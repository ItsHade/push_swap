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

int ft_get_min(t_pile **pile_a, long int last)
{
    t_pile *current;
    t_pile *min_element;
    long int min;
    static int i = 0;
 
    if (*pile_a == NULL)
        return (0);
    current = *pile_a;
    min = 2147483648;
    min_element = *pile_a;
    while (current != NULL)
    {
        if (current->nb < min && current->nb > last)
        {
            min_element = current;
            min = current->nb;
        }
        current = current->next;
    }  
    min_element->index = i;
    i++;
    ft_putstr("nb: ", 1);
    ft_putnbr(min_element->nb);
    ft_putstr(" -> index: ", 1);         
    ft_putnbr(min_element->index);
    ft_putstr("   ", 1);
    return (min);
}

/*
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
*/

void ft_sort_2(t_pile **Pile, char c)
{
    if ((*Pile)->next->index < (*Pile)->index)
    {
        if (c == 'a')
            do_sa(Pile);
        else if (c == 'b')
            do_sb(Pile);
        g_count++;
    }
}

int ft_sort_index(t_pile **pile_a, t_pile **pile_b, int len)
{
    int a;
    int max;

    while ((*pile_a)->index != 0)
    {
        do_ra(pile_a);
        g_count++;
    }
    if (*pile_b == NULL)
    {
        do_pb(pile_a, pile_b);
        do_pb(pile_a, pile_b);
        ft_sort_2(pile_b, 'b');
        g_count++;
    }
    max = (*pile_b)->next->nb;
    while (*pile_a != NULL)
    {
        while ((*pile_b)->index > (*pile_a)->index && (*pile_b)->nb < max)
        {
            do_rb(pile_b);
            g_count++;
        }
        max = (*pile_a)->nb;
        do_pb(pile_a, pile_b);
        g_count++;
    }
    a = 0;
    while (a < len)
    {
        do_pa(pile_a, pile_b);
        a++;
        g_count++;
    }
    return (0);
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
    ft_sort_index(pile_a, pile_b, len);   
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
    ft_putstr("Liste A: \n", 1);
    ft_putlst(pile_a);
    ft_putstr("Liste B: \n", 1);
    ft_putlst(pile_b);
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