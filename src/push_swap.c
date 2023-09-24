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
		if (Pile->nb > Pile->next->nb)
			return (-1);
		Pile = Pile->next;
	}
	return (0);
}

void	ft_sort(t_pile **pile_a, t_pile **pile_b, int size)
{
	ft_addIndex(pile_a, size);
	if (size == 2)
		do_sa(pile_a);
	else if (size == 3)
		ft_sort3(pile_a);
	else
		ft_radixsort(pile_a, pile_b, size);
}

int	main(int argc, char **argv)
{
	t_pile	*pile_a;
	t_pile	*pile_b;
	int size;

	pile_a = NULL;
	pile_b = NULL;
	if (argc < 2)
		return (0);
	if (ft_valid_args(argv, &pile_a) == -1)
	{
		ft_putstr("Error\n", 2);
		return (ft_lstclear(&pile_a), 0);
	}
	if (ft_is_sorted(pile_a) == 0)
		return (ft_putstr("Already sorted!\n", 1), ft_lstclear(&pile_a), 0);
	size = ft_lstsize(pile_a);
	ft_sort(&pile_a, &pile_b, size);
	ft_putstr("Liste A: ", 1);
	ft_putlst(pile_a);
	ft_putstr("Liste B: ", 1);
	ft_putlst(pile_b);
	if (ft_is_sorted(pile_a) == 0)
	{
		ft_putstr("Stack has been sorted!\n", 1);
	}
	ft_putnbr(g_count);
	ft_putstr(" instructions!\n", 1);
	ft_lstclear(&pile_a);
	ft_lstclear(&pile_b);
	return (0);
}
