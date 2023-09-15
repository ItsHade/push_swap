#include "../include/push_swap.h"

int g_count = 0;

//Main used to individually test the different rule fonctions

// int main(int argc, char **argv)
// {
//     t_pile *pile_a;
//     t_pile *pile_b;
//     int i;
    
//     if (argc < 3)
//         return (0);
//     pile_a = ft_lstcreate_a();
//     pile_b = ft_lstcreate_b();
//     i = 0;
//     ft_putlst(pile_a);
//     ft_putstr("Finished printing pile_a!\n", 1);
//     ft_putlst(pile_b);
//     ft_putstr("Finished printing pile_b!\n", 1);
//     ft_lstswap(&pile_a);
//     ft_putstr("SWAPED!\n", 1);
//     ft_putlst(pile_a);
//     do_pa(&pile_a, &pile_b);
//     ft_putlst(pile_a);
//     ft_putstr("Finished printing pile_a!\n", 1);
//     ft_putlst(pile_b);
//     ft_putstr("Finished printing pile_b!\n", 1);
//     ft_putstr("Rotating pile_b\n", 1);
//     while (i++ < 5)
//         do_rb(&pile_b);
//     ft_putlst(pile_b);
//     i = 0;
//     while (i++ < 5)
//         do_rra(&pile_a);
//     ft_putlst(pile_a);
//     ft_lstclear(&pile_a);
//     ft_lstclear(&pile_b);
//     return (0);
// }

int ft_is_sorted(t_pile *Pile)
{
    if (Pile == NULL || Pile->next == NULL)
        return (0);
    while (Pile->next != NULL)
    {
        if (Pile->nb > Pile->next->nb)
            return (-1);
        Pile = Pile->next;
    }
    return (0);
}

int main(int argc, char **argv)
{
    t_pile *pile_a;
    t_pile *pile_b;

    pile_a = NULL;
    pile_b = NULL;
    if (argc < 2)
        return (0);
    if (ft_valid_args(argv, &pile_a) == -1)
    {
        ft_putstr("Error\n", 2);
        return (ft_lstclear(&pile_a), 0);
    }
    if (ft_is_sorted(pile_a) == 0)
        return (ft_putstr("Already sorted!\n", 1), ft_lstclear(&pile_a), 0);
    ft_radixsort(&pile_a, &pile_b);

    ft_putstr("Liste A: \n", 1);
    ft_putlst(pile_a);
    ft_putstr("Liste B: \n", 1);
    ft_putlst(pile_b);
    if (ft_is_sorted(pile_a) == 0)
    {
        ft_putstr("Stack has been sorted in: \n", 1);
        ft_putnbr(g_count);
        ft_putstr(" instructions!\n", 1);
    }

    ft_lstclear(&pile_a);
    ft_lstclear(&pile_b);
    return (0);
}