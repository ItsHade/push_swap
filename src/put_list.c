#include "../include/push_swap.h"

//below are not usefull functions in the final build

// not needed int final build
void ft_putarray(int array[], int size)
{
    int i;

    i = 0;
    while (i < size)
    {
        ft_putnbr(array[i]);
        ft_putchar(' ', 1);
        i++;
    }
    ft_putchar('\n', 1);
}

void ft_putlst(t_pile *lst)
{
    int element;
    t_pile *current;

    element = 0;
    current = lst;
    while(current != NULL)
    {
        ft_putstr("Element ", 1);
        ft_putnbr(element);
        ft_putstr(": ", 1);
        ft_putnbr(current->nb);
        ft_putstr(" index: ", 1);
        ft_putnbr(current->index);
        ft_putchar('\n', 1);
        current = current->next;
        element++;
    }
}

t_pile *ft_lstcreate_b(void)
{
    t_pile *testPile;
    char c;

    c = 'A';
    testPile = ft_lstnew(c);
    c++;
    while (testPile != NULL && c <= 'Z')
    {
        ft_lstadd_back(&testPile, ft_lstnew(c));
        c++;
    }
    ft_putstr("Finished creating the linked list!\n", 1);
    return (testPile);
}

t_pile *ft_lstcreate_a(void)
{
    t_pile *testPile;
    char c;

    c = 'a';
    testPile = ft_lstnew(c);
    c++;
    while (testPile != NULL && c <= 'z')
    {
        ft_lstadd_back(&testPile, ft_lstnew(c));
        c++;
    }
    ft_putstr("Finished creating the linked list!\n", 1);
    return (testPile);
}
