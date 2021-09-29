#include <stdio.h>
#include <stdlib.h>

struct node {
    int key;
    struct node * leftChild, * rightChild;
};

//creation of node---------------->

struct node * newNode(int item) {
    struct node * temp = (struct node * ) malloc(sizeof(struct node)); //dynamically memory allocation
    temp -> key = item;
    temp -> leftChild = temp -> rightChild = NULL;
    return temp;
}

//insertion of node--------------->

struct node * insert(struct node * node, int key) {

    if (node == NULL)
        return newNode(key);

    if (key < node -> key)
        node -> leftChild = insert(node -> leftChild, key);
    else
        node -> rightChild = insert(node -> rightChild, key);

    return node;
}

struct node * minValueNode(struct node * node) {
    struct node * current = node;

    while (current && current -> leftChild != NULL)
        current = current -> leftChild;

    return current;
}

//deletion of node------------------->

struct node * deleteNode(struct node * root, int key) {

    if (root == NULL)
        return root;

    if (key < root -> key)
        root -> leftChild = deleteNode(root -> leftChild, key);

    else if (key > root -> key)
        root -> rightChild = deleteNode(root -> rightChild, key);

    else {
        //node having only one child
        if (root -> leftChild == NULL) {
            struct node * temp = root -> rightChild;
            free(root);
            return temp;
        } else if (root -> rightChild == NULL) {
            struct node * temp = root -> leftChild;
            free(root);
            return temp;
        }
        struct node * temp = minValueNode(root -> rightChild);

        root -> key = temp -> key;
        root -> rightChild = deleteNode(root -> rightChild, temp -> key);
    }

    return root;
}

//In-order-traversal-------------->

void inorder(struct node * root) {
    if (root != NULL) {
        inorder(root -> leftChild);
        printf("%d ", root -> key);
        inorder(root -> rightChild);
    }
}

int main() {

    int n, datas, deletenode;
    struct node * root = NULL;

    printf("//////////////// Construction of BST ///////////////\n");
    printf("\n");
    printf("Number of nodes you want to insert---> ");
    scanf("%d", & n);
    for (int i = 1; i <= n; i++) {
        printf("Enter %d no. node--->   ", i);
        scanf("%d", & datas);
        root = insert(root, datas);

    }

    printf("In-order Traversal---->\n");
    inorder(root);
    printf("\n");
    printf("\n");

    printf("Enter the node you want to delete-->  ");
    scanf("%d", & deletenode);
    printf("In-order Traversal after deletion of a node  --->\n");

    root = deleteNode(root, deletenode);
    inorder(root);
    printf("\n");

    return 0;
}
