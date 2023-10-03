/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maburnet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 20:38:30 by maburnet          #+#    #+#             */
/*   Updated: 2023/10/03 17:12:10 by maburnet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	ft_lstswap(t_pile **Pile)
{
	t_pile	*prev;
	t_pile	*current;

	if (*Pile == NULL || (*Pile)->next == NULL)
		return ;
	prev = *Pile;
	current = (*Pile)->next;
	prev->next = current ->next;
	current->next = prev;
	*Pile = current;
}

void	do_sa(t_pile **pile_a)
{
	ft_lstswap(pile_a);
	ft_putstr("sa\n");
}

void	do_sb(t_pile **pile_b)
{
	ft_lstswap(pile_b);
	ft_putstr("sb\n");
}

void	do_ss(t_pile **pile_a, t_pile **pile_b)
{
	ft_lstswap(pile_a);
	ft_lstswap(pile_b);
	ft_putstr("ss\n");
}
