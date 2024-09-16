#include <arpa/inet.h>
#include <errno.h>
#include <stdio.h>
#include <sys/socket.h>
#include <unistd.h>
#include <string.h>

#include <stdlib.h>
#include "index.c"
#include "about.c"
#include "ml/router.c"
#include "notes.c"

int notes_router(int fd, char* buffer, char* path) {
    printf("routing:\n");
    printf("%s", buffer);

    if (is_path(path, "/notes/ml"))
    {
        return notes_ml_router(fd, buffer, path);
    };


    if (is_path(path, "/notes"))
    {
        return write(fd, get_notes_index(), strlen(get_notes_index()));
    };

    return write(fd, get_missing_page(), strlen(get_missing_page()));
}


int route(int fd, char* buffer) {
	printf("routing:\n");
	printf("%s", buffer);
        char *method, *path;

        method = strtok(buffer, " ");
        path = strtok(NULL, " ");

        printf("method: %s\n", method);
        printf("path: %s\n", path);

        if (strcmp(method,"GET") != 0)
        {
            return write(fd, get_method_not_allowed(), strlen(get_method_not_allowed()));
        }

        if (strcmp(path, "/") == 0)
        {
            return write(fd, get_index_html(), strlen(get_index_html()));
        }

        if (is_path(path, "/about"))
        {
            return write(fd, get_about_html(), strlen(get_about_html()));
        }
        if (is_path(path, "/notes"))
        {
            return notes_router(fd, buffer, path);
        }

        return write(fd, get_missing_page(), strlen(get_missing_page()));
}
