#include "../include/push_swap.h"

typedef struct s_stack{
    int *tab_a;
    int *tab_b;
    int size_a;
    int size_b;
    int size_max;
} t_stack;

void ft_putinttab(int *tab, int size)
{
    int i;

    i = 0;
    while (i < size)
    {
        ft_putchar('[', 1);
        ft_putnbr(tab[i]);
        ft_putchar(']', 1);
        i++;
    }
    ft_putchar('\n', 1);
}

int *ft_swaptab(int *tab, int size)
{
    int tmp;

    if (size < 2)
        return (tab);
    tmp = tab[0];
    tab[0] = tab[1];
    tab[1] = tmp;
    return (tab);
}

int *ft_rotatetab(int *tab, int size)
{
    int i;
    int tmp;
    int tab_tmp[size];

    i = 0;
    tmp = tab[0];
    while (i < size - 1)
    {
        tab_tmp[i] = tab[i + 1];
        i++;
    }
    i = 0;
    while (i < size)
    {
        tab[i] = tab_tmp[i];
        i++;
    }
    tab[size - 1] = tmp;
    return (tab);
}
//from a to b
//decaler tout de 1 en b si besoin
//puis push a vers b
//puis decaler tout de a
int ft_pushtab(t_stack *stack)
{
    int i;

    i = stack->size_b;
    if (stack->size_a == 0)
        return (-1);
    while (i > 0)
    {
        stack->tab_b[i] = stack->tab_b[i - 1];
        i--;
    }
    stack->tab_b[0] = stack->tab_a[0];
    i = 0;
    while (i < stack->size_a && i < stack->size_max - 1)
    {
        stack->tab_a[i] = stack->tab_a[i + 1];
        i++;
    }
    stack->tab_a[i] = 0; //not optimal to do it that way but don't have the choice
    stack->size_b++;
    stack->size_a--;
    // ft_putstr("manual: ", 1);
    // ft_putnbr(stack->tab_a[stack->size_a]);
    // ft_putnbr(stack->tab_a[stack->size_a - 1]);
    // ft_putnbr(stack->tab_a[stack->size_a - 2]);
    // ft_putnbr(stack->tab_a[stack->size_a - 3]);
    // ft_putnbr(stack->tab_a[stack->size_a - 4]);
    // ft_putnbr(stack->tab_a[stack->size_a - 5]);
    // ft_putchar('\n', 1);
    return (0);
}

void ft_puttabs(t_stack stack)
{
    ft_putstr("tab A: ", 1);
    ft_putinttab(stack.tab_a, stack.size_a);
    ft_putchar('\n', 1);
    ft_putstr("tab B: ", 1);
    ft_putinttab(stack.tab_b, stack.size_b);
    ft_putchar('\n', 1);
}

// you need to check manualy if there is a zero or not because you can't set a tab[index] to null or you need to re create the tab and re malloc
int main(int argc, char **argv)
{
    t_stack stack;

    if (argc < 2)
        return (-1);
    stack.size_max = 7;
    stack.size_a = stack.size_max;
    stack.size_b = 0;
    stack.tab_a = malloc(sizeof(int) * stack.size_max);
    if (!stack.tab_a)
        return (-1);
    stack.tab_b = malloc(sizeof(int) * stack.size_max);
    if (!stack.tab_b)
        return (-1);
    stack.tab_a[0] = 2;
    stack.tab_a[1] = 1;
    stack.tab_a[2] = 3;
    stack.tab_a[3] = 6;
    stack.tab_a[4] = 5;
    stack.tab_a[5] = 8;
    stack.tab_a[6] = 7;
    

    ft_putnbr(ft_atoi(argv[1]));
    ft_putchar('\n', 1);
    ft_puttabs(stack);
    //test swap
    ft_putstr("SWAPING\n", 1);
    stack.tab_a = ft_swaptab(stack.tab_a, stack.size_a);
    ft_puttabs(stack);
    //test rotate
    ft_putstr("ROTATING\n", 1);
    stack.tab_a = ft_rotatetab(stack.tab_a, stack.size_a);
    ft_puttabs(stack);
    //test push
    while (stack.size_a > 0)
    {
        ft_putstr("PUSHING\n", 1);
        ft_pushtab(&stack);
        ft_puttabs(stack);
    }
    ft_putstr("PUSHING\n", 1);
    ft_pushtab(&stack);
    ft_puttabs(stack);
    return (free(stack.tab_a), free(stack.tab_b), 0);
}



//Main used to individually test the different rule fonctions [for linked lists]

// int main(int argc, char **argv)
// {
//     t_pile *pile_a;
//     t_pile *pile_b;
//     int i;
    
//     if (argc < 3)
//         return (0);
//     pile_a = ft_lstcreate_a();
//     pile_b = ft_lstcreate_b();
//     i = 0;
//     ft_putlst(pile_a);
//     ft_putstr("Finished printing pile_a!\n", 1);
//     ft_putlst(pile_b);
//     ft_putstr("Finished printing pile_b!\n", 1);
//     ft_lstswap(&pile_a);
//     ft_putstr("SWAPED!\n", 1);
//     ft_putlst(pile_a);
//     do_pa(&pile_a, &pile_b);
//     ft_putlst(pile_a);
//     ft_putstr("Finished printing pile_a!\n", 1);
//     ft_putlst(pile_b);
//     ft_putstr("Finished printing pile_b!\n", 1);
//     ft_putstr("Rotating pile_b\n", 1);
//     while (i++ < 5)
//         do_rb(&pile_b);
//     ft_putlst(pile_b);
//     i = 0;
//     while (i++ < 5)
//         do_rra(&pile_a);
//     ft_putlst(pile_a);
//     ft_lstclear(&pile_a);
//     ft_lstclear(&pile_b);
//     return (0);
// }