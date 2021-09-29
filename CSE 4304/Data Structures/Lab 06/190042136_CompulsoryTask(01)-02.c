#include<stdio.h>

int binarySearching(int * arr, int n, int size) {

    int i, low, high, mid, j, temporaryValue ;

    for(i = 0; i < size - 1; i++)
    {
        for(j = 0; j < size - i - 1 ; j++)
        {
            if(arr[j]>arr[j+1])
            {
                temporaryValue = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temporaryValue;
            }
        }
    }

    low = 0;
    high = size - 1;
    mid = (high - low) / 2;
    while (low <= high )
    {
        if(arr[mid] < n)
            low = mid + 1;
        else if (arr[mid] == n)
        {
            return 1;
        }
        else
            high = mid - 1;
        mid = low + (high - low) / 2;
    }
    if(low > high)
    {
        return -1;
    }
}

    int main() {
      int arr[101], i, x, search, no;
      printf("please enter the total number of integers you want to store in the array :\n ");
      scanf("%d", & x);
      printf("please enter your integers-->\n");
      for (i = 0; i < x; i++) {

        printf("enter %d number = ", i + 1);
        scanf("%d", & arr[i]);
      }
      printf("please enter the number you want to search in your array in binary algorithm--->\n");
      scanf("%d", & no);
      int s = sizeof(arr) / sizeof(arr[0]);
      search = binarySearching(arr, no, s);
      printf("%d", search);

    }
