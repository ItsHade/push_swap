/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maburnet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 20:51:20 by maburnet          #+#    #+#             */
/*   Updated: 2023/09/16 20:56:57 by maburnet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

t_pile	*ft_lstnew(int nb)
{
	t_pile	*new;

	new = malloc(sizeof(t_pile));
	if (!new)
		return (NULL);
	new->nb = nb;
	new->next = NULL;
	return (new);
}

t_pile	*ft_lstlast(t_pile *lst)
{
	if (lst == NULL || lst->next == NULL)
		return (lst);
	while (lst->next != NULL)
	{
		lst = lst->next;
	}
	return (lst);
}

void	ft_lstadd_back(t_pile **lst, t_pile *new)
{
	t_pile	*cur;

	cur = *lst;
	if (lst != NULL && *lst != NULL)
	{
		cur = ft_lstlast(*(lst));
		cur->next = new;
		return ;
	}
	*lst = new;
}

void	ft_lstclear(t_pile **lst)
{
	t_pile	*tmp;
	t_pile	*start;

	start = *lst;
	while (start)
	{
		tmp = start->next;
		start->nb = 0;
		free(start);
		start = tmp;
	}
	*lst = NULL;
}

int	ft_lstsize(t_pile *lst)
{
	size_t	i;

	i = 0;
	while (lst)
	{
		lst = lst->next;
		i++;
	}
	return (i);
}
