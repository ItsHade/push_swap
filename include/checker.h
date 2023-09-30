/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maburnet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 13:42:46 by maburnet          #+#    #+#             */
/*   Updated: 2023/09/27 14:14:21 by maburnet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include <unistd.h>
# include <stdlib.h>

typedef struct s_pile
{
	long			nb;
	int				index;
	int				pos;
	int				cost_to_pos_a;
	int				cost_to_top_b;
	struct s_pile	*next;
}	t_pile;

/* PUT Functions */

void	ft_putchar(char c);

void	ft_putstr(char *str);

void	ft_putstr_fd(char *str, int fd);

void	ft_putnbr(int nb);

/* Input checks */

int		ft_valid_args(char **argv, t_pile **pile_a);

#endif
