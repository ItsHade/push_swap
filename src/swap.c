#include "../include/push_swap.h"

void ft_lstswap(t_pile **Pile)
{
    t_pile *prev;
    t_pile *current;

    if (*Pile == NULL || (*Pile)->next == NULL)
        return ;
    prev = *Pile;
    current = (*Pile)->next;
    prev->next = current ->next;
    current->next = prev;
    *Pile = current;
}

void do_sa(t_pile **pile_a)
{
    ft_lstswap(pile_a);
    ft_putstr("sa\n", 1);
}

void do_sb(t_pile **pile_b)
{
    ft_lstswap(pile_b);
    ft_putstr("sb\n", 1);
}

void do_ss(t_pile **pile_a, t_pile **pile_b)
{
    ft_lstswap(pile_a);
    ft_lstswap(pile_b);
    ft_putstr("ss\n", 1);
}
