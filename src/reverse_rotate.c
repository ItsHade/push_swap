/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maburnet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 20:36:32 by maburnet          #+#    #+#             */
/*   Updated: 2023/10/03 17:11:41 by maburnet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	ft_lst_reverse_rotate(t_pile **Pile)
{
	t_pile	*last;
	t_pile	*current;

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

void	do_rra(t_pile **pile_a)
{
	ft_lst_reverse_rotate(pile_a);
	ft_putstr("rra\n");
}

void	do_rrb(t_pile **pile_b)
{
	ft_lst_reverse_rotate(pile_b);
	ft_putstr("rrb\n");
}

void	do_rrr(t_pile **pile_a, t_pile **pile_b)
{
	ft_lst_reverse_rotate(pile_a);
	ft_lst_reverse_rotate(pile_b);
	ft_putstr("rrr\n");
}
