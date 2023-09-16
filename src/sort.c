/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maburnet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 21:04:22 by maburnet          #+#    #+#             */
/*   Updated: 2023/09/16 21:07:05 by maburnet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

//
extern int g_count;

int	ft_maxIndex(t_pile *pile_a)
{
	int	max;

	max = pile_a->index;
	while (pile_a != NULL)
	{
		if (pile_a->index > max)
			max = pile_a->index;
		pile_a = pile_a->next;
	}
	return (max);
}

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

int	ft_getrotatelen(t_pile *pile_a, int index, int size)
{
	int	count;
	t_pile	*current;

	count = 0;
	current = pile_a;
	// ft_putstr("------------\nsize: ", 1);
	// ft_putnbr(size);
	// ft_putchar('\n', 1);
	while (current->index != index)
	{
		current = current->next;
		count++;
	}
	// ft_putstr("count: ", 1);
	// ft_putnbr(count);
	// ft_putchar('\n', 1);
	if (count >  (size / 2))
		return (-1);
	return (1);
}

// too long -> divide in multiple functions
void	ft_countingSort(t_pile **pile_a, t_pile **pile_b, int size, int place, int max)
{
	int	i;
	int	a;
	int	output[size + 1];
	int	count[max];
	t_pile	*current;

	current = *pile_a;
	i = 0;
	while (i < max)
	{
		count[i] = 0;
		i++;
	}
	while (current != NULL)
	{
		count[(current->index / place) % 10]++;
		current = current->next;
	}
	i = 1;
	while (i < 10)
	{
		count[i] += count[i - 1];
		i++;
	}
	i = size - 1;
	while (i >= 0)
	{
		current = *pile_a;
		a = 0;
		while (a < i)
		{
			current = current->next;
			a++;
		}
		output[count[(current->index / place) % 10] - 1] = current->index;
		count[(current->index / place) % 10]--;
		i--;
	}
	i = 0;
	ft_putstr("Avant boucle finale: \n", 1);
	ft_putstr("output: ", 1);
	ft_putarray(output, size);
	ft_putstr("count: ", 1);
	ft_putarray(count, max);
	while (*pile_a != NULL)
	{
		a = ft_getrotatelen(*pile_a, output[i], size);
		// ft_putstr("a: ", 1);
		// ft_putnbr(a);
		// ft_putchar('\n', 1);
		while ((*pile_a)->index != output[i])
		{
			if (a == 1)
				do_ra(pile_a);
			else
				do_rra(pile_a);
			g_count++;
		}
		do_pb(pile_a, pile_b);
		size--;
		g_count++;
		i++;
	}
	// stop ^ quand size == 2 (2 elements dans A) swap si besoin et puis remettre tout B sur A
	// *1
	while (*pile_b != NULL)
	{
		do_pa(pile_a, pile_b);
		g_count++;
	}
	ft_putstr("pile_a after: \n", 1);
	ft_putlst(*pile_a);
}

void	ft_addIndex(t_pile **pile_a, int size)
{
	long	min;
	int	i;

	min = -2147483649;
	i = 0;
	while (i < size)
	{
		min = ft_get_min(pile_a, min);
		i++;
	}
}

// sort 2, 3, 4, 5, large
// get min and max check which is gonna take less instructions to get to


void	ft_radixsort(t_pile **pile_a, t_pile **pile_b)
{
	int	place;
	int	max;
	int	size;

	place = 1;
	size = ft_lstsize(*pile_a);
	ft_addIndex(pile_a, size);
	ft_putstr("Liste A: \n", 1);
	ft_putlst(*pile_a);
	ft_putstr("Liste B: \n", 1);
	ft_putlst(*pile_b);
	max = ft_maxIndex(*pile_a);
	while (max / place > 0)
	{
		// *1 enlever la boucle qui remet tout dans A et refaire une fonction qu'on appelle une fois sur deux qui tri a partir de B (a l'envers)
		ft_countingSort(pile_a, pile_b, size, place, 10);
		place *= 10;
	}
}
