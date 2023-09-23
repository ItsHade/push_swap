/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_list.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maburnet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 21:01:57 by maburnet          #+#    #+#             */
/*   Updated: 2023/09/21 21:53:49 by maburnet         ###   ########.fr       */
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
		ft_putchar(' ', 1);
		i++;
	}
	ft_putchar('\n', 1);
}

void	ft_putlst(t_pile *lst)
{
	t_pile	*current;

	current = lst;
	while (current != NULL)
	{
		ft_putchar('[', 1);
		ft_putnbr(current->nb);
		ft_putchar(']', 1);
		current = current->next;
	}
	ft_putchar('\n', 1);
}

void	ft_putlst2(t_pile *lst)
{
	t_pile	*current;

	current = lst;
	while (current != NULL)
	{
		ft_putchar('[', 1);
		ft_putnbr(current->index);
		ft_putchar(']', 1);
		current = current->next;
	}
	ft_putchar('\n', 1);
}

t_pile	*ft_lstcreate_b(void)
{
	t_pile	*testpile;
	char	c;

	c = 'A';
	testpile = ft_lstnew(c);
	c++;
	while (testpile != NULL && c <= 'Z')
	{
		ft_lstadd_back(&testpile, ft_lstnew(c));
		c++;
	}
	ft_putstr("Finished creating the linked list!\n", 1);
	return (testpile);
}

t_pile	*ft_lstcreate_a(void)
{
	t_pile	*testpile;
	char	c;

	c = 'a';
	testpile = ft_lstnew(c);
	c++;
	while (testpile != NULL && c <= 'z')
	{
		ft_lstadd_back(&testpile, ft_lstnew(c));
		c++;
	}
	ft_putstr("Finished creating the linked list!\n", 1);
	return (testpile);
}
