/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maburnet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 13:42:46 by maburnet          #+#    #+#             */
/*   Updated: 2023/10/03 17:12:41 by maburnet         ###   ########.fr       */
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

/* GET NEXT LINE */

char	*get_next_line(int fd, int *nb_bytes);

char	*ft_strjoin(char *stash, char *buff);

char	*ft_strjoin2(char *ptr, char *s1, char *s2);

/* PUT Functions */

void	ft_putchar(char c);

void	ft_putstr(char *str);

void	ft_putstr_fd(char *str, int fd);

void	ft_putnbr(int nb);

/* CHECK ARGS */

int		ft_is_num(char *s);

int		ft_check_splitted(char **strs, t_pile **pile_a);

int		ft_check_dup(t_pile **pile_a);

int		ft_valid_args(char **argv, t_pile **pile_a);

/* SPLIT */

int		ft_wordcount(char *s, char c);

int		ft_getwordlen(char *s, char c, int i);

void	ft_freemalloc(char **strs, int a);

char	**ft_split(char const *s, char c);

void	ft_bzero(void *s, size_t n);

void	*ft_calloc(size_t nmemb, size_t size);

/* LIST */

t_pile	*ft_lstnew(int nb);

t_pile	*ft_lstlast(t_pile *lst);

void	ft_lstadd_back(t_pile **lst, t_pile *new);

void	ft_lstclear(t_pile **lst);

int		ft_lstsize(t_pile *lst);

/* UTILS */

int		ft_strlen(char *s);

void	ft_freesplit(char **strs);

long	ft_atol(char *s);

int		ft_abs(int nb);

/* MOVES */

void	do_sa(t_pile **pile_a);

void	do_sb(t_pile **pile_b);

void	do_ss(t_pile **pile_a, t_pile **pile_b);

void	do_pa(t_pile **pile_a, t_pile **pile_b);

void	do_pb(t_pile **pile_a, t_pile **pile_b);

void	do_ra(t_pile **pile_a);

void	do_rb(t_pile **pile_b);

void	do_rr(t_pile **pile_a, t_pile **pile_b);

void	do_rra(t_pile **pile_a);

void	do_rrb(t_pile **pile_b);

void	do_rrr(t_pile **pile_a, t_pile **pile_b);

#endif
