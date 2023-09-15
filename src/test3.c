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

int main(void)
{
    int array[] = {121, 432, 564, 89, 23, 1, 45, 788};
    int n = sizeof(array) / sizeof(array[0]);

    radixsort(array, n);
    printArray(array, n);
}