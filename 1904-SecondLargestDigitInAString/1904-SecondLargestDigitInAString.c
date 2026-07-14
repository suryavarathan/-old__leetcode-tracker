// Last updated: 7/14/2026, 3:27:13 PM
int secondHighest(char* s)
{
    int i;
    int max;
    int second;

    i = 0;
    max = -1;
    second = -1;
    while (s[i])
    {
        if (s[i] >= '0' && s[i] <= '9')
        {
            if ((s[i] - '0') > max)
            {
                second = max;
                max = s[i] - '0';
            }
            else if ((s[i] - '0') > second && (s[i] - '0') < max)
                second = s[i] - '0';
        }
        i++;
    }
    if (second == max || second == -1)
        return (-1);
    return (second);
}