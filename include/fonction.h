/*
 * E89 Pedagogical & Technical Lab
 * project:     maze
 * created on:  2024-01-16 - 11:50 +0100
 * 1st author:  ilan.trigueiro-legrand - ilan.trigueiro-legrand
 * description: include fonction
 */

#ifndef FONCTION_
#define FONCTION_

#include <time.h>

enum facing {
    NORTH,
    EAST,
    SOUTH,
    WEST,
};

struct map {
    int length;
    int height;
    int start;
    int exit;
    int how_far;
    enum facing dir;
};

unsigned int coords_to_idx(unsigned int x, unsigned int y, unsigned int width);
int freeable(int retu, char *buffspread, char *buffer);
int check(char* maze);
void size_print(struct map map);
int is_valid(char *maze, struct map map);
int no_exit();
enum facing side(char *maze, int pos, struct map map);
int shift(char *maze, int pos, struct map map, time_t timestamp);
int start_finder(const char *str);
int print_base10(int nb);
struct map map_size(char *buffer, int start);
char *reader(int fd, char **av);
unsigned int stu_strlen(const char *str);
int spread(char *maze, int pos, struct map map, time_t timestamp);

#endif
