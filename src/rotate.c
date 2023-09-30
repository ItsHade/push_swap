/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maburnet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 20:35:54 by maburnet          #+#    #+#             */
/*   Updated: 2023/09/27 14:07:57 by maburnet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

extern int g_count;

void	ft_lstrotate(t_pile **Pile)
{
	t_pile	*last;
	t_pile	*current;
	t_pile	*next;

	if (*Pile == NULL || (*Pile)->next == NULL)
		return ;
	last = ft_lstlast(*Pile);
	next = (*Pile)->next;
	current = *Pile;
	current->next = NULL;
	last->next = current;
	*Pile = next;
}

void	do_ra(t_pile **pile_a)
{
	ft_lstrotate(pile_a);
	g_count++;
	ft_putstr("ra\n");
}

void	do_rb(t_pile **pile_b)
{
	ft_lstrotate(pile_b);
	g_count++;
	ft_putstr("rb\n");
}

void	do_rr(t_pile **pile_a, t_pile **pile_b)
{
	ft_lstrotate(pile_a);
	ft_lstrotate(pile_b);
	g_count++;
	ft_putstr("rr\n");
}
