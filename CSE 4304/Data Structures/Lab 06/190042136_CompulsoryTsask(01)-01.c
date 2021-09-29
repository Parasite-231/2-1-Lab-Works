#include <stdio.h>

void printInsertedValues(long list[], long n)
{
  long c, d, t;
  for (c = 0; c < n; c++)
     printf("%ld\n", list[c]);


}

int main()
{
  long array[100], n, c , d, t;

  printf("Enter number of elements\n");
  scanf("%ld", &n);

  printf("Enter %ld integers\n", n);

  for (c = 0; c < n; c++)
    scanf("%ld", &array[c]);

  //bubble_sort(array, n);

  printf("Sorted list in ascending order:\n");
  for (c = 0 ; c < n - 1; c++) {
    for (d = 0 ; d < n - c - 1; d++) {
      if (array[d] > array[d+1]) {
        /* Swapping */
        t         = array[d];
        array[d]   = array[d+1];
        array[d+1] = t;
      }
    }
  }


  /*for (c = 0; c < n; c++)
     printf("%ld\n", array[c]);*/

  printInsertedValues(array, n);

  return 0;
}

