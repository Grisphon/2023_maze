/*
 * E89 Pedagogical & Technical Lab
 * project:     maze
 * created on:  2024-01-16 - 13:54 +0100
 * 1st author:  ilan.trigueiro-legrand - ilan.trigueiro-legrand
 * description: map read
 */

#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include "fonction.h"

char *reader(int fd, char **av)
{
    char *buffer;
    int size_read;
    char *provisoir;
    int total;

    buffer = malloc(sizeof (char) * 100);
    total = 0;
    if (!buffer) {
        return NULL;
    }
    size_read = read(fd, buffer, 99);
    while (size_read > 0) {
        total += size_read;
        size_read = read(fd, buffer, 99);
    }
    close(fd);
    fd = open(av[1], O_RDONLY);
    provisoir = malloc(sizeof (char) * (total + 1));
    read(fd, provisoir, total);
    provisoir[total] = '\0';
    //  write(1, provisoir, total);
    free(buffer);
    return provisoir;
}
