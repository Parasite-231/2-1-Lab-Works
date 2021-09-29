#include<stdio.h>
int addition(int num1, int num2);
int main()
{
    int var1, var2, res;
    printf("Enter number 1: ");
    scanf("%d",&var1);
    printf("Enter number 2: ") ;

    scanf("%d",&var2) ;
    res = addition( var1, var2 ) ;
    printf("Output: %d", res) ;
}

int addition(int num1, int num2)
{
    int sum ;
    sum = num1 + num2 ;
    return sum ;

}
