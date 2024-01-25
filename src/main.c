#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include "fonction.h"

static char *stu_strdup(char *arr)
{
    int count;
    char *str_a;

    count = 0;
    str_a = malloc((stu_strlen(arr) + 1) * sizeof (char));
    if (!str_a)
        return NULL;
    while (arr[count] != '\0') {
        str_a[count] = arr[count];
        count = count + 1;
    }
    str_a[count] = '\0';
    return str_a;
}


static int is_valid_boucle(char *buffer, struct map map)
{
    if (is_valid(buffer, map) == 1) {
        free(buffer);
        write(1, "Invalid maze\n", 13);
        return 1;
    }
    return 0;
}

int freeable(int retu, char *buffspread, char *buffer)
{
    free(buffspread);
    free(buffer);
    if (retu == -1)
        write(1, "stop processing : timed out\n", 28);
    return retu;
}

static int shift_spread(char *buffer, int pos, struct map map)
{
    char *buffspread;
    time_t timestamp;

    timestamp = time(NULL);
    buffspread = stu_strdup(buffer);
    buffer[map.start] = '.';
    buffspread[map.start] = '.';
    if (shift(buffer, pos, map, timestamp) == 0) {
        buffer[map.start] = 'S';
        write(1, buffer, stu_strlen(buffer));
    } else if (shift(buffer, pos, map, timestamp == 1))
        return freeable(1, buffspread, buffer);
    else
        return freeable(-1, buffspread, buffer);
    timestamp = time(NULL);
    if (spread(buffspread, pos, map, timestamp) == 0) {
        buffspread[map.start] = 'S';
        write(1, "\n", 1);
        write(1, buffspread, stu_strlen(buffspread));
    } else if (spread(buffspread, pos, map, timestamp) == 1)
        return freeable(1, buffspread, buffer);
    else
        return freeable(-1, buffspread, buffer);
    return freeable(0, buffspread, buffer);
}

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
    map.how_far = 0;
    if (is_valid_boucle(buffer, map) == 1)
        return 1;
    else
        size_print(map);
    map.dir = side(buffer, pos, map);
    if (shift_spread(buffer, pos, map) == 1)
        return 1;
    close(fd);
}
