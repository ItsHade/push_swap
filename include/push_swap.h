/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maburnet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 20:12:30 by maburnet          #+#    #+#             */
/*   Updated: 2023/09/16 20:33:33 by maburnet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <stddef.h>
# include <limits.h>

typedef struct s_pile
{
	long			nb;
	int				index;
	struct s_pile	*next;
}	t_pile;

void	ft_bzero(void *s, size_t n);

void	*ft_calloc(size_t nmemb, size_t size);

void	ft_radixsort(t_pile **stack, t_pile **stack2);

void	ft_freesplit(char **strs);

char	**ft_split(char const *s, char c);

int		ft_valid_args(char **argv, t_pile **pile_a);

int		ft_is_num(char *s);

long	ft_atol(char *s);

void	ft_putnbr(int nb);

int		ft_strint_cmp(char *s1, char *s2);

void	ft_putchar(char c, int fd);

void	ft_putstr(char *str, int fd);

int		ft_strlen(char *s);

t_pile	*ft_lstnew(int nb);

t_pile	*ft_lstlast(t_pile *lst);

void	ft_lstadd_back(t_pile **lst, t_pile *new);

void	ft_lstadd_front(t_pile **lst, t_pile *new);

void	ft_lstdelone(t_pile *lst);

void	ft_lstclear(t_pile **lst);

int		ft_lstsize(t_pile *lst);

void	ft_putarray(int array[], int size);

void	ft_putlst(t_pile *lst);

void	ft_lstswap(t_pile **t_pile);

t_pile	*ft_lstcreate_a(void);

t_pile	*ft_lstcreate_b(void);

void	do_sa(t_pile **pile_a);

void	do_sb(t_pile **pile_b);

void	do_ss(t_pile **pile_a, t_pile **pile_b);

void	do_pa(t_pile **pile_a, t_pile **pile_b);

void	do_pb(t_pile **pile_a, t_pile **pile_b);

void	ft_lstrotate(t_pile **t_pile);

void	do_ra(t_pile **pile_a);

void	do_rb(t_pile **pile_b);

void	do_rr(t_pile **pile_a, t_pile **pile_b);

void	ft_lst_reverse_rotate(t_pile **t_pile);

void	do_rra(t_pile **pile_a);

void	do_rrb(t_pile **pile_b);

void	do_rr(t_pile **pile_a, t_pile **pile_b);

#endif
