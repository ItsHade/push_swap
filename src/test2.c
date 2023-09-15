
#include "../include/push_swap.h"



// already have
void printList(t_pile *stack)
{
    int element;
    t_pile *current;

    element = 0;
    current = stack;
    while (current != NULL)
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

int ft_lstindex(t_pile **stack, long int last)
{
    t_pile *current;
    t_pile *min_element;
    long int min;
    static int i = 0;

    if (*stack == NULL)
        return (0);
    current = *stack;
    min = 2147483648;
    min_element = *stack;
    while (current != NULL)
    {
        if (current->nb < min && current->nb > last)
        {
            min_element = current;
            min = current->nb;
        }
        current = current->next;
    }
    min_element->index = i;
    i++;
    return (min);
}

int lstMaxIndex(t_pile *stack)
{
    int max;

    max = stack->index;
    while (stack != NULL)
    {
        if (stack->index > max)
            max = stack->index;
        stack = stack->next;
    }
    return (max);
}

// too long -> divide in multiple functions
void lstCountingSort(t_pile **stack, t_pile **stack2, int size, int place, int max)
{
    int i;
    int a;
    int output[size + 1];
    int count[max];
    t_pile *current;

    current = *stack;
    i = 0;
    while (i < max)
    {
        count[i] = 0;
        i++;
    }
    printArray(count, max);
    while (current != NULL)
    {
        count[(current->index / place) % 10]++;
        current = current->next;
    }
    printArray(count, max);
    i = 1;
    while (i < 10)
    {
        count[i] += count[i - 1];
        i++;
    }
    printArray(count, max);
    // maybe change that to do from bottom to top of list instead of top to bottoms
    i = size - 1;
    while (i >= 0)
    {
        current = *stack;
        a = 0;
        while (a < i)
        {
            current = current->next;
            a++;
        }
        output[count[(current->index / place) % 10] - 1] = current->index;
        count[(current->index / place) % 10]--;
        i--;
    }
    ft_putstr("Avant boucle finale: \n", 1);
    ft_putstr("stack:\n", 1);
    printList(*stack);
    ft_putstr("output: ", 1);
    printArray(output, size);
    ft_putstr("count: ", 1);
    printArray(count, max);
    i = 0;
    while (*stack != NULL)
    {
        //can optimise to rotate in the way wich there is less rotate instructions to get to  == output[i]
        while ((*stack)->index != output[i])
        {
            do_ra(stack);
        }
        do_pb(stack, stack2);
        i++;
    }
    while (*stack2 != NULL)
    {
        do_pa(stack, stack2);
    }
    ft_putstr("stack after: ", 1);
    printList(*stack);
}

void ft_addIndex(t_pile **pile_a, int size)
{
    long int min;
    int i;

    min = -2147483649;
    i = 0;
    while (i < size)
    {
        //replace by ft_getmin
        min = ft_lstindex(pile_a, min);
        i++;
    }


}

void lstradixsort(t_pile **stack, t_pile **stack2, int size)
{
    int place;
    int max;

    place = 1;
    ft_addIndex(stack, size);
    max = lstMaxIndex(*stack);
    ft_putstr("max: ", 1);
    ft_putnbr(max);
    ft_putchar('\n', 1);
    while (max / place > 0)
    {
        ft_putstr("\nplace: ", 1);
        ft_putnbr(place);
        ft_putchar('\n', 1);
        lstCountingSort(stack, stack2, size, place, 10);
        place *= 10;
    }
}

// delete
t_pile *ft_lstcreate(char **argv)
{
    t_pile *testPile;
    int i;

    i = 1;
    testPile = ft_lstnew(ft_atol(argv[i]));
    i++;
    while (testPile != NULL && argv[i] != NULL)
    {
        ft_lstadd_back(&testPile, ft_lstnew(ft_atol(argv[i])));
        i++;
    }
    // ft_putstr("Finished creating the linked list!\n", 1);
    return (testPile);
}

int main(int argc, char **argv)
{
    t_pile *stack;
    t_pile *stack2;
    int size;

    if (argc < 2)
        return (0);
    stack = ft_lstcreate(argv);
    stack2 = NULL;
    size = ft_lstsize(stack);
    lstradixsort(&stack, &stack2, size);
    ft_putstr("\n========LIST========\n", 1);
    ft_putstr("size: ", 1);
    ft_putnbr(size);
    ft_putchar('\n', 1);
    ft_putchar('\n', 1);
    ft_putstr("stack 1: \n", 1);
    printList(stack);
    ft_putstr("stack 2: \n", 1);
    printList(stack2);
    ft_lstclear(&stack);
    ft_lstclear(&stack2);
}