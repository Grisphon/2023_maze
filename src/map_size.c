#include <unistd.h>
#include "fonction.h"

void map_size(char *buffer)
{
    int hauteur;
    int count;

    hauteur = 0;
    count = 0;
    while (buffer[count] != '\0') {
        if (buffer[count] == '\n') {
            hauteur += 1;
        }
        count += 1;
    }
    write(1, "Width: ", 7);
    print_base10(count / (hauteur + 1));
    write(1, "Height: ", 8);
    print_base10(hauteur);
    write(1, "\n", 1);
}
