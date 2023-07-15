#include "../include/push_swap.h"

pile *ft_lstnew(int nb)
{
    pile *new;

    new = malloc(sizeof(pile));
    if (!new)
        return (NULL);
    new->nb = nb;
    new->next = NULL;
    return (new);
}

pile *ft_lstlast(pile *lst)
{
    if (lst == NULL || lst->next == NULL)
        return (lst);
    while (lst->next != NULL)
    {
        lst = lst->next;
    }
    return (lst);
}

void ft_lstadd_back(pile **lst, pile *new)
{
    pile *cur;

    cur = *lst;
    if (lst != NULL && *lst != NULL)
    {
        cur = ft_lstlast(*(lst));
        cur->next = new;
        return;
    }
    *lst = new;
}

void ft_lstadd_front(pile **lst, pile *new)
{
    pile *tmp;

    tmp = *lst;
    *lst = new;
    new->next = tmp;
}

// void ft_lstdelone(pile *lst)
// {
//     lst->nb = NULL;
//     if (lst != NULL)
//         free(lst);
// }

void ft_lstclear(pile **lst)
{
    pile *tmp;
    pile *start;

    start = *lst;
    while (start)
    {
        tmp = start->next;
        start->nb = 0;
        free(start);
        start = tmp;
    }
    *lst = NULL;
}

int ft_lstsize(pile *lst)
{
    size_t i;

    i = 0;
    while (lst)
    {
        lst = lst->next;
        i++;
    }
    return (i);
}