#include "fonction.h"

static int north(char *maze, int pos, struct map map)
{
    if (maze[pos - 1] == '#' || maze[pos - 1] == '\n' || maze[pos - 1] == 'S'
        || maze[pos - 1] == 'G') {
        map.dir = EAST;
        return spread(maze, pos, map);
    } else {
        map.dir = WEST;
        if (maze[pos] == '.') {
            maze[pos] = '0' + map.how_far % 10;
        } else {
            map.how_far = maze[pos] - 0;
            map.how_far = map.how_far + 2;
        }
        map.how_far = map.how_far + 1;
        pos = pos - 1;
        return spread(maze, pos, map);
    }
}

static int east(char *maze, int pos, struct map map)
{
    if (maze[pos - map.length - 1] == '#'
        || maze[pos - map.length - 1] == '\n'
        || maze[pos - map.length - 1] == 'S'
        || maze[pos - map.length - 1] == 'G') {
        map.dir = SOUTH;
        return spread(maze, pos, map);
    } else {
        map.dir = NORTH;
        if (maze[pos] == '.') {
            maze[pos] = '0' + map.how_far % 10;
        } else {
            map.how_far = maze[pos] - 0;
            map.how_far = map.how_far + 2;
        }
        map.how_far = map.how_far + 1;
        pos = pos - map.length - 1;
        return spread(maze, pos, map);
    }
}

static int south(char *maze, int pos, struct map map)
{
    if (maze[pos + 1] == '#' || maze[pos + 1] == '\n' || maze[pos + 1] == 'S'
        || maze[pos + 1] == 'G') {
        map.dir = WEST;
        return spread(maze, pos, map);
    } else {
        map.dir = EAST;
        if (maze[pos] == '.') {
            maze[pos] = '0' + map.how_far % 10;
        } else {
            map.how_far = maze[pos] - 0;
            map.how_far = map.how_far + 2;
        }
        map.how_far = map.how_far + 1;
        pos = pos + 1;
        return spread(maze, pos, map);
    }
}

static int west(char *maze, int pos, struct map map)
{
    if (maze[pos + map.length + 1] == '#'
        || maze[pos + map.length + 1] == '\n'
        || maze[pos + map.length + 1] == 'S'
        || maze[pos + map.length + 1] == 'G') {
        map.dir = NORTH;
        return spread(maze, pos, map);
    } else {
        map.dir = SOUTH;
        if (maze[pos] == '.') {
            maze[pos] = '0' + map.how_far % 10;
        } else {
            map.how_far = maze[pos] - 0;
            map.how_far = map.how_far + 2;
        }
        map.how_far = map.how_far + 1;
        pos = pos + map.length + 1;
        return spread(maze, pos, map);
    }
}

int spread(char *maze, int pos, struct map map)
{
    if (pos >= 0 && pos < (map.length + 1) * map.height ) {
        if (pos == map.start)
            map.exit = map.exit - 1;
        if (map.exit == 0)
            return no_exit();
        if (check(maze) == 0)
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
