/*
 * E89 Pedagogical & Technical Lab
 * project:     maze
 * created on:  2024-01-16 - 11:48 +0100
 * 1st author:  ilan.trigueiro-legrand - ilan.trigueiro-legrand
 * description: print base 10
 */

#include <unistd.h>

static void tc_putchar(char c)
{
    write(1, &c, 1);
}

static int get_digit(int nb, int index)
{
    int result;

    if (nb < 0) {
        nb = nb * -1;
    }
    while (index > 0) {
        nb = nb / 10;
        index = index - 1;
    }
    result = nb % 10;
    return result;
}

static int nb_len(int nb)
{
    int len;

    len = 0;
    if (nb == 0) {
        return 1;
    }
    if (nb < 0) {
        nb = nb * -1;
    }
    while (nb > 0) {
        nb = nb / 10;
        len = len + 1;
    }
    return len;
}

int print_base10(int nb)
{
    int len;
    int count;

    len = nb_len(nb);
    count = 0;
    if (nb < 0) {
        count = count + 1;
        tc_putchar('-');
    }
    while (len > 0) {
        tc_putchar(get_digit(nb, len - 1) + '0');
        len = len - 1;
        count = count + 1;
    }
    tc_putchar(' ');
    return count;
}
