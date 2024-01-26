#include <stdlib.h>
#include <unistd.h>

int freeable(int retu, char *buffspread, char *buffer)
{
    free(buffspread);
    free(buffer);
    if (retu == -1)
        write(1, "stop processing : timed out\n", 28);
    return retu;
}
