#include "../include/push_swap.h"

void ft_lstswap(pile **Pile)
{
    pile *prev;
    pile *current;

    if (*Pile == NULL || (*Pile)->next == NULL)
        return ;
    prev = *Pile;
    current = (*Pile)->next;
    prev->next = current ->next;
    current->next = prev;
    *Pile = current;
}

void do_sa(pile **pile_a)
{
    ft_lstswap(pile_a);
    ft_putstr("sa\n", 1);
}

void do_sb(pile **pile_b)
{
    ft_lstswap(pile_b);
    ft_putstr("sb\n", 1);
}

void do_ss(pile **pile_a, pile **pile_b)
{
    ft_lstswap(pile_a);
    ft_lstswap(pile_b);
    ft_putstr("ss\n", 1);
}
