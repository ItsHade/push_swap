#include "../include/push_swap.h"

int ft_strlen(char *s)
{
    size_t i;

    i = 0;
    while (s && s[i])
        i++;
    return (i);
}

void ft_freesplit(char **strs)
{
    int i;

    i = 0;
    while (strs[i][0] != 0)
    {
        free(strs[i]);
        i++;
    }
    free(strs[i]);
    free(strs);
}

// this atoi returns 0 if a in
long ft_atol(char *s)
{
    size_t i;
    int sign;
    long int res;

    i = 0;
    sign = 1;
    res = 0;
    if (s[i] == '-')
    {
        sign *= -1;
        i++;
    }
    else if (s[i] == '+')
        i++;
    if (s[i] == 0)
        return (-1); 
    while (s[i])
    {
        if (s[i] < '0' || s[i] > '9')
            return (-1);
        res = res * 10 + (s[i] - 48);
        i++;
    }
    res = res * sign;
    return (res);
}