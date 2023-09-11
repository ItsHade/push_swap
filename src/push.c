#include "../include/push_swap.h"


//if (*pile_a == NULL) ?
void do_pa(t_pile **pile_a, t_pile **pile_b)
{
    t_pile *next_a;
    t_pile *next_b;

    if (*pile_b == NULL)
        return ;
    next_a = *pile_a;
    next_b = (*pile_b)->next;
    *pile_a = *pile_b;
    (*pile_a)->next = next_a;
    *pile_b = next_b;
    ft_putstr("pa\n", 1);
}

void do_pb(t_pile **pile_a, t_pile **pile_b)
{
    t_pile *next_a;
    t_pile *next_b;

    if (*pile_a == NULL)
        return ;
    next_a = (*pile_a)->next;
    next_b = *pile_b;
    *pile_b = *pile_a;
    (*pile_b)->next = next_b;
    *pile_a = next_a;
    ft_putstr("pb\n", 1);
}