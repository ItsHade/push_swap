/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maburnet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 14:00:06 by maburnet          #+#    #+#             */
/*   Updated: 2023/09/27 14:12:20 by maburnet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	main(int argc, char *argv)
{
	t_pile *pile_a;
	t_pile *pile_b;
	
	if (argc < 2)
		return (0);
	if (ft_valid_args(argv, &pile_a) == -1)
	{
		ft_putstr_fd("Error\n", 2);
		return (ft_lstclear(&pile_a), 0);
	}
	while (1)
}
