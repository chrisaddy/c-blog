#include <stdio.h>

#include "ml.c"
#include "../errors.c"
#include "../utils.c"

int notes_ml_router(int fd, char* buffer, char* path) {
    printf("routing:\n");
    printf("%s", buffer);

    if (is_path(path, "/notes/ml"))
    {
        return write(fd, get_ml_index(), strlen(get_ml_index()));
    };

    return write(fd, get_missing_page(), strlen(get_missing_page()));
}
