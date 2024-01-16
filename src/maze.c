/*
 * E89 Pedagogical & Technical Lab
 * project:     maze
 * created on:  2024-01-16 - 11:12 +0100
 * 1st author:  ilan.trigueiro-legrand - ilan.trigueiro-legrand
 * description: read map
 */

#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <fcntl.h>
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

char *stu_strcpy(char *dest, const char *src)
{
    int count;

    count = 0;
    while (src[count] != '\0') {
        dest[count] = src[count];
        count = count + 1;
    }
    dest[count] = '\0';
    return (dest);
}

char *stu_strcat(char *str1, char *str2)
{
    int count;
    int i;

    i = 0;
    count = stu_strlen(str1);
    while (str2[i] != '\0') {
        str1[count] = str2[i];
        count = count + 1;
        i = i + 1;
    }
    str1[count] = '\0';
    return (str1);
}

char *strdupcat(char *str1, char *str2)
{
    int len;
    char *alloc;

    len = stu_strlen(str1) + stu_strlen(str2);
    alloc = malloc(sizeof (char) * (len + 1));
    if (!alloc) {
        return NULL;
    }
    stu_strcpy(alloc, str1);
    return stu_strcat(alloc, str2);
}

char *reading(int size_read, char *bufferread, char *accu, int fd)
{
    char *tofree;

    while (size_read != 0) {
        size_read = read(fd, bufferread, 99);
        if (size_read == -1) {
            free(bufferread);
            return accu;
        }
        bufferread[size_read] = '\0';
        tofree = accu;
        accu = strdupcat(accu, bufferread);
        free(tofree);
        if (!accu){
            free(bufferread);
            return NULL;
        }
    }
    free(bufferread);
    return accu;
}

char *reader(int fd)
{
    int size_read;
    char *accu;
    char *bufferread;

    bufferread = malloc(sizeof (char) * 100);
    if (!bufferread) {
        return NULL;
    }
    size_read = read(fd, bufferread, 99);
    if (size_read == -1) {
        free(bufferread);
        return NULL;
    }
    bufferread[size_read] = '\0';
    accu = strdupcat("", bufferread);
    if (!accu) {
        free(bufferread);
        return NULL;
    }
    return reading(size_read, bufferread, accu, fd);
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
}

int main(int ac, char **av)
{
    int fd;
    char *buffer;

    if (ac < 1 || ac > 2) {
        return 1;
    }
    fd = open(av[1], O_RDONLY);
    buffer = reader(fd);
    write(1, buffer, stu_strlen(buffer));
    compteur(buffer);
    free(buffer);
    close(fd);
}
