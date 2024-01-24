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

    if (ac < 1 || ac > 2)
        return 1;
    fd = open(av[1], O_RDONLY);
    buffer = reader(fd, av);
    pos = start_finder(buffer);
    map = map_size(buffer, pos);
    if (is_valid(buffer, map) == 1) {
        free(buffer);
        write(1, "Invalid maze\n", 13);
        return 1;
    } else
        size_print(map);
    if (shift(buffer, side(buffer, pos, map), pos, map) == 1) {
        free(buffer);
        return 1;
    }
    write(1, buffer, stu_strlen(buffer));
    free(buffer);
    close(fd);
}
