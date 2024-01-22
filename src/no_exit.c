#include "fonction.h"
#include <unistd.h>

int no_exit()
{
    write(1, "No Solution to maze.\n", 21);
    return 1;
}
