#include<stdio.h>
#include<stdlib.h>



struct node {
  int data;
  struct node * leftNode;
  struct node * rightNode;
};
int count = 0;

typedef struct node Node;
void inorder(Node * root) {
  //when tree is not null
  if (root != NULL) {
    inorder(root -> leftNode);
    printf("%d \n", root -> data);
    inorder(root -> rightNode);
  }
}
struct node * newNode(int value) {
  struct node * temp = (struct node * ) malloc(sizeof(struct node));
  temp -> data = value;
  temp -> leftNode = temp -> rightNode = NULL;
  return temp;
}

Node * insert(Node * root, Node * newNode) {

  if (root == NULL) {
    root = newNode;
  } else {
    if (newNode -> data < root -> data) {
      root -> leftNode = insert(root -> leftNode, newNode);
    } else if (newNode -> data > root -> data) {
      root -> rightNode = insert(root -> rightNode, newNode);
    }
  }
  return root;

}
