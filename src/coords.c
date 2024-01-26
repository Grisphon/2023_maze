#include "fonction.h"

unsigned int coords_to_idx(unsigned int x,
			   unsigned int y,
			   unsigned int width)
{
    return (((width + 1) * y) + x);
}
