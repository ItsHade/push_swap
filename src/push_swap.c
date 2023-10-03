/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maburnet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 21:00:37 by maburnet          #+#    #+#             */
/*   Updated: 2023/09/16 21:00:52 by maburnet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	ft_is_sorted(t_pile *Pile)
{
	if (Pile == NULL || Pile->next == NULL)
		return (0);
	while (Pile->next != NULL)
	{
		if (Pile->index > Pile->next->index)
			return (-1);
		Pile = Pile->next;
	}
	return (0);
}

int	ft_get_min(t_pile **pile_a, long int last)
{
	t_pile		*current;
	t_pile		*min_element;
	long		min;
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

void	ft_add_index(t_pile **pile_a, int size)
{
	long	min;
	int		i;

	min = -2147483649;
	i = 0;
	while (i < size)
	{
		min = ft_get_min(pile_a, min);
		i++;
	}
}

void	ft_push_swap(t_pile **pile_a, t_pile **pile_b, int size)
{
	if (size == 2)
		do_sa(pile_a);
	else if (size == 3)
		ft_sort3(pile_a);
	else
		ft_sort(pile_a, pile_b, size);
}
