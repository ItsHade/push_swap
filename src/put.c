/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maburnet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 20:45:07 by maburnet          #+#    #+#             */
/*   Updated: 2023/09/27 14:07:52 by maburnet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str && str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
}

void	ft_putstr_fd(char *str, int fd)
{
	int	i;

	i = 0;
	while (str && str[i])
	{
		write(fd, &str[i], 1);
		i++;
	}
}

void	ft_putnbr(int nb)
{
	unsigned int	num;

	if (nb < 0)
	{
		num = -nb;
		ft_putchar('-');
	}
	else
		num = nb;
	if (num <= 9)
		ft_putchar(num + 48);
	else
	{
		ft_putnbr(num / 10);
		ft_putchar(num % 10 + 48);
	}
}
