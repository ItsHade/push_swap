#include "../include/push_swap.h"

void ft_putlst(pile *lst)
{
    int element;
    pile *current;

    element = 0;
    current = lst;
    while(current != NULL)
    {
        ft_putstr("Element ", 1);
        ft_putnbr(element);
        ft_putstr(": ", 1);
        ft_putnbr(current->nb);
        ft_putchar('\n', 1);
        current = current->next;
        element++;
    }
}

pile *ft_lstcreate_b(void)
{
    pile *testPile;
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

pile *ft_lstcreate_a(void)
{
    pile *testPile;
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