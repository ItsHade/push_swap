/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_list.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maburnet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 21:01:57 by maburnet          #+#    #+#             */
/*   Updated: 2023/09/16 21:03:45 by maburnet         ###   ########.fr       */
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
	int		element;
	t_pile	*current;

	element = 0;
	current = lst;
	while (current != NULL)
	{
		ft_putstr("Element ", 1);
		ft_putnbr(element);
		ft_putstr(": ", 1);
		ft_putnbr(current->nb);
		ft_putstr(" index: ", 1);
		ft_putnbr(current->index);
		ft_putchar('\n', 1);
		current = current->next;
		element++;
	}
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
