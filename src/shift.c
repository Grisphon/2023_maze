#include "fonction.h"

static int north(char *maze, int pos, struct map map)
{
    if (maze[pos - 1] == '#' || maze[pos - 1] == '\n') {
        map.dir = EAST;
        return shift(maze, pos, map);
    } else {
        map.dir = WEST;
        maze[pos] = ' ';
        pos = pos - 1;
        return shift(maze, pos, map);
    }
}

static int east(char *maze, int pos, struct map map)
{
    if (maze[pos - map.length - 1] == '#'
        || maze[pos - map.length - 1] == '\n') {
        map.dir = SOUTH;
        return shift(maze, pos, map);
    } else {
        map.dir = NORTH;
        maze[pos] = ' ';
        pos = pos - map.length - 1;
        return shift(maze, pos, map);
    }
}

static int south(char *maze, int pos, struct map map)
{
    if (maze[pos + 1] == '#' || maze[pos + 1] == '\n') {
        map.dir = WEST;
        return shift(maze, pos, map);
    } else {
        map.dir = EAST;
        maze[pos] = ' ';
        pos = pos + 1;
        return shift(maze, pos, map);
    }
}

static int west(char *maze, int pos, struct map map)
{
    if (maze[pos + map.length + 1] == '#' ||
        maze[pos + map.length + 1] == '\n') {
        map.dir = NORTH;
        return shift(maze, pos, map);
    } else {
        map.dir = SOUTH;
        maze[pos] = ' ';
        pos = pos + map.length + 1;
        return shift(maze, pos, map);
    }
}

int shift(char *maze, int pos, struct map map)
{
    if (pos >= 0 && pos < (map.length + 1) * map.height ) {
        if (pos == map.start)
            map.exit = map.exit - 1;
        if (map.exit == 0)
            return no_exit();
        if (maze[pos] == 'G')
            return 0;
        if (map.dir == NORTH)
            return north(maze, pos, map);
        else if (map.dir == EAST)
            return east(maze, pos, map);
        else if (map.dir == SOUTH)
            return south(maze, pos, map);
        else
            return west(maze, pos, map);
    }
    return -1;
}

