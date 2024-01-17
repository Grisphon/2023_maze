int start_finder(const char *str)
{
    int count;
    int back;

    back = 0;
    count = 0;
    while (str[count] != '\0') {
        if (str[count] == '\n')
            back += 1;
        if (str[count] == 'S')
            return count - back;
        else
            count = count + 1;
    }
    return -1;
}
