#include "fonction.h"

static int north(char *maze, enum facing dir, int pos, struct map map)
{
    if (maze[pos - 1] == '#' || maze[pos - 1] == '\n') {
        dir = EAST;
        return shift(maze, dir, pos, map);
    } else {
        dir = WEST;
        maze[pos] = ' ';
        pos = pos - 1;
        return shift(maze, dir, pos, map);
    }
}

static int east(char *maze, enum facing dir, int pos, struct map map)
{
    if (maze[pos - map.length - 1] == '#'
        || maze[pos - map.length - 1] == '\n') {
        dir = SOUTH;
        return shift(maze, dir, pos, map);
    } else {
        dir = NORTH;
        maze[pos] = ' ';
        pos = pos - map.length - 1;
        return shift(maze, dir, pos, map);
    }
}

static int south(char *maze, enum facing dir, int pos, struct map map)
{
    if (maze[pos + 1] == '#' || maze[pos + 1] == '\n') {
        dir = WEST;
        return shift(maze, dir, pos, map);
    } else {
        dir = EAST;
        maze[pos] = ' ';
        pos = pos + 1;
        return shift(maze, dir, pos, map);
    }
}

static int west(char *maze, enum facing dir, int pos, struct map map)
{
    if (maze[pos + map.length + 1] == '#' ||
        maze[pos + map.length + 1] == '\n') {
        dir = NORTH;
        return shift(maze, dir, pos, map);
    } else {
        dir = SOUTH;
        maze[pos] = ' ';
        pos = pos + map.length + 1;
        return shift(maze, dir, pos, map);
    }
}

int shift(char *maze, enum facing dir, int pos, struct map map)
{
    if (pos >= 0 && pos < map.length * map.height) {
        if (maze[pos] == 'G')
            return 0;
        if (dir == NORTH)
            return north(maze, dir, pos, map);
        else if (dir == EAST)
            return east(maze, dir, pos, map);
        else if (dir == SOUTH)
            return south(maze, dir, pos, map);
        else
            return west(maze, dir, pos, map);
    }
    return -1;
}
