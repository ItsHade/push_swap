/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_cost.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maburnet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 10:12:53 by maburnet          #+#    #+#             */
/*   Updated: 2023/10/02 11:08:16 by maburnet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	ft_get_max_index(t_pile *pile_a)
{
	t_pile	*current;
	int		max_index;

	current = pile_a;
	max_index = pile_a->index;
	while (current != NULL)
	{
		if (current->index > max_index)
			max_index = current->index;
		current = current->next;
	}
	return (max_index);
}

int	ft_get_min_index(t_pile *pile_a)
{
	t_pile	*current;
	int		min_index;

	current = pile_a;
	min_index = pile_a->index;
	while (current != NULL)
	{
		if (current->index < min_index)
			min_index = current->index;
		current = current->next;
	}
	return (min_index);
}

int	ft_get_cost_a(t_pile **pile_a, t_pile *elem_b, int min, int max)
{
	t_pile	*cur;
	int		cost;
	int		size;

	cur = *pile_a;
	cost = 0;
	size = ft_lstsize(cur);
	while (cur != NULL && cur->next != NULL)
	{
		if (cur->index == min && elem_b->index < cur->index)
			break ;
		cost++;
		if (cur->index == max && elem_b->index > cur->index)
			break ;
		if (elem_b->index > cur->index && elem_b->index < cur->next->index)
			break ;
		cur = cur->next;
	}
	if (elem_b->index > cur->index && cur->next == NULL)
		cost++;
	if (cost >= size)
		return (0);
	if (cost > size / 2)
		return (((size - cost)) * -1);
	return (cost);
}

int	ft_get_cost_b(t_pile *element_b, int size)
{
	if (element_b->pos > size / 2)
		return ((size - element_b->pos) * -1);
	else
		return (element_b->pos);
}

void	ft_get_cost(t_pile **pile_a, t_pile **pile_b)
{
	int		min_cost;
	int		size_b;
	t_pile	*current;
	int		min;
	int		max;

	ft_get_pos(pile_a);
	ft_get_pos(pile_b);
	size_b = ft_lstsize(*pile_b);
	current = *pile_b;
	while (current != NULL)
	{
		min = ft_get_min_index(*pile_a);
		max = ft_get_max_index(*pile_a);
		current->cost_to_pos_a = ft_get_cost_a(pile_a, current, min, max);
		current->cost_to_top_b = ft_get_cost_b(current, size_b);
		current = current->next;
	}
}
