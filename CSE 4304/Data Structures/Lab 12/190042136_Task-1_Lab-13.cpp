#include<iostream>
using namespace std;
char array[200][200];

int main()
{
    int numberOfNodes, numberOfEdges;
    char a, b ;
    cin >> numberOfEdges >> numberOfNodes;

    for(int i = 0 ; i < numberOfNodes ; i++)
    {
        for(int  j = 0 ; j < numberOfNodes ; j++)
        {
            array[i][j] = 'O';
        }

    }

    for(int i = 0 ; i < numberOfEdges ; i++)
    {
        cin >> a >> b ;
        int c, d;


        if(a == 'A')
            c = 0;
        else if(a == 'B')
            c = 1;
        else if(a == 'C')
            c = 2;
        else if(a == 'D')
            c = 3;
        else if(a == 'E')
            c = 4;
        else if(a == 'F')
            c = 5;

        if(b =='A')
            d = 0;
        else if(b =='B')
            d = 1;
        else if(b == 'C')
            d =2 ;
        else if(b == 'D')
            d = 3;
        else if(b == 'E')
            d = 4;
        else if(b == 'F')
            d = 5;

        array[c][d] = 'Y';

    }

    for(int i = 0; i < numberOfNodes ; i++)
    {
        for(int j = 0 ; j < numberOfNodes ; j++)
        {
            cout<<array[i][j]<<"    ";
        }


    }


}

