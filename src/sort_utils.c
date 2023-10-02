/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maburnet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 10:20:58 by maburnet          #+#    #+#             */
/*   Updated: 2023/10/02 10:54:03 by maburnet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	ft_get_pos(t_pile **pile)
{
	t_pile	*current;
	int		i;

	i = 0;
	current = *pile;
	while (current != NULL)
	{
		current->pos = i;
		i++;
		current = current->next;
	}
}

int	ft_get_last_index(t_pile **pile_a)
{
	t_pile	*current;

	current = *pile_a;
	while (current != NULL && current->next != NULL)
	{
		current = current->next;
	}
	return (current->index);
}

int	ft_get_last_pos(t_pile **pile_a)
{
	t_pile	*current;

	current = *pile_a;
	while (current != NULL && current->next != NULL)
	{
		current = current->next;
	}
	return (current->pos);
}

int	ft_first_is_lowest(t_pile **pile)
{
	if ((*pile)->index == ft_get_min_index(*pile))
		return (0);
	return (-1);
}

int	ft_calculate_move_cost(int pos_a, int pos_b)
{
	if (pos_a >= 0 && pos_b >= 0)
	{
		if (pos_a >= pos_b)
			return (pos_a);
		return (pos_b);
	}
	else if (pos_a < 0 && pos_b < 0)
	{
		if (ft_abs(pos_a) > ft_abs(pos_b))
			return (ft_abs(pos_a));
	}
	else
	{
		return (ft_abs(pos_a) + ft_abs(pos_b));
	}
}
