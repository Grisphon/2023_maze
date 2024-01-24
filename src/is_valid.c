#include "fonction.h"

int is_valid(char *maze, struct map map)
{
    unsigned int count;

    count = 0;
    while (count < stu_strlen(maze)) {
        if (maze[count] != '\n' && maze[count] != 'S' && maze[count] != 'G'
            && maze[count] != '#' && maze[count] != '.')
            return 1;
        count += 1;
    }
    if (map.height * (map.length + 1) != (int)stu_strlen(maze)) {
        return 1;
    }
    return 0;
}
