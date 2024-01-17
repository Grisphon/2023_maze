#include "fonction.h"

enum facing side(char *maze, int pos, struct map map)
{
    if (pos > 0 && pos < map.length)
        return SOUTH;
    if (pos < (map.length + 1) * map.height && pos > map.length * map.height)
        return NORTH;
    if (maze[pos + 1 + pos / map.length] == '\n')
        return WEST;
    return EAST;
}
