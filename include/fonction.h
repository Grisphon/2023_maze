/*
 * E89 Pedagogical & Technical Lab
 * project:     maze
 * created on:  2024-01-16 - 11:50 +0100
 * 1st author:  ilan.trigueiro-legrand - ilan.trigueiro-legrand
 * description: include fonction
 */

#ifndef FONCTION_
#define FONCTION_

enum facing {
    NORTH,
    EAST,
    SOUTH,
    WEST,
};

struct map {
    int length;
    int height;
};

int shift(char *maze, enum facing dir, int pos, int length, int height);
int start_finder(const char *str);
int print_base10(int nb);
struct map map_size(char *buffer);
char *reader(int fd, char **av);
unsigned int stu_strlen(const char *str);

#endif
