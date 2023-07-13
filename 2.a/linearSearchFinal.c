/*
2.Implement the following searching algorithms and perform their analysis by 
generating best case and worst case data.
a) Sequential Search */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int linearSearch(int arr[], int val, int length)
{
   int count = 0, found = 0;
   for (int i = 0; i < length; i++)
   {
      count++;
      if (arr[i] == val)
      {
         // printf("Element %d found at index %d\n",val,i);
         return count;
      }
   }
   // printf("Element %d not found\n",val);
   return count;
}

void main()
{
   srand(time(NULL));
   int x, size = 1, key = 0;
   FILE *fptr = fopen("timingLinear.txt", "w");
   while (size < 40000)
   {
      if (size < 10000) size *= 10;
      else size *= 2;

      int *arr = (int *)malloc(sizeof(int) * size);
      for (int i = 0; i < size; i++)
      {
         arr[i] = rand();
      }
      
      // BEST CASE
      x = linearSearch(arr, arr[0], size);
      // printf("BEST CASE: Linear search took %d counts \n", x);
      fprintf(fptr, "%d\t%d\t", size, x);

      // AVG CASE
      x = linearSearch(arr, arr[size / 2], size);
      // printf("AVG CASE: Binary search took %d \n", x);
      fprintf(fptr, "%d\t%d\t", size, x);

      // WORST CASE
      x = linearSearch(arr, arr[size - 1], size);
      // printf("WORST CASE: Linear search took %d counts \n", x);
      fprintf(fptr, "%d\t%d\n", size, x);
   }
   fclose(fptr);
}
