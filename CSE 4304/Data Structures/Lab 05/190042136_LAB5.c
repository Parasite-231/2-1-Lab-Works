#include<stdio.h>

#include<stdlib.h>

// Creating the structure for declaring a Node
struct Node {
  //Declare the variable to store data
  //Declare to variable to store the next node's address
  int data;
  struct Node * next;
};

typedef struct Node Node;

//Creating a structure for managing a linked list
struct List {
  Node * firstnode;
};

typedef struct List List;

Node * createNode() {
  //Declare a pointer type variable to hold the address of a node
  //Allocate memory for a node and save the address to previously declared variable
  //Ask the user to enter the data for the node
  //Read and store the data in the node
  //Set the pointer (usually named "next") of the node as NULL
  //Return the address of newly created node
  Node * node = (Node * ) malloc(sizeof(Node));
  printf("Please enter data in the node : ");
  scanf("%d", & node -> data);
  node -> next = NULL;
  return node;
}

void displayList(List * list) {
  //Run a loop to print all the elements of the list
  Node * last;
  if (list -> firstnode != NULL) {
    last = list -> firstnode;
    printf("The elements in the linked list are --->");
    printf("\n") ;
    while (last != NULL) {
      printf("%d\n", last -> data);
      last = last -> next;
    }
  } else {
    printf("Linked list is empty, nothing to display!To display insert some value.");
  }
}

void insertAtFront(Node * newNode, List * list) {
  //Add the newnode to the beginning of the list
  newNode -> next = list -> firstnode;
  list -> firstnode = newNode;
}

void insertAfter(Node * newnode, Node * node) {
  //Add the "newnode" after the node having address "node"
  if (node != NULL) {
    newnode -> next = node -> next;
    node -> next = newnode;
  } else {
    printf("Sorry, this operation cannot be performed.");

  }
}

void insertAtEnd(Node * newnode, List * list) {
  //Add the "newnode" at the end of the list
  Node * last;
  if (list -> firstnode != NULL) {
    last = list -> firstnode;
    while (last -> next != NULL) {
      last = last -> next;
    }
    insertAfter(newnode, last);
  } else {
    insertAtEnd(newnode, list);
  }

}

void removeFromFront(List * list) {
  //Delete the first node of the list (if possible)
  Node * first;
  if (list -> firstnode != NULL) {
    first = list -> firstnode;
    list -> firstnode = first -> next;
    free(first);
  } else {
    printf("Sorry, cannot perform this operation list is empty");
  }
}

int main() {
  int n, i;
  List list;
  list.firstnode = NULL;

  printf("Enter the number of elements you want to store: ");
  scanf("%d", & n);

  //Run a loop n times, each time do the following:
  // Create a new node by calling our user defined function
  // Add the newnode at the beginning of the list
  //display all the contents of the list

  for (i = 0; i < n; i++) {
    Node * newnode;
    newnode = createNode();
    insertAtFront(newnode, & list);
  }
  displayList( & list);

  printf("\nEnd\n");
  return 0;
}