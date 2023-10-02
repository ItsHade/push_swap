/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maburnet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 20:40:27 by maburnet          #+#    #+#             */
/*   Updated: 2023/09/16 20:40:37 by maburnet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	ft_is_num(char *s)
{
	int	i;

	i = 0;
	if (s[i] == '+' || s[i] == '-')
		i++;
	if (s[i] == 0)
		return (-1);
	while (s[i])
	{
		if (s[i] < '0' || s[i] > '9')
			return (-1);
		i++;
	}
	return (0);
}

int	ft_check_splitted(char **strs, t_pile **pile_a)
{
	int		a;
	long	nb;
	t_pile	*new;

	a = 0;
	while (strs[a][0] != 0)
	{
		if (ft_is_num(strs[a]) == -1)
			return (-1);
		nb = ft_atol(strs[a]);
		if (nb < INT_MIN || nb > INT_MAX)
			return (-1);
		new = ft_lstnew(nb);
		ft_lstadd_back(pile_a, new);
		a++;
	}
	return (0);
}

int	ft_check_dup(t_pile **pile_a)
{
	t_pile	*current;
	t_pile	*check;

	current = *pile_a;
	while (current != NULL)
	{
		check = current->next;
		while (check != NULL)
		{
			if (check->nb == current->nb)
				return (-1);
			check = check->next;
		}
		current = current->next;
	}
	return (0);
}

int	ft_valid_args(char **argv, t_pile **pile_a)
{
	int		i;
	char	**strs;

	i = 1;
	while (argv[i])
	{
		strs = ft_split(argv[i], ' ');
		if (ft_check_splitted(strs, pile_a) == -1)
			return (ft_freesplit(strs), -1);
		ft_freesplit(strs);
		i++;
	}
	if (ft_check_dup(pile_a) == -1)
		return (-1);
	return (0);
}
