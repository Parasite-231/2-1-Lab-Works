#include <stdio.h>
#include <stdlib.h>


struct node
{
    int data;
    struct node * lNode, * rNode;
};


//here, node is created for the BST
struct node * newNode(int value)
{
    struct node * temp = (struct node *) malloc(sizeof(struct node));
    //void pointer
    temp -> data = value;
    temp -> lNode = NULL;
    temp -> rNode = NULL;
    return temp;
}


//insert function implemented
struct node * insert(struct node* rootNode, int value)
{
    // counting the number of operations during the insertion of node
    int numOfOperations = 0;

    struct node* newnode = newNode(value);
    struct node* r = rootNode;
    struct node* temp = NULL;

    // if root node is NULL, then the new node is the root of the BST
    if(r == NULL)
    {
        printf("Number of Operations: %d \n", numOfOperations);
        return newnode;
    }

    // finding the parent node where new node would be inserted
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

    //temp - immediate parent
    if (value < temp->data)
        temp->lNode = newnode;
    else
        temp->rNode = newnode;

    ++numOfOperations;

    printf("Number of Operations needed to insert the new value: %d \n", numOfOperations);

    return temp;
}


// delete function implemented
struct node * delete(struct node * root, int value)
{
    if (root == NULL) //base condition
        return root;

    // if the current node is equal to the deleted value
    if(root->data == value)
    {
        struct node *temp = root->rNode;

        //predicissor 
        if(temp == NULL)//check rt. subtree exist  or not
            return root->lNode;

        //inorder-successor--> parent er right-subtrree er smallest value findout kora->right subtree node thaakle
        while(temp->lNode != NULL)
            temp = temp->lNode;

        root->data = temp->data;//inorder succuessor assign


        root->rNode = delete(root->rNode, temp->data);
    }
    //to traverse right and left subtree based on condition

    // if the current node-->(root node) is smaller than the deleted value
    //root right side

    else if(root->data < value)
    {
        root->rNode = delete(root->rNode, value);
    }

    // if the current node is greater than the deleted value
    //root left side
    else
        root->lNode = delete(root->lNode, value);

    return root; //return tree root if root tree delete then new root

}

// in-order-traversal of the BST
void inorder(struct node * root)
{
    //l -> root->right

    if(root == NULL) //base condition
        return;

    inorder(root->lNode);
    printf("%d ", root->data);
    inorder(root->rNode);

    //postorder
    // l->r-> root
    postorder(root->lNode);
    postorder(root->rNode);
    printf("%d ", root->data);
  
    // root -> l- > right
     printf("%d ", root->data);
    preorder(root->lNode);
    preorder(root->rNode);
   
  

}


int main()
{

    int n, value, deletenode;
    struct node * root = NULL;

    printf("The number of Nodes to be inserted: ");
    scanf("%d", &n);

    scanf("%d", &value);
    root = insert(root, value);
    printf("Node : %d is inserted\n", value);

    for (int i = 2; i <= n; i++)
    {
        scanf("%d", &value);
        insert(root, value);
        printf("Node : %d is inserted\n", value);
    }

    printf("The desired BST is implemented \n");

    printf("\n");

    printf("The in-order Traversal : ");
    inorder(root);

    printf("\n");

    printf("Remove the node : ");

    scanf("%d", &deletenode);
    root = delete(root, deletenode);

    printf("\n");

    printf("The in-order Traversal after deletion of node : ");
    inorder(root);

    printf("\n");

    return 0;
}
