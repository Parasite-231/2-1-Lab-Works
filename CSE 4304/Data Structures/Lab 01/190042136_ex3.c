#include<stdio.h>
int max(int num1, int num2 ) ;
int main ()
{
    int a, b, ret  ;
    printf("Enter number 1: ");
    scanf("%d",&a);
    printf("Enter number 2: ") ;
    scanf("%d",&b) ;
    ret = max( a, b ) ;
    printf("Max value is : %d\n", ret) ;
}

int max(int num1, int num2 )
{
    int result ;
    if (num1 > num2 )
        result = num1 ;
    else
        result = num2 ;
    return result ;

}
