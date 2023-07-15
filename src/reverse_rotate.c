#include "../include/push_swap.h"

void ft_lst_reverse_rotate(pile **Pile)
{
    pile *last;
    pile *current;

    if (*Pile == NULL || (*Pile)->next == NULL) 
        return ;
    current = *Pile;
    last = ft_lstlast(*Pile);
    while (current->next->next != NULL)
        current = current->next;
    current->next = NULL;
    last->next = *Pile;
    *Pile = last;
}

void do_rra(pile **pile_a)
{
    ft_lst_reverse_rotate(pile_a);
    ft_putstr("rra\n", 1);
}

void do_rrb(pile **pile_b)
{
    ft_lst_reverse_rotate(pile_b);
    ft_putstr("rrb\n", 1);
}

void do_rrr(pile **pile_a, pile **pile_b)
{
    ft_lst_reverse_rotate(pile_a);
    ft_lst_reverse_rotate(pile_b);
    ft_putstr("rrr\n", 1);
}