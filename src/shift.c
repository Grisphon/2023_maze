#include "fonction.h"

static int north(char *maze, enum facing dir, int pos, int length, int height)
{
    if (maze[pos - 1] == '#') {
        dir = EAST;
        return shift(maze, dir, pos, length, height);
    } else {
        dir = WEST;
        maze[pos] = ' ';
        pos = pos - 1;
        return shift(maze, dir, pos, length, height);
    }
}

static int east(char *maze, enum facing dir, int pos, int length, int height)
{
    if (maze[pos - length - 1] == '#') {
        dir = SOUTH;
        return shift(maze, dir, pos, length, height);
    } else {
        dir = NORTH;
        maze[pos] = ' ';
        pos = pos - length - 1;
        return shift(maze, dir, pos, length, height);
    }
}

static int south(char *maze, enum facing dir, int pos, int length, int height)
{
    if (maze[pos + 1] == '#') {
        dir = WEST;
        return shift(maze, dir, pos, length, height);
    } else {
        dir = EAST;
        maze[pos] = ' ';
        pos = pos + 1;
        return shift(maze, dir, pos, length, height);
    }
}

static int west(char *maze, enum facing dir, int pos, int length, int height)
{
    if (maze[pos + length + 1] == '#') {
        dir = NORTH;
        return shift(maze, dir, pos, length, height);
    } else {
        dir = SOUTH;
        maze[pos] = ' ';
        pos = pos + length + 1;
        return shift(maze, dir, pos, length, height);
    }
}

int shift(char *maze, enum facing dir, int pos, int length, int height)
{
    if (pos >= 0 && pos < length * height) {
        if (maze[pos] == 'G')
            return 0;
        if (dir == NORTH)
            return north(maze, dir, pos, length, height);
        else if (dir == EAST)
            return east(maze, dir, pos, length, height);
        else if (dir == SOUTH)
            return south(maze, dir, pos, length, height);
        else
            return west(maze, dir, pos, length, height);
    }
    return -1;
}
