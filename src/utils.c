#include <arpa/inet.h>
#include <errno.h>
#include <sys/socket.h>
#include <unistd.h>
#include <string.h>

int is_path(char* path, char* path_to_check) {
    size_t len = strlen(path_to_check);
    return (strncmp(path, path_to_check, len) == 0) &&
           (path[len] == '\0' || path[len] == '/');
}


