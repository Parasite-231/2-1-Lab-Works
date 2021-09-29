#include<stdio.h>
int main()
{
    int n, i ;
    int a[100], w[100] ;
    printf("Enter number of students : ");
    scanf("%d",&n) ;

    for( i = 1 ; i <= n ; i++)
    {
        printf("Student %d age and weight : ",i) ;

        scanf("%d %d", &a[i],&w[i]);
    }

    for( i = 1 ; i <= n ; i++)
    {

        printf("Student %d age  is %d and weight is %d\n",i,a[i],w[i]) ;
    }
}
