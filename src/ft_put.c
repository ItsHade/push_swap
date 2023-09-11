#include "../include/push_swap.h"

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
    unsigned int num;

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