#include "../include/push_swap.h"

int main(int argc, char **argv)
{
    pile *pile_a;
    pile *pile_b;
    int i;
    
    if (argc != 1)
        return (0);
    pile_a = ft_lstcreate_a();
    pile_b = ft_lstcreate_b();
    i = 0;
    ft_putlst(pile_a);
    ft_putstr("Finished printing pile_a!\n", 1);
    ft_putlst(pile_b);
    ft_putstr("Finished printing pile_b!\n", 1);
    ft_lstswap(&pile_a);
    ft_putstr("SWAPED!\n", 1);
    ft_putlst(pile_a);
    do_pa(&pile_a, &pile_b);
    ft_putlst(pile_a);
    ft_putstr("Finished printing pile_a!\n", 1);
    ft_putlst(pile_b);
    ft_putstr("Finished printing pile_b!\n", 1);
    ft_putstr("Rotating pile_b\n", 1);
    while (i++ < 5)
        do_rb(&pile_b);
    ft_putlst(pile_b);
    i = 0;
    while (i++ < 5)
        do_rra(&pile_a);
    ft_putlst(pile_a);
    ft_lstclear(&pile_a);
    ft_lstclear(&pile_b);
    return (0);
    // if (argc < 2)
    //     return (0);
    // if (ft_valid_args(argc, argv) == 0)
    // {
    //     ft_putstr("Error\n", 2);
    //     return (0);
    // }
    // printf("OK!\n");
    // return (0);
}