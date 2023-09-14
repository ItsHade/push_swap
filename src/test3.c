#include "../include/push_swap.h"

void ft_changetab(int tab[], int size)
{
    int i;

    i = 0;
    while (i < size)
    {
        tab[i] = 0;
        i++;
    }
}

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

int main(void)
{
    int tab[] = {12, 4, 124, 98, 32};
    int size = (sizeof(tab) / sizeof(tab[0]));
    
    printArray(tab, size);
    ft_changetab(tab, size);
    printArray(tab, size);
}