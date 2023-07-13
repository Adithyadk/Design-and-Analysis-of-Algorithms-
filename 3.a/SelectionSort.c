/*
3.Implement the following elementary sorting algorithms and perform their analysis by 
generating best case and worst case data. (Note: Any two may be asked in the 
test/exam) 
a) Selection Sort */

#include <stdio.h>
#include <stdlib.h>

int SelectionSort(int a[], int n)
{
    int count = 0, min, temp;
    for (int i = 0; i < n - 1; i++)
    {
        min = i;
        for (int j = i + 1; j < n; j++)
        {
            count++;
            if (a[j] < a[min]) min = j;
        }
        temp = a[i];
        a[i] = a[min];
        a[min] = temp;
    }
    return count;
}

void main()
{
    int n = 1, count;
    FILE *fptr=fopen("data.txt", "w");
    while (n < 40000)
    {
        if (n < 10000) n *= 10;
        else n *= 2;
        int *a = (int *)malloc(sizeof(int) * n);
        for (int i = 0; i < n; i++)
        {
            a[i] = i;
        }
        count = SelectionSort(a, n);    
        fprintf(fptr, "%d\t%d\n", n, count);
    }
    fclose(fptr);
    system("gnuplot>load 'selection_plot.txt' ");
}