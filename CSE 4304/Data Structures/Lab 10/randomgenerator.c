#include <stdio.h>
#include<time.h>
#include <stdlib.h>

int main() {
    long int randomNumber;
    srand(time(NULL));



    for (randomNumber = 1; randomNumber <= 100; randomNumber++){


         printf("%d\n", rand());

    }


}
