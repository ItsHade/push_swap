#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#include <unistd.h>
#include <stdlib.h>
#include <stddef.h>
#include <limits.h>
//
#include <stdio.h>

typedef struct t_pile
{
   int nb;
   struct t_pile *next;
} pile;

int ft_valid_args(char **argv);

int ft_is_num(char *s);

int ft_atoi(char *s, int *res);

void ft_putnbr(int nb);

int ft_strint_cmp(char *s1, char *s2);

void ft_putchar(char c, int fd);

void ft_putstr(char *str, int fd);

int ft_strlen(char *s);

pile *ft_lstnew(int nb);

pile *ft_lstlast(pile *lst);

void ft_lstadd_back(pile **lst, pile *new);

void ft_lstadd_front(pile **lst, pile *new);

void ft_lstdelone(pile *lst);

void ft_lstclear(pile **lst);

int ft_lstsize(pile *lst);

void ft_putlst(pile *lst);

void ft_lstswap(pile **pile);

pile *ft_lstcreate_a(void);

pile *ft_lstcreate_b(void);

void do_sa(pile **pile_a);

void do_sb(pile **pile_b);

void do_ss(pile **pile_a, pile **pile_b);

void do_pa(pile **pile_a, pile **pile_b);

void do_pb(pile **pile_a, pile **pile_b);

void ft_lstrotate(pile **Pile);

void do_ra(pile **pile_a);

void do_rb(pile **pile_b);

void do_rr(pile **pile_a, pile **pile_b);

void ft_lst_reverse_rotate(pile **Pile);

void do_rra(pile **pile_a);

void do_rrb(pile **pile_b);

void do_rr(pile **pile_a, pile **pile_b);
#endif