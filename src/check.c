#include "fonction.h"

int check(char* maze)
{
    int count;

    count = 0;
    while (count < (int) stu_strlen(maze)) {
        if (maze[count] == '.')
            return 1;
        count = count + 1;
    }
    return 0;
}
