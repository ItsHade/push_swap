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

//
int	g_count = 0;

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

void	ft_addIndex(t_pile **pile_a, int size)
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

int	main(int argc, char **argv)
{
	t_pile	*pile_a;
	t_pile	*pile_b;
	int		size;

	pile_a = NULL;
	pile_b = NULL;
	if (argc < 2)
		return (0);
	if (ft_valid_args(argv, &pile_a) == -1)
	{
		ft_putstr_fd("Error\n", 2);
		return (ft_lstclear(&pile_a), 0);
	}
	size = ft_lstsize(pile_a);
	ft_addIndex(&pile_a, size);
	//enlever already sorted
	if (ft_is_sorted(pile_a) == 0)
		return (ft_putstr("Already sorted!\n"), ft_lstclear(&pile_a), 0);
	ft_push_swap(&pile_a, &pile_b, size);
	if (ft_is_sorted(pile_a) == 0)
	{
		ft_putstr("\033[1;32mStack has been sorted!\033[1;0m\n");
	}
	ft_putnbr(g_count);
	ft_putstr(" instructions!\n");
	ft_lstclear(&pile_a);
	ft_lstclear(&pile_b);
	return (0);
}
