
#include "../include/push_swap.h"

// Print an array
void printArray(int array[], int size) 
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

void printList(t_pile *stack)
{
    while (stack != NULL)
    {
        ft_putnbr(stack->nb);
        ft_putchar(' ', 1);
        stack = stack->next;
    }
    ft_putchar('\n', 1);
}

// Function to get the largest element from an array
int getMax(int array[], int n)
{
    int max = array[0];
    int i;

    i = 1;
    while (i < n)
    {
        if (array[i] > max)
            max = array[i];
        i++;
    }
    return (max);
}

int lstMax(t_pile *stack)
{
    int max;

    max = stack->nb;
    while (stack != NULL)
    {
        if (stack->nb > max)
            max = stack->nb;
        stack = stack->next;
    }
    return (max);
}

void lstCountingSort(t_pile *stack, int size, int place, int max)
{
    int i;
    int a;
    int output[size + 1];
    int count[max];
    t_pile *current;
    
    current = stack;
    i = 0;
    while (i < max)
    {
        count[i] = 0;
        i++;
    }
    printArray(count, max);
    while (current != NULL)
    {
        count[(current->nb / place) % 10]++;
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

    i = size - 1;
    while (i >= 0) 
    {    
        current = stack;
        a = 0;
        while (a < i)
        {
            current = current->next;
            a++;
        }
        output[count[(current->nb / place) % 10] - 1] = current->nb;
        count[(current->nb / place) % 10]--;
        i--;
    }
    ft_putstr("Avant boucle finale: \n", 1);
    ft_putstr("stack: ", 1);
    printList(stack);
    ft_putstr("output: ", 1);
    printArray(output, size);
     ft_putstr("count: ", 1);
    printArray(count, max);
    current = stack;
    // change that to do from bottom to top of list instead of top to bottom
    while (current != NULL)
    {
        current->nb = output[i];
        current = current->next;
    }
    ft_putstr("stack after: ", 1);
    printList(stack);
}


// Using counting sort to sort the elements in the basis of significant places
void countingSort(int array[], int size, int place) 
{
    int i;
    int output[size + 1];
    int max = 10;

    int count[max];
    i = 0;
    while (i < max)
    {
        count[i] = 0;
        ++i;
    }
    printArray(count, max);
    // Calculate count of elements
    i = 0;
    while (i < size)
    {
        count[(array[i] / place) % 10]++;
        i++;
    }
    printArray(count, max);
    //
    // Calculate cumulative count
    i = 1;
    while (i < 10)
    {
        count[i] += count[i - 1];
        i++;
    }
    printArray(count, max);
    // Place the elements in sorted order
    i = size - 1;
    while (i >= 0)
    {
        output[count[(array[i] / place) % 10] - 1] = array[i];
        count[(array[i] / place) % 10]--;
        i--;
    }
    i = 0;
    ft_putstr("Avant boucle finale: \n", 1);
    ft_putstr("array: ", 1);
    printArray(array, size);
    ft_putstr("output: ", 1);
    printArray(output, size);
     ft_putstr("count: ", 1);
    printArray(count, max);
    while (i < size)
    {
        array[i] = output[i];
        i++;
    }
    ft_putstr("array after: ", 1);
    printArray(array, size);
}

// Main function to implement radix sort
void radixsort(int array[], int size) 
{
    int place;
    // int max;

    place = 1;
    // Get maximum element
    int max = getMax(array, size);


    // Apply counting sort to sort elements based on place value.
    while (max / place > 0 )
    {
        ft_putstr("\nplace: ", 1);
        ft_putnbr(place);
        ft_putchar('\n', 1);
        countingSort(array, size, place);
        place *= 10;
    }
}

void lstradixsort(t_pile *stack, int size)
{
    int place;
    int max;

    place = 1;
    max = lstMax(stack);
    while (max / place > 0)
    {
        ft_putstr("\nplace: ", 1);
        ft_putnbr(place);
        ft_putchar('\n', 1);
        lstCountingSort(stack, size, place, 10);
        place *= 10;
    }
}

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

// Driver code
int main(int argc, char **argv) 
{
    t_pile *stack;
    int size;

    if (argc < 2)
        return (0);
    int array[] = {121, 432, 564, 23, 1, 45, 788};
    int n = sizeof(array) / sizeof(array[0]);
    stack = ft_lstcreate(argv);
    size = ft_lstsize(stack);
    ft_putstr("\n========ARRAY========\n", 1);
    radixsort(array, n);
    ft_putchar('\n', 1);
    printArray(array, n);
    ft_putstr("\n========LIST========\n", 1);
    ft_putstr("size: ", 1);
    ft_putnbr(size);
    ft_putchar('\n', 1);
    lstradixsort(stack, size);
    ft_putchar('\n', 1);
    printList(stack);
    ft_lstclear(&stack);
}