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

int	main(int argc, char **argv)
{
	t_pile	*pile_a;
	t_pile	*pile_b;

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
	ft_radixsort(&pile_a, &pile_b);
	ft_putstr("Liste A: \n", 1);
	ft_putlst(pile_a);
	ft_putstr("Liste B: \n", 1);
	ft_putlst(pile_b);
	if (ft_is_sorted(pile_a) == 0)
	{
		ft_putstr("Stack has been sorted in: \n", 1);
		ft_putnbr(g_count);
		ft_putstr(" instructions!\n", 1);
	}
	ft_lstclear(&pile_a);
	ft_lstclear(&pile_b);
	return (0);
}
