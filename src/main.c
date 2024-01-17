#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include "fonction.h"

int main(int ac, char **av)
{
    int fd;
    char *buffer;

    if (ac < 1 || ac > 2) {
        return 1;
    }
    fd = open(av[1], O_RDONLY);
    buffer = reader(fd, av);
    map_size(buffer);
    free(buffer);
    close(fd);
}
