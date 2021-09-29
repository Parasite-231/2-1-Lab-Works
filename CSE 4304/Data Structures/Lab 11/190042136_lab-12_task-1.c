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

  if (root == NULL) //if tree is empty
  {
    root = newNode; //enter newnode as root
  } else {
    if (newNode -> data < root -> data)
    {
      root -> leftNode = insert(root -> leftNode, newNode);
    } else if (newNode -> data > root -> data)
    {
      root -> rightNode = insert(root -> rightNode, newNode);
    }
  }
  return root;

}

bool search(Node * root, int data) {
  Node * temp = root;

  while (temp != NULL) {
    if (data == temp -> data)
      return true;
    else if (data < temp -> data)
      temp = temp -> leftNode;
    else if (data > root -> data)
      temp = temp -> rightNode;
  }

  return false;
}

int main() {

  int n;
  scanf("%d", & n);
  for (int i = 0; i < n; i++) {
    Node * root = NULL;
    int x, y;
    scanf("%d %d", & x, & y);
    int count = 0, t;
    scanf("%d", & t);
    Node * temp = newNode(t);
    root = insert(root, temp);

    count++;
    for (int j = 1; j < y; j++) {
      scanf("%d", & y);
      if (search(root, y) == false) {
        count++;
        Node * temp = newNode(y);
        root = insert(root, temp);
      }

    }

    printf("%d", count);
    if (count == x)
      printf("Good\n");
    else if (count > x)
      printf("Average\n");
    else
      printf("Bad\n");
  }

  return 0;
}
