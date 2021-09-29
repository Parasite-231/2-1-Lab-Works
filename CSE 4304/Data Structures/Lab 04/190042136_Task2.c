#include <stdio.h>

#include <string.h>

#define true 1
#define false 0
#define MAXSIZE 1010
int top = -1;

int isempty() {

  if (top == -1)
    return true;
  else
    return false;
}

int isfull() {

  if (top == MAXSIZE - 1)
    return true;
  else
    return false;
}

char peek(char * stack) {
  if (top != -1)
    return stack[top];
  return -1;
}

char pop(char * stack) {
  char data;

  if (!isempty()) {
    data = stack[top];
    top = top - 1;
    return data;
  }
  else {
    return -1;
  }
}

char push(char * stack, char data) {

  if (!isfull()) {
    top = top + 1;
    stack[top] = data;
    return data;
  }
   else {
    return -1;
  }
}

int main() {
  char stack[MAXSIZE];
  char input[MAXSIZE];
  int i;

  //Read the input from keyboard
  scanf("%s", input);

  //Your code goes here
  // Iterate through every elements of input
  // if top value of stack is same as current element, pop it
  // else push the current value
  push(stack, input[0]);

  for (i = 0; input[i] != 0; i++) {

    if (input[i] != peek(stack)) {

      push(stack, input[i]);
    }
  }

  // After finishing the iteration
  // if nothing left in the stack, print "Empty String"
  // else print the content of stack from bottom to top [ Not from top to bottom]
  if (top == -1) {

    printf("Empty String");
  }
  else {
    for (i = 0; i <= top; i++) {

      printf("%c", stack[i]);
    }
  }

  return 0;
}
