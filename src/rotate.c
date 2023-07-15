#include "../include/push_swap.h"

void ft_lstrotate(pile **Pile)
{
    pile *last;
    pile *current;
    pile *next;

    if (*Pile == NULL || (*Pile)->next == NULL)
        return ;
    last = ft_lstlast(*Pile);
    next = (*Pile)->next;
    current = *Pile;
    current->next = NULL;
    last->next = current;
    *Pile = next;
}

void do_ra(pile **pile_a)
{
    ft_lstrotate(pile_a);
    ft_putstr("ra\n", 1);
}

void do_rb(pile **pile_b)
{
    ft_lstrotate(pile_b);
    ft_putstr("rb\n", 1);
}

void do_rr(pile **pile_a, pile **pile_b)
{
    ft_lstrotate(pile_a);
    ft_lstrotate(pile_b);
    ft_putstr("rr\n", 1);
}