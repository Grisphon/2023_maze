#include "fonction.h"

static int north(char *maze, enum facing dir, int pos, struct map map)
{
    if (maze[pos - 1] == '#' || maze[pos - 1] == '\n') {
        dir = EAST;
        return spread(maze, dir, pos, map);
    } else {
        dir = WEST;
        if (maze[pos] == '.') {
            maze[pos] = '0' + map.how_far % 10;
        } else {
            map.how_far = maze[pos] - 0;
            map.how_far = map.how_far + 2;
        }
        map.how_far = map.how_far + 1;
        pos = pos - 1;
        return spread(maze, dir, pos, map);
    }
}

static int east(char *maze, enum facing dir, int pos, struct map map)
{
    if (maze[pos - map.length - 1] == '#'
        || maze[pos - map.length - 1] == '\n') {
        dir = SOUTH;
        return spread(maze, dir, pos, map);
    } else {
        dir = NORTH;
        if (maze[pos] == '.') {
            maze[pos] = '0' + map.how_far % 10;
        } else {
            map.how_far = maze[pos] - 0;
            map.how_far = map.how_far + 2;
        }
        map.how_far = map.how_far + 1;
        pos = pos - map.length - 1;
        return spread(maze, dir, pos, map);
    }
}

static int south(char *maze, enum facing dir, int pos, struct map map)
{
    if (maze[pos + 1] == '#' || maze[pos + 1] == '\n') {
        dir = WEST;
        return spread(maze, dir, pos, map);
    } else {
        dir = EAST;
        if (maze[pos] == '.') {
            maze[pos] = '0' + map.how_far % 10;
        } else {
            map.how_far = maze[pos] - 0;
            map.how_far = map.how_far + 2;
        }
        map.how_far = map.how_far + 1;
        pos = pos + 1;
        return spread(maze, dir, pos, map);
    }
}

static int west(char *maze, enum facing dir, int pos, struct map map)
{
    if (maze[pos + map.length + 1] == '#' ||
        maze[pos + map.length + 1] == '\n') {
        dir = NORTH;
        return spread(maze, dir, pos, map);
    } else {
        dir = SOUTH;
        if (maze[pos] == '.') {
            maze[pos] = '0' + map.how_far % 10;
        } else {
            map.how_far = maze[pos] - 0;
            map.how_far = map.how_far + 2;
        }
        map.how_far = map.how_far + 1;
        pos = pos + map.length + 1;
        return spread(maze, dir, pos, map);
    }
}

int spread(char *maze, enum facing dir, int pos, struct map map)
{
    if (pos >= 0 && pos < (map.length + 1) * map.height ) {
        if (pos == map.start)
            map.exit = map.exit - 1;
        if (map.exit == 0)
            return no_exit();
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
