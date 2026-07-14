// Last updated: 7/14/2026, 3:24:31 PM
int my_strlen(char *str)
{
    int count;

    count = 0;
    while(str[count])
        count++;
    return (count);
}

char* largestOddNumber(char* num) {
    int     index;
    char    *total;
    int     i;

    i = 0;
    index = my_strlen(num) - 1;
    while (index >=0 && !(num[index] & 1))
        index--;
    total = malloc(index + 2);
    if (!total)
        return (NULL);
    while(i <= index)
    {
        total[i] = num[i];
        i++;
    }
    total[i] = '\0';
    return (total);
}