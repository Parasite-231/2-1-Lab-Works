#include <stdio.h>
#include <stdlib.h>
#include<time.h>

struct node
{
    int data;
    struct node * lNode, * rNode;
};

// A new node is created here
struct node * newNode(int value)
{
    struct node * temp = (struct node * ) malloc(sizeof(struct node));
    temp -> data = value;
    temp -> lNode = NULL;
    temp -> rNode = NULL;
    return temp;
}

//A new node is inserted here
struct node * insert(struct node* rootNode, int value)
{
    // Count the number of operations during the insertion
    int numOfOperations = 0;

    struct node* newnode = newNode(value);
    struct node* r = rootNode;
    struct node* temp = NULL;

    // If root node is NULL, then the new node is the root of the BST
    if(r == NULL)
    {
        printf("%d\n", numOfOperations);
        return newnode;
    }

    // Find the new root node after the insertion
    do
    {
        temp = r;
        if (value < r->data)
            r = r->lNode;
        else
            r = r->rNode;

        ++numOfOperations;

    }
    while (r != NULL);


    if (value < temp->data)
        temp->lNode = newnode;
    else
        temp->rNode = newnode;

    ++numOfOperations;

    printf("%d\n", numOfOperations);

    return temp;
}

// In-order-traversal of the BST
void inorder(struct node * root)
{

    if(root == NULL)
        return;

    inorder(root->lNode);
    printf("%d ", root->data);
    inorder(root->rNode);

}


int main()
{

    // Question 2
    printf("Inserting 100 random element in the BST \n");
    struct node * root = NULL;
    int randContainer[100];
    srand(time(0));
    //always start with zero, why??????????
    for(int i = 0; i<100; i++)
        randContainer[i] = rand();

    printf("Number of operations for each insertion: \n");
    root = insert(root, randContainer[0]);
    for(int i = 1; i<100; i++)
    {
        insert(root, randContainer[i]);
    }

    return 0;
}
