#include <unistd.h>
#include "fonction.h"

struct map map_size(char *buffer, int start)
{
    int hauteur;
    int count;
    struct map map;

    hauteur = 0;
    count = 0;
    while (buffer[count] != '\0') {
        if (buffer[count] == '\n') {
            hauteur += 1;
        }
        count += 1;
    }
    map.height = hauteur;
    map.length = (count - hauteur) / hauteur;
    map.start = start;
    map.exit = 3;
    return map;
}
