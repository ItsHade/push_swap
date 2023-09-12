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
    while (Pile->next != NULL)
    {
        if (Pile->nb > Pile->next->nb)
            return (-1);
        Pile = Pile->next;
    }
    return (0);
}

int ft_get_min(t_pile **pile_a, long int last)
{
    t_pile *current;
    t_pile *min;
    static int i = 0;
 
    if (*pile_a == NULL)
        return (0);
    current = *pile_a;
    min = *pile_a;
    while (current != NULL)
    {
        if (current->nb < min->nb && current->nb > last)
            min = current;
        current = current->next;
    }  
    min->index = i;
    i++;
    ft_putnbr(min->nb);
    ft_putstr("->", 1);         
    ft_putnbr(min->index);
    ft_putstr("   ", 1);
    return (min->nb);
}

void ft_put_min_to_b(t_pile **pile_a, t_pile **pile_b, int min)
{
    if (*pile_a == NULL)
        return ;
    while (*pile_a != NULL && (*pile_a)->nb != min)
    {
        do_ra(pile_a);
        g_count++;
    }
    do_pb(pile_a, pile_b);
    g_count++;
}

// sort 2, 3, 4, 5, large
// get min and max check which is gonna take less instructions to get to
int ft_sort(t_pile **pile_a, t_pile **pile_b)
{
    long int min;
    int len;
    int i;

    i = 0;
    len = ft_lstsize(*pile_a);
    ft_putstr("len: ", 1);
    ft_putnbr(len);
    ft_putchar('\n', 1);
    min = -2147483649;
    while (i < len)
    {
        min = ft_get_min(pile_a, min);
        ft_putstr("min: ", 1);
        ft_putnbr(min);
        ft_putchar('\n', 1);
        
        // ft_put_min_to_b(pile_a, pile_b, min);
        i++;
    }
    // ft_sort_by_index(pile_a, pile_b);
    // i = 0;
    // while (i < len)
    // {
    //     do_pa(pile_a, pile_b);
    //     g_count++;
    //     i++;
    // }
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
    // ft_putstr("Liste A: \n", 1);
    // ft_putlst(pile_a);
    // ft_putstr("Liste B: \n", 1);
    // ft_putlst(pile_b);
    if (ft_is_sorted(pile_a) == 0)
        return (ft_putstr("Already sorted!\n", 1), ft_lstclear(&pile_a), 0);
    ft_sort(&pile_a, &pile_b);
    // do_ra(&pile_a);
    // do_ra(&pile_a);
    // do_ra(&pile_a);
    // do_pb(&pile_a, &pile_b);
    // do_pb(&pile_a, &pile_b);
    // do_pb(&pile_a, &pile_b);
    // do_pb(&pile_a, &pile_b);
    /*
    ft_putstr("Liste A: \n", 1);
    ft_putlst(pile_a);
    ft_putstr("Liste B: \n", 1);
    ft_putlst(pile_b);
    */
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