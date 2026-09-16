#include <stdio.h>
#include <stdlib.h>

struct Node {
  int data;
  struct Node *prev;
  struct Node *next;
};

int main() {
  struct Node *p, *r, *q;
  int n, i;

  p = (struct Node *)malloc(sizeof(struct Node));

  printf("Enter data of first node: ");
  scanf("%d", &p->data);

  p->prev = NULL;
  p->next = NULL;

  q = p;

  printf("Enter number of nodes to create: ");
  scanf("%d", &n);

  for (i = 1; i < n; i++) {
    r = (struct Node *)malloc(sizeof(struct Node));

    printf("Enter data: ");
    scanf("%d", &r->data);

    r->prev = q;
    r->next = NULL;

    q->next = r;
    q = r;
  }

  // Print in forward direction
  printf("\nForward direction: ");

  q = p;
  while (q != NULL) {
    printf("%d", q->data);
    if (q->next != NULL) {
      printf("<->");
    }
    q = q->next;
  }
  printf("NULL");

  q = p;
  while (q->next != NULL) {
    q = q->next;
  }

  // Print in backward direction
  printf("\nBackward direction: ");

  while (q != NULL) {
    printf("%d", q->data);
    if (q->prev != NULL) {
      printf("<->");
    }
    q = q->prev;
  }
  printf("NULL");

  return 0;
}
