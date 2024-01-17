#include "fonction.h"

int shift(char *maze, enum facing dir, int pos, int length, int height)
{
    if (pos >= 0 && pos < length * height) {
        if (maze[pos] == 'G')
            return 0;
        if (dir == NORTH) {
            if (maze[pos - 1] == '#') {
                dir = EAST;
                return shift(maze, dir, pos, length, height);
            } else {
                dir = WEST;
                maze[pos] = ' ';
                pos = pos - 1;
                return shift(maze, dir, pos, length, height);
            }
        } else if (dir == EAST) {
            if (maze[pos - length - 1] == '#') {
                dir = SOUTH;
                return shift(maze, dir, pos, length, height);
            } else {
                dir = NORTH;
                maze[pos] = ' ';
                pos = pos - length - 1;
                return shift(maze, dir, pos, length, height);
            }
        } else if (dir == SOUTH) {
            if (maze[pos + 1] == '#') {
                dir = WEST;
                return shift(maze, dir, pos, length, height);
            } else {
                dir = EAST;
                maze[pos] = ' ';
                pos = pos + 1;
                return shift(maze, dir, pos, length, height);
            }
        } else {
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
    }
    return -1;
}
