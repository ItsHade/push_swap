/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maburnet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 20:35:35 by maburnet          #+#    #+#             */
/*   Updated: 2023/10/03 15:58:32 by maburnet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	ft_lstpush(t_pile **pile_1, t_pile **pile_2)
{
	t_pile	*next_1;
	t_pile	*next_2;

	if (*pile_2 == NULL)
		return ;
	next_1 = *pile_1;
	next_2 = (*pile_2)->next;
	*pile_1 = *pile_2;
	(*pile_1)->next = next_1;
	*pile_2 = next_2;
}

void	do_pa(t_pile **pile_a, t_pile **pile_b)
{
	ft_lstpush(pile_a, pile_b);
}

void	do_pb(t_pile **pile_a, t_pile **pile_b)
{
	ft_lstpush(pile_b, pile_a);
}
