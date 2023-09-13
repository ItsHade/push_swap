
#include "../include/push_swap.h"

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

// Using counting sort to sort the elements in the basis of significant places
void countingSort(int array[], int size, int place) 
{
    int i;
    int output[size + 1];
    int max = (array[0] / place) % 10;

    i = 1;
    while (i < size)
    {
        if (((array[i] / place) % 10) > max)
            max = array[i];
        i++;
    }

    int count[max + 1];
    i = 0;
    while (i < max)
    {
        count[i] = 0;
        ++i;
    }

    // Calculate count of elements
    i = 0;
    while (i < size)
    {
        count[(array[i] / place) % 10]++;
        i++;
    }
        
    // Calculate cumulative count
    i = 1;
    while (i < 10)
    {
        count[i] += count[i - 1];
        i++;
    }

    // Place the elements in sorted order
    i = size - 1;
    while (i >= 0)
    {
        output[count[(array[i] / place) % 10] - 1] = array[i];
        count[(array[i] / place) % 10]--;
        i--;
    }
    i = 0;
    while (i < size)
    {
        array[i] = output[i];
        i++;
    }
}

// Main function to implement radix sort
void radixsort(int array[], int size) 
{
    int place;
    // int max;

    place = 1;
    // Get maximum element
    int max = getMax(array, size);
    // max = lstMax(stack);

    // Apply counting sort to sort elements based on place value.
    while (max / place > 0 )
    {
        countingSort(array, size, place);
        place *= 10;
    }
}
/*
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
*/
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

t_pile *ft_lstcreate(void)
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

// Driver code
int main() 
{
    t_pile *stack;
    int size;

    int array[] = {121, 432, 564, 23, 1, 45, 788};
    int n = sizeof(array) / sizeof(array[0]);
    stack = ft_lstcreate();
    size = ft_lstsize(stack);
    radixsort(array, n);
    // printArray(array, n);
    printList(stack);
    ft_lstclear(&stack);
}
