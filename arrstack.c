// Static Stack Implementation in C using Array
#include <stdio.h>
#define MAX 5

int stack[MAX];
int top = -1;
void push();
void pop();
void peek();
void display();
int isEmpty();
int isFull();

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

int isFull() {
  if (top == MAX - 1) {
    return 1;
  } else {
    return 0;
  }
}

int isEmpty() {
  if (top == -1) {
    return 1;
  } else {
    return 0;
  }
}

void push() {
  int x;
  printf("Enter Value to Push:");
  scanf("%d", &x);
  if (isFull()) {
    printf("Stack Overflow\n");
  } else {
    top++;
    stack[top] = x;
    printf("Value %d Pushed to the stack\n", x);
  }
}

void pop() {
  if (isEmpty()) {
    printf("Stack Underflow\n");
  } else {
    int x = stack[top];
    top--;
    printf("Value %d Popped from the stack\n", x);
  }
}

void peek() {
  if (isEmpty()) {
    printf("Stack is Empty\n");
  } else {
    printf("Top Value is %d\n", stack[top]);
  }
}

void display() {
  if (isEmpty()) {
    printf("Stack is Empty\n");
  } else {
    printf("Stack Elements are:\n");
    for (int i = top; i >= 0; i--) {
      printf("%d\n", stack[i]);
    }
  }
}
