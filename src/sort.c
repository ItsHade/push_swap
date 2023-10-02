/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maburnet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 21:04:22 by maburnet          #+#    #+#             */
/*   Updated: 2023/10/02 10:44:28 by maburnet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	ft_initiate_sorting(t_pile **pile_a, t_pile **pile_b, int size)
{
	int	pushed;
	int	i;

	pushed = 0;
	i = 0;
	while (size > 6 && i < size && pushed < size / 2)
	{
		if ((*pile_a)->index <= size / 2)
		{
			do_pb(pile_a, pile_b);
			pushed++;
		}
		else
			do_ra(pile_a);
		i++;
	}
	while (size - pushed > 3)
	{
		do_pb(pile_a, pile_b);
		pushed++;
	}
}

void	ft_sort3(t_pile **pile_a)
{
	int	max;

	max = ft_get_max_index(*pile_a);
	if ((*pile_a)->index == max)
	{
		do_ra(pile_a);
	}
	else if ((*pile_a)->next->index == max)
	{
		do_rra(pile_a);
	}
	if ((*pile_a)->index > (*pile_a)->next->index)
		do_sa(pile_a);
}

int	ft_get_index_zero_pos(t_pile **pile_a)
{
	t_pile	*current;

	current = *pile_a;
	while (current->index != 0)
	{
		current = current->next;
	}
	return (current->pos);
}

void	ft_put_index_zero_top(t_pile **pile_a, int size)
{
	int	zero_pos;

	ft_get_pos(pile_a);
	zero_pos = ft_get_index_zero_pos(pile_a);
	while ((*pile_a)->index != 0)
	{
		if (zero_pos <= size / 2)
			do_ra(pile_a);
		else
			do_rra(pile_a);
	}
}

void	ft_sort(t_pile **pile_a, t_pile **pile_b, int size)
{
	ft_initiate_sorting(pile_a, pile_b, size);
	ft_sort3(pile_a);
	while (*pile_b != NULL)
	{
		ft_get_cost(pile_a, pile_b);
		ft_do_best(pile_a, pile_b);
	}
	ft_put_index_zero_top(pile_a, size);
}
