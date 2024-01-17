int stu_strchr(const char *str, char subject)
{
    int count;
    int back;

    back = 0;
    count = 0;
    while (str[count] != '\0') {
        if (str[count] == '\n')
            back += 1;
        if (str[count] == subject)
            return count + 1 - back;
        else
            count = count + 1;
    }
    return -1;
}
