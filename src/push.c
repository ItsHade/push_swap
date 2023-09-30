/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maburnet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 20:35:35 by maburnet          #+#    #+#             */
/*   Updated: 2023/09/27 14:07:33 by maburnet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

extern int g_count;

void	do_pa(t_pile **pile_a, t_pile **pile_b)
{
	t_pile	*next_a;
	t_pile	*next_b;

	if (*pile_b == NULL)
		return ;
	next_a = *pile_a;
	next_b = (*pile_b)->next;
	*pile_a = *pile_b;
	(*pile_a)->next = next_a;
	*pile_b = next_b;
	g_count++;
	ft_putstr("pa\n");
}

void	do_pb(t_pile **pile_a, t_pile **pile_b)
{
	t_pile	*next_a;
	t_pile	*next_b;

	if (*pile_a == NULL)
		return ;
	next_a = (*pile_a)->next;
	next_b = *pile_b;
	*pile_b = *pile_a;
	(*pile_b)->next = next_b;
	*pile_a = next_a;
	g_count++;
	ft_putstr("pb\n");
}
