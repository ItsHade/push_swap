/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maburnet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 14:00:06 by maburnet          #+#    #+#             */
/*   Updated: 2023/10/03 23:09:59 by maburnet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/checker.h"

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

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	unsigned char	*str1;
	unsigned char	*str2;

	str1 = (unsigned char *)s1;
	str2 = (unsigned char *)s2;
	i = 0;
	while ((str1[i] || str2[i]) && i < n)
	{
		if (str1[i] < str2[i])
			return (-1);
		else if (str1[i] > str2[i])
			return (1);
		i++;
	}
	return (0);
}

int	ft_do_instruction(t_pile **pile_a, t_pile **pile_b, char *buffer)
{
	if (ft_strncmp(buffer, "sa\n", ft_strlen(buffer)) == 0)
		do_sa(pile_a);
	else if (ft_strncmp(buffer, "sb\n", ft_strlen(buffer)) == 0)
		do_sb(pile_b);
	else if (ft_strncmp(buffer, "ss\n", ft_strlen(buffer)) == 0)
		do_ss(pile_a, pile_b);
	else if (ft_strncmp(buffer, "ra\n", ft_strlen(buffer)) == 0)
		do_ra(pile_a);
	else if (ft_strncmp(buffer, "rb\n", ft_strlen(buffer)) == 0)
		do_rb(pile_b);
	else if (ft_strncmp(buffer, "rr\n", ft_strlen(buffer)) == 0)
		do_rr(pile_a, pile_b);
	else if (ft_strncmp(buffer, "rra\n", ft_strlen(buffer)) == 0)
		do_rra(pile_a);
	else if (ft_strncmp(buffer, "rrb\n", ft_strlen(buffer)) == 0)
		do_rrb(pile_b);
	else if (ft_strncmp(buffer, "rrr\n", ft_strlen(buffer)) == 0)
		do_rrr(pile_a, pile_b);
	else if (ft_strncmp(buffer, "pa\n", ft_strlen(buffer)) == 0)
		do_pa(pile_a, pile_b);
	else if (ft_strncmp(buffer, "pb\n", ft_strlen(buffer)) == 0)
		do_pb(pile_a, pile_b);
	else
		return (-1);
	return (0);
}

int	ft_get_instructions(t_pile **pile_a, t_pile **pile_b)
{
	int		nbbytes;
	int		error;
	char	*buffer;

	nbbytes = 1;
	buffer = NULL;
	error = 0;
	while (nbbytes > 0)
	{
		buffer = get_next_line(0, &nbbytes);
		if (buffer == NULL)
			return (-1);
		if (nbbytes > 0)
		{
			error = ft_do_instruction(pile_a, pile_b, buffer);
			if (error == -1)
			{
				free(buffer);
				return (-1);
			}
		}
		free(buffer);
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
		ft_putstr_fd("Error\n", 2);
		return (ft_lstclear(&pile_a), 0);
	}
	if (ft_get_instructions(&pile_a, &pile_b) == -1)
	{
		ft_lstclear(&pile_a);
		ft_lstclear(&pile_b);
		return (ft_putstr_fd("ERROR\n", 2), -1);
	}
	if (ft_is_sorted(pile_a) == -1 || ft_lstsize(pile_b) > 0)
		ft_putstr("KO\n");
	else
		ft_putstr("OK\n");
	ft_lstclear(&pile_a);
	ft_lstclear(&pile_b);
	return (0);
}
