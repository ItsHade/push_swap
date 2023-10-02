/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_move.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maburnet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 10:36:10 by maburnet          #+#    #+#             */
/*   Updated: 2023/10/02 10:41:56 by maburnet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	ft_get_index_of_best(t_pile **pile_a, t_pile **pile_b)
{
	t_pile	*current;
	int		best_move;
	int		best_index;
	int		check;

	best_index = (*pile_b)->index;
	best_move = INT_MAX;
	current = *pile_b;
	while (current != NULL)
	{
		check = ft_calculate_move_cost(current->cost_to_pos_a,
				current->cost_to_top_b);
		if (check < best_move)
		{
			best_index = current->index;
			best_move = check;
		}
		current = current->next;
	}
	return (best_index);
}

int	ft_get_cost_a_of_index(t_pile **pile_b, int best_index)
{
	t_pile	*current;

	current = *pile_b;
	while (current->index != best_index)
	{
		current = current->next;
	}
	return (current->cost_to_pos_a);
}

int	ft_get_cost_b_of_index(t_pile **pile_b, int best_index)
{
	t_pile	*current;

	current = *pile_b;
	while (current->index != best_index)
	{
		current = current->next;
	}
	return (current->cost_to_top_b);
}

void	ft_do_best2(t_pile **pile_a, t_pile **pile_b,
		int to_top_b, int to_pos_a)
{
	while (to_top_b < 0)
	{
		do_rrb(pile_b);
		to_top_b++;
	}
	while (to_top_b > 0)
	{
		do_rb(pile_b);
		to_top_b--;
	}
	while (to_pos_a < 0)
	{
		do_rra(pile_a);
		to_pos_a++;
	}
	while (to_pos_a > 0)
	{
		do_ra(pile_a);
		to_pos_a--;
	}
}

void	ft_do_best(t_pile **pile_a, t_pile **pile_b)
{
	int	best_index;
	int	to_top_b;
	int	to_pos_a;

	best_index = ft_get_index_of_best(pile_a, pile_b);
	to_top_b = ft_get_cost_b_of_index(pile_b, best_index);
	to_pos_a = ft_get_cost_a_of_index(pile_b, best_index);
	while (to_top_b > 0 && to_pos_a > 0)
	{
		do_rr(pile_a, pile_b);
		to_top_b--;
		to_pos_a--;
	}
	while (to_top_b < 0 && to_pos_a < 0)
	{
		do_rrr(pile_a, pile_b);
		to_top_b++;
		to_pos_a++;
	}
	ft_do_best2(pile_a, pile_b, to_top_b, to_pos_a);
	do_pa(pile_a, pile_b);
}
