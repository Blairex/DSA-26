// Program to create a doubly linked list and print the same in both directions

#include <stdio.h>
#include <stdlib.h>

struct node *createNode(struct node *p, int n);
void getNodes(struct node *p);

struct node {
  struct node *prev;
  int data;
  struct node *next;
};

int main() {
  struct node *p;
  int n;
  p = (struct node *)malloc(sizeof(struct node));
  p->prev = NULL;
  printf("Enter the data for the first node: ");
  scanf("%d", &p->data);
  p->next = NULL;
  printf("\nEnter the number of nodes you want to create: ");
  scanf("%d", &n);
  p = createNode(p, n);
  getNodes(p);
}

struct node *createNode(struct node *p, int n) {
  struct node *q, *r;
  int i;
  q = p;
  for (i = 1; i <= n; i++) {
    r = (struct node *)malloc(sizeof(struct node));
    printf("\nEnter the data for node %d: ", i + 1);
    scanf("%d", &r->data);
    r->prev = q;
    r->next = NULL;
    q->next = r;
    q = r;
  }
  return p;
}

void getNodes(struct node *p) {
  struct node *q;
  q = p;
  printf("\nThe data in the linked list in forward direction is:\n");
  while (q != NULL) {
    printf("%d", q->data);
    if (q->next != NULL) {
      printf("<->");
    }
    q = q->next;
  }
  printf("\n\nThe data in the linked list in backward direction is:\n");
  q = p;
  while (q->next != NULL) {
    q = q->next;
  }
  while (q != NULL) {
    printf("%d", q->data);
    if (q->prev != NULL) {
      printf("<->");
    }
    q = q->prev;
  }
  printf("\n");
}
