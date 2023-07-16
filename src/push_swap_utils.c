#include "../include/push_swap.h"

int ft_strlen(char *s)
{
    size_t i;

    i = 0;
    while (s && s[i])
        i++;
    return (i);
}

void ft_putchar(char c, int fd)
{
    write(fd, &c, 1);
}

// peut etre remplacer par ft_printf par la suite
void ft_putstr(char *str, int fd)
{
    size_t i;

    i = 0;
    while (str && str[i])
    {
        write(fd, &str[i], 1);
        i++;
    }
}

void ft_putnbr(int nb)
{
    long num;

    if (nb < 0)
    {
        num = -nb;
        ft_putchar('-', 1);
    }
    else
        num = nb;
    if (num <= 9)
        ft_putchar(num + 48, 1);
    else
    {
        ft_putnbr(num / 10);
        ft_putchar(num % 10 + 48, 1);
    }

}


// this atoi returns 0 if a in
int ft_atoi(char *s, int *res)
{
    size_t i;
    int sign;

    i = 0;
    sign = 1;
    *res = 0;
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
        *res = *res * 10 + (s[i] - 48);
        i++;
    }
    *res = *res * sign;
    return (0);
}