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
	int				pos;
	int				cost_to_pos_a;
	int				cost_to_top_b;
	struct s_pile	*next;
}	t_pile;

/* SORT */

void	ft_sort(t_pile **pile_a, t_pile **pile_b, int size);

void	ft_put_index_zero_top(t_pile **pile_a, int size);

int		ft_get_index_zero_pos(t_pile **pile_a);

void	ft_sort3(t_pile **pile_a);

void	ft_initiate_sorting(t_pile **pile_a, t_pile **pile_b, int size);

/* DO MOVE */

void	ft_do_best(t_pile **pile_a, t_pile **pile_b);

int		ft_get_cost_b_of_index(t_pile **pile_b, int best_index);

int		ft_get_cost_a_of_index(t_pile **pile_b, int best_index);

int		ft_get_index_of_best(t_pile **pile_a, t_pile **pile_b);

/* GET COST*/

void	ft_get_cost(t_pile **pile_a, t_pile **pile_b);

int		ft_get_cost_b(t_pile *element_b, int size);

int		ft_get_cost_a(t_pile **pile_a, t_pile *elem_b, int min, int max);

int		ft_get_min_index(t_pile *pile_a);

int		ft_get_max_index(t_pile *pile_a);

/* SORT UTILS */

void	ft_get_pos(t_pile **pile);

int		ft_get_last_index(t_pile **pile_a);

int		ft_get_last_pos(t_pile **pile_a);

int		ft_first_is_lowest(t_pile **pile);

int		ft_calculate_move_cost(int pos_a, int pos_b);

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

/* SPLIT */

int		ft_wordcount(char *s, char c);

int		ft_getwordlen(char *s, char c, int i);

void	ft_freemalloc(char **strs, int a);

char	**ft_split(char const *s, char c);

/* PUT */

void	ft_putchar(char c);

void	ft_putstr(char *str);

void	ft_putstr_fd(char *str, int fd);

void	ft_putnbr(int nb);

/* */

int		ft_get_max_index(t_pile *pile_a);

int		ft_get_min(t_pile **pile_a, long int last);

void	ft_get_pos(t_pile **pile);

void	ft_put_index_zero_top(t_pile **pile_a, int size);

void	ft_addIndex(t_pile **pile_a, int size);

void	ft_push_swap(t_pile **stack_a, t_pile **stack_b, int size);

void	ft_sort(t_pile **stack_a, t_pile **stack_b, int size);

void	ft_sort3(t_pile **pile_a);
//
void	ft_putlst2(t_pile *lst);

void	ft_putlst3(t_pile *lst);

void	ft_putlst4(t_pile *lst);

int		ft_is_sorted2(t_pile *Pile);

void	ft_putlst_pos(t_pile *lst);

int		ft_is_sorted(t_pile *Pile);

void	ft_bzero(void *s, size_t n);

void	*ft_calloc(size_t nmemb, size_t size);

void	ft_radixsort(t_pile **pile_a, t_pile **pile_b, int size);

void	ft_freesplit(char **strs);

char	**ft_split(char const *s, char c);

int		ft_valid_args(char **argv, t_pile **pile_a);

int		ft_is_num(char *s);

long	ft_atol(char *s);

void	ft_putnbr(int nb);

int		ft_strint_cmp(char *s1, char *s2);

void	ft_putchar(char c);

void	ft_putstr(char *str);

void	ft_putstr_fd(char *str, int fd);

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

void	do_rra(t_pile **pile_a);

void	do_rrb(t_pile **pile_b);

void	do_rrr(t_pile **pile_a, t_pile **pile_b);

void	ft_lst_reverse_rotate(t_pile **t_pile);



#endif
