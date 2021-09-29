#include<stdio.h>

int add(long long int , long long int ) ;

int main (){

    long long int a , b , sum;
    scanf("%lld",&a) ;
    scanf("%lld",&b) ;

    sum = add(a,b) ;
    printf("%d\n",sum) ;

}

int add(long long int x, long long int y){
    int addition ;
    addition = x + y ;
    return addition;
}

