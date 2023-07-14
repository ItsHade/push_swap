#include "push_swap.h"

int ft_strlen(char *s)
{
    size_t i;

    i = 0;
    while (s && s[i])
        i++;
    return (i);
}

// peut etre remplacer par ft_printf par la suite
void ft_putstr(char *str, int err)
{
    size_t i;

    i = 0;
    while (str && str[i])
    {
        write(err, &str[i], 1);
        i++;
    }
}

long ft_atoi(char *s)
{
    size_t i;
    long res;
    int sign;

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
    while (s[i])
    {
        res = res * 10 + (s[i] - 48);
        i++;
    }
    return (res * sign);
}