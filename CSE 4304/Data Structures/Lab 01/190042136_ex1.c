#include<stdio.h>
int main ()
{
    int age;
    printf("Enter your age: ") ;
    scanf("%d",&age) ;
    number(age) ;
}

void number(int old)
{
    printf("Your age : %d",old) ;
}
