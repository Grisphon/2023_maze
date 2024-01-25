#include "fonction.h"
#include <time.h>
#include <stddef.h>

static int north(char *maze, int pos, struct map map, time_t timestamp)
{
    if (maze[pos - 1] == '#' || maze[pos - 1] == '\n') {
        map.dir = EAST;
        return shift(maze, pos, map, timestamp);
    } else {
        map.dir = WEST;
        maze[pos] = ' ';
        pos = pos - 1;
        return shift(maze, pos, map, timestamp);
    }
}

static int east(char *maze, int pos, struct map map, time_t timestamp)
{
    if (maze[pos - map.length - 1] == '#'
        || maze[pos - map.length - 1] == '\n') {
        map.dir = SOUTH;
        return shift(maze, pos, map, timestamp);
    } else {
        map.dir = NORTH;
        maze[pos] = ' ';
        pos = pos - map.length - 1;
        return shift(maze, pos, map, timestamp);
    }
}

static int south(char *maze, int pos, struct map map, time_t timestamp)
{
    if (maze[pos + 1] == '#' || maze[pos + 1] == '\n') {
        map.dir = WEST;
        return shift(maze, pos, map, timestamp);
    } else {
        map.dir = EAST;
        maze[pos] = ' ';
        pos = pos + 1;
        return shift(maze, pos, map, timestamp);
    }
}

static int west(char *maze, int pos, struct map map, time_t timestamp)
{
    if (maze[pos + map.length + 1] == '#' ||
        maze[pos + map.length + 1] == '\n') {
        map.dir = NORTH;
        return shift(maze, pos, map, timestamp);
    } else {
        map.dir = SOUTH;
        maze[pos] = ' ';
        pos = pos + map.length + 1;
        return shift(maze, pos, map, timestamp);
    }
}

int shift(char *maze, int pos, struct map map, time_t timestamp)
{
    if ((int) difftime(time(NULL), timestamp) > 30)
        return -1;
    if (pos >= 0 && pos < (map.length + 1) * map.height ) {
        if (pos == map.start)
            map.exit = map.exit - 1;
        if (map.exit == 0)
            return no_exit();
        if (maze[pos] == 'G')
            return 0;
        if (map.dir == NORTH)
            return north(maze, pos, map, timestamp);
        else if (map.dir == EAST)
            return east(maze, pos, map, timestamp);
        else if (map.dir == SOUTH)
            return south(maze, pos, map, timestamp);
        else
            return west(maze, pos, map, timestamp);
    }
    return -1;
}

