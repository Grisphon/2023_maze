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
#include "../include/fonction.h"

unsigned int stu_strlen(const char *str)
{
    int count;

    count = 0;
    while (str[count] != '\0') {
        count = count + 1;
    }
    return count;
}

void compteur(char *buffer)
{
    int hauteur;
    int count;

    hauteur = 0;
    count = 0;
    while (buffer[count] != '\0') {
        if (buffer[count] == '\n') {
            hauteur += 1;
        }
        count += 1;
    }
    write(1, "Width: ", 7);
    print_base10(count / (hauteur + 1));
    write(1, "Height: ", 8);
    print_base10(hauteur);
    write(1, "\n", 1);
}

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
    write(1, provisoir, total);
    free(buffer);
    return provisoir;
}

int main(int ac, char **av)
{
    int fd;
    char *buffer;

    if (ac < 1 || ac > 2) {
        return 1;
    }
    fd = open(av[1], O_RDONLY);
    buffer = reader(fd, av);
    compteur(buffer);
    free(buffer);
    close(fd);
}
