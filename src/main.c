#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include "fonction.h"

int main(int ac, char **av)
{
    int fd;
    char *buffer;
    struct map map;
    int pos;

    if (ac < 1 || ac > 2) {
        return 1;
    }
    fd = open(av[1], O_RDONLY);
    buffer = reader(fd, av);
    pos = start_finder(buffer);
    map = map_size(buffer);
    shift(buffer, side(buffer, pos, map), pos, map);
    write(1, buffer, stu_strlen(buffer));
    free(buffer);
    close(fd);
}
