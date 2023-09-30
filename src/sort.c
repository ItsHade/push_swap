/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maburnet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 21:04:22 by maburnet          #+#    #+#             */
/*   Updated: 2023/09/27 15:06:51 by maburnet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	ft_get_min(t_pile **pile_a, long int last)
{
	t_pile	*current;
	t_pile	*min_element;
	long	min;
	static int	i = 0;

	if (*pile_a == NULL)
		return (0);
	current = *pile_a;
	min = 2147483648;
	min_element = *pile_a;
	while (current != NULL)
	{
		if (current->nb < min && current->nb > last)
		{
			min_element = current;
			min = current->nb;
		}
		current = current->next;
	}
	min_element->index = i;
	i++;
	return (min);
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
		// maybe possible de stopper avant et ne pas rotate pour rien si il n'y a plus de index en dessous de size / 2
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

int	ft_get_max_index_pos(t_pile **pile)
{
	int		max_pos;
	int		index;
	t_pile	*current;

	max_pos = 0;
	index = (*pile)->index;
	current = *pile;
	while (current != NULL)
	{
		if (current->index > index)
			max_pos = current->pos;
		current = current->next;
	}
	return (max_pos);
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

int	ft_first_is_lowest(t_pile **pile)
{
	if ((*pile)->index == ft_get_min_index(*pile))
		return (0);
	return (-1);
}

int	ft_get_cost_a(t_pile **pile_a, t_pile *element_b)
{
	t_pile	*current;
	int		size;
	int		cost;
	int		min;
	int		max;

	current = *pile_a;
	size = ft_lstsize(current);
	cost = 0;
	max = ft_get_max_index(*pile_a);
	min = ft_get_min_index(*pile_a);
	while (current != NULL && current->next != NULL)
	{
		if (current->index == min && element_b->index < current->index)
			break ;
		cost++;
		if (current->index == max && element_b->index > current->index)
			break ;
		if (element_b->index > current->index && element_b->index < current->next->index)
			break ;
		current = current->next;
	}
	if (element_b->index > current->index && current->next == NULL)
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

	ft_get_pos(pile_a);
	ft_get_pos(pile_b);
	size_b = ft_lstsize(*pile_b);
	current = *pile_b;
	while (current != NULL)
	{
		current->cost_to_pos_a = ft_get_cost_a(pile_a, current);
		current->cost_to_top_b = ft_get_cost_b(current, size_b);
		current = current->next;
	}
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
		check = ft_calculate_move_cost(current->cost_to_pos_a, current->cost_to_top_b);
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
	{	do_rra(pile_a);
		to_pos_a++;
	}
	while (to_pos_a > 0)
	{
		do_ra(pile_a);
		to_pos_a--;
	}
	do_pa(pile_a, pile_b);
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
