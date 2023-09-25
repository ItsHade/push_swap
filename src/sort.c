/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maburnet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 21:04:22 by maburnet          #+#    #+#             */
/*   Updated: 2023/09/25 21:13:55 by maburnet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

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
	ft_putstr("------------\nsize: ", 1);
	ft_putnbr(size);
	ft_putchar('\n', 1);
	while (current->index != index)
	{
		current = current->next;
		count++;
	}
	ft_putstr("count: ", 1);
	ft_putnbr(count);
	ft_putchar('\n', 1);
	if (count > (size / 2)) //maybe >=
		return (-1);
	return (1);
}


void	ft_sort3(t_pile **pile_a)
{
	int	max;

	max = ft_maxIndex(*pile_a);
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
	//si is sorted == 0 we stop and we have A = [6, 7, 8] et B = [5, 4, 3, 2, 1, 0]
	while (size > 3 && ft_is_sorted(*pile_a) == -1)
	{
		a = ft_getrotatelen(*pile_a, output[i], size);
		ft_putstr("a: ", 1);
		ft_putnbr(a);
		ft_putchar('\n', 1);
		ft_putstr("Liste A index: ", 1);
		ft_putlst2(*pile_a);
		while ((*pile_a)->index != output[i])
		{
			if (a == 1)
				do_ra(pile_a);
			else
				do_rra(pile_a);
		}
		do_pb(pile_a, pile_b);
		size--;
		i++;
	}
	ft_putstr("TEST: ", 1);
	ft_putlst(*pile_a);
	ft_sort3(pile_a);
	ft_putlst(*pile_a);
	// stop ^ quand size == 3 (3 elements dans A) swap si besoin et puis remettre tout B sur A
	// *1
	while (*pile_b != NULL)
	{
		do_pa(pile_a, pile_b);
	}
	ft_putstr("pile_a after: ", 1);
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

// get min and max check which is gonna take less instructions to get to


void	ft_radixsort(t_pile **pile_a, t_pile **pile_b, int size)
{
	int	place;
	int	max;

	place = 1;
	max = ft_maxIndex(*pile_a);
	while (max / place > 0)
	{
		ft_putstr("Liste A: ", 1);
		ft_putlst(*pile_a);
		ft_putstr("Liste B: ", 1);
		ft_putlst(*pile_b);
		// *1 enlever la boucle qui remet tout dans A et refaire une fonction qu'on appelle une fois sur deux qui tri a partir de B (a l'envers)
		ft_countingSort(pile_a, pile_b, size, place, 10);
		place *= 10;
	}
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

void ft_get_pos(t_pile **pile)
{
	t_pile	*current;
	int	i;

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
	t_pile *current;

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
	//!= lowest index possible 0 or 1
	while ((*pile_a)->index != 0)
	{
		if (zero_pos <= size / 2)
			do_ra(pile_a);
		else
			do_rra(pile_a);
	}
}

int	ft_get_max_pos(t_pile **pile)
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
	int		max_pos;

	current = *pile_a;
	max_pos = ft_get_max_pos(pile_a);
	while (current != NULL && current->next != NULL)
	{
		current = current->next;
	}
	return (current->pos);
}

void	ft_place(t_pile **pile_a, t_pile **pile_b)
{
	int max_pos;

	ft_get_pos(pile_a);
	ft_get_pos(pile_b);
	// ft_putstr("Pos A: ", 1);
	// ft_putlst_pos(*pile_a);
	// ft_putstr("Pos B: ", 1);
	// ft_putlst_pos(*pile_b);
	max_pos = ft_get_max_pos(pile_a);
	if ((*pile_b)->index < (*pile_a)->index)
	{
		while (ft_get_last_index(pile_a) > (*pile_b)->index && ft_get_last_pos(pile_a) != max_pos)
			do_rra(pile_a);
		do_pa(pile_a, pile_b);
	}
	else
	{
		while ((*pile_a)->index < (*pile_b)->index && (*pile_a)->pos != max_pos)
			do_ra(pile_a);
		do_pa(pile_a, pile_b);
	}

}

void	ft_sort(t_pile **pile_a, t_pile **pile_b, int size)
{
	ft_initiate_sorting(pile_a, pile_b, size);
	ft_sort3(pile_a);
	while (*pile_b != NULL)
	{
		ft_place(pile_a, pile_b);
		ft_putstr("PLACED\n", 1);
	}
	ft_put_index_zero_top(pile_a, size);

}
