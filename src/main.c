#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include "fonction.h"

int main(int ac, char **av)
{
    int fd;
    char *buffer;
    struct map map;

    if (ac < 1 || ac > 2) {
        return 1;
    }
    fd = open(av[1], O_RDONLY);
    buffer = reader(fd, av);
    map = map_size(buffer);
    shift(buffer, SOUTH, start_finder(buffer) , map.length, map.height);
    write(1, buffer, stu_strlen(buffer));
    free(buffer);
    close(fd);
}
