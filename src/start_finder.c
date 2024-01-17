int start_finder(const char *str)
{
    int count;

    count = 0;
    while (str[count] != '\0') {
        if (str[count] == 'S')
            return count;
        else
            count = count + 1;
    }
    return -1;
}
