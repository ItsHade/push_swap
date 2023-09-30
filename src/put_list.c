/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_list.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maburnet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 21:01:57 by maburnet          #+#    #+#             */
/*   Updated: 2023/09/27 14:09:05 by maburnet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

//below are not usefull functions in the final build

// not needed int final build
void	ft_putarray(int array[], int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		ft_putnbr(array[i]);
		ft_putchar(' ');
		i++;
	}
	ft_putchar('\n');
}

void	ft_putlst(t_pile *lst)
{
	t_pile	*current;

	current = lst;
	while (current != NULL)
	{
		ft_putchar('[');
		ft_putnbr(current->nb);
		ft_putchar(']');
		current = current->next;
	}
	ft_putchar('\n');
}

void	ft_putlst2(t_pile *lst)
{
	t_pile	*current;

	current = lst;
	while (current != NULL)
	{
		ft_putchar('[');
		ft_putnbr(current->index);
		ft_putchar(']');
		current = current->next;
	}
	ft_putchar('\n');
}

void	ft_putlst3(t_pile *lst)
{
	t_pile	*current;

	current = lst;
	while (current != NULL)
	{
		ft_putchar('[');
		ft_putnbr(current->cost_to_pos_a);
		ft_putchar(']');
		current = current->next;
	}
	ft_putchar('\n');
}

void	ft_putlst4(t_pile *lst)
{
	t_pile	*current;

	current = lst;
	while (current != NULL)
	{
		ft_putchar('[');
		ft_putnbr(current->cost_to_top_b);
		ft_putchar(']');
		current = current->next;
	}
	ft_putchar('\n');
}

void	ft_putlst_pos(t_pile *lst)
{
	t_pile	*current;

	current = lst;
	while (current != NULL)
	{
		ft_putchar('[');
		ft_putnbr(current->pos);
		ft_putchar(']');
		current = current->next;
	}
	ft_putchar('\n');
}
