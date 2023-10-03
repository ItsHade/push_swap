/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maburnet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 13:02:37 by maburnet          #+#    #+#             */
/*   Updated: 2023/10/03 17:12:24 by maburnet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

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
	ft_add_index(&pile_a, size);
	if (ft_is_sorted(pile_a) == 0)
		return (ft_lstclear(&pile_a), 0);
	ft_push_swap(&pile_a, &pile_b, size);
	ft_lstclear(&pile_a);
	ft_lstclear(&pile_b);
	return (0);
}
