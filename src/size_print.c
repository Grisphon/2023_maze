#include <unistd.h>
#include "fonction.h"

void size_print(struct map map)
{
    write(1, "Width: ", 7);
    print_base10(map.length);
    write(1, "Height: ", 8);
    print_base10(map.height);
    write(1, "\n", 1);
}
