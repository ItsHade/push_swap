#include "push_swap.h"

int main(int ac, char **av)
{
    if (ac < 2)
        return (0);
    if (ft_valid_args(ac, av) == 0)
    {
        ft_putstr("Error\n", 2);
        return (0);
    }
    printf("OK!\n");
    return (0);
}