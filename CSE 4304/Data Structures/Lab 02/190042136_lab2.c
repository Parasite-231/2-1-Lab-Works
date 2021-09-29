//Function 1
#include<stdio.h>

/*void display(int *array , int numberOfAges)
{
    for ( int i = 0 ; i < numberOfAges ; i++)
    {
        printf("Ages : %d\n",*(array+i)) ;
    }

}


int main()
{
    int students[100] , n ;
    printf("Enter number of students: ") ;
    scanf("%d",&n) ;
    printf("Enter ages of students: ") ;
    for( int i = 0 ; i < n ; i++)
    {
        scanf("%d",&students[i]) ;
    }
    int size = sizeof(students)/sizeof(students[0]) ;
    display(students,size) ;
}
*/

//Function 2

/*int updateAge(int *array, int modifiedIndex, int numberOfAges)
{

    if ( modifiedIndex >= numberOfAges)
        return -1 +--+;

    printf("Enter the modified age : ") ;
    scanf("%d",&array[modifiedIndex-1]) ;
    printf("%d",array[modifiedIndex-1]) ;



}

int main()
{
    int students[100] ,index, n ;
    printf("Enter number of students: ") ;
    scanf("%d",&n) ;

    for( int i = 0 ; i < n ; i++)
    {
        printf("Enter ages of student no. %d: ",i+1) ;
        scanf("%d",&students[i]) ;
    }
    printf("Enter the modified index to change age : ") ;
    scanf("%d",&index) ;

    int size = sizeof(students)/sizeof(students[0]) ;
    updateAge(students,index,size) ;

}
*/


//Function 3

/*int sortAge(int *array, int sizeOfArray)
{
    int temporaryValue, i, j;

    for(i=0; i<sizeOfArray-1; i++)
    {
        for(j=0; j<sizeOfArray-i-1; j++)
        {
            if(array[j]>array[j+1])
            {
                temporaryValue = array[j];
                array[j] = array[j+1];
                array[j+1] = temporaryValue;
            }
        }
    }
    for(i=0; i<sizeOfArray-1; i++)
    {
        if(array[i]>array[i+1] )
            return -1;

    }
    return 0 ;
}

int main()
{
    int students[100],index, n ;
    printf("Enter number of students: ") ;
    scanf("%d",&n) ;

    for( int i = 0 ; i < n ; i++)
    {
        printf("Enter ages of student no. %d: ",i+1) ;
        scanf("%d",&students[i]) ;
    }
    int size = sizeof(students)/sizeof(students[0]) ;
    //sortAge(students,size);
    int decision = sortAge(students,size) ;
    printf("Ages in sorted manner: %d",decision) ;

}
*/

//Function 4


int indexSearch(int *array, int searchAge, int numberOfAges)
{

    int i, low, high, mid, j, temporaryValue ;

    for(i = 0; i < numberOfAges - 1; i++)
    {
        for(j = 0; j < numberOfAges - i - 1 ; j++)
        {
            if(array[j]>array[j+1])
            {
                temporaryValue = array[j];
                array[j] = array[j+1];
                array[j+1] = temporaryValue;
            }
        }
    }

    low = 0;
    high = numberOfAges - 1;
    mid = (low+high)/2;
    while (low <= high )
    {
        if(array[mid] < searchAge)
            low = mid + 1;
        else if (array[mid] == searchAge)
        {
            printf("Search aged %d found at location %d", searchAge, mid+1);
            break;
        }
        else
            high = mid - 1;
        mid = (low + high)/2;
    }
    if(low > high)
    {
        printf("Not found! %d isn't present in the list", searchAge);
    }


}

int main()
{

    int students[100], i, n, age;
    printf("Enter the number of students : ") ;
    scanf("%d",&n) ;
    for( i = 0 ; i < n ; i++)
    {
        printf("Age of no. %d student : ",i+1);
        scanf("%d",&students[i]) ;
    }
    //int size = sizeof(students)/sizeof(students[0]) ;
    int size = n ;
    printf("\n") ;
    printf("Type the seraching age : ");
    scanf("%d",&age) ;


    indexSearch(students,age, size);

}
