// Dynamic Stack Implementation using Linked List in C
#include <stdio.h>
#include <stdlib.h>

struct node {
  int data;
  struct node *next;
};

struct node *top = NULL;

void push();
void pop();
void peek();
void display();

int main() {
  int choice;
  do {
    printf("\nStack Menu Driven Program");
    printf("\n1.Push");
    printf("\n2.Pop");
    printf("\n3.Peek");
    printf("\n4.Display");
    printf("\n5.Exit");
    printf("\nEnter your choice[1-5]:");
    scanf("%d", &choice);
    switch (choice) {
    case 1:
      printf("\nPush\n");
      push();
      break;
    case 2:
      printf("\nPop\n");
      pop();
      break;
    case 3:
      printf("\nPeek\n");
      peek();
      break;
    case 4:
      printf("\nDisplay\n");
      display();
      break;
    }
  } while (choice != 5);

  return 0;
}

void push() {
  int x;
  struct node *newnode;
  newnode = (struct node *)malloc(sizeof(struct node));
  newnode->next = NULL;
  if (newnode == NULL) {
    printf("\nStack Overflow");
    return;
  } else {
    printf("\nEnter the data:");
    scanf("%d", &x);
    newnode->data = x;
    newnode->next = top;
    top = newnode;
  }
}

void pop() {
  if (top == NULL) {
    printf("\nStack Underflow");
    return;
  } else {
    struct node *temp = top;
    printf("\nPopped element is %d", temp->data);
    top = top->next;
    free(temp);
  }
}

void peek() {
  if (top == NULL) {
    printf("\nStack is empty");
    return;
  } else {
    printf("\nTop element is %d", top->data);
  }
}

void display() {
  if (top == NULL) {
    printf("\nStack is empty");
    return;
  } else {
    struct node *temp = top;
    printf("\nStack elements are:\n");
    while (temp != NULL) {
      printf("%d\n", temp->data);
      temp = temp->next;
    }
  }
}
