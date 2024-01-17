unsigned int stu_strlen(const char *str)
{
    int count;

    count = 0;
    while (str[count] != '\0') {
        count = count + 1;
    }
    return count;
}
