#include <bits/stdc++.h>
using namespace std;
int main()
{

    int numberOfVertices, x, y, numberOfEdges;
    cin>> numberOfVertices>>numberOfEdges;
    int adjacencyMatrix[numberOfVertices][numberOfVertices];

    for(int i=0; i < numberOfVertices; i++)
    {
        for(int j=0; j < numberOfVertices; j++)
            adjacencyMatrix[i][j]=0;
    }

    for(int i=0; i < numberOfEdges; i++)
    {
        cin>> x>> y;
        adjacencyMatrix[x][y]=1;
        adjacencyMatrix[x][y]=1;
    }


    for(int i=0; i < numberOfVertices; i++)
    {
        for(int j=0; j < numberOfVertices; j++){

            cout<<adjacencyMatrix[i][j];
        }

    }

    return 0;
}

