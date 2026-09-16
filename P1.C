#include<stdio.h>
#include<stdlib.h>

struct node* createNode(struct node *p,int x);
void getNode(struct node *p);

struct node
{
	int data;
	struct node *next;
};

int main()
{
	struct node *p;
	int n;
	clrscr();
	printf("----LINKED-LIST PROGRAM----");
	p=(struct node*)malloc(sizeof(struct node));
	printf("\nEnter the no of Nodes:");
	scanf("%d",&n);
	printf("\nEnter the data for node 1:");
	scanf("%d",&p->data);
	p=createNode(p,n);
	getNode(p);
	getch();
	return 0;
}

struct node* createNode(struct node *p,int x)
{
	struct node *q,*r;
	int i;
	q=p;
	for(i=1;i<x;i++)
	{
		r=(struct node*)malloc(sizeof(struct node));
		printf("Enter the data for node %d:",i+1);
		scanf("%d",&r->data);
		r->next=NULL;
		q->next=r;
		q=r;
	}
	return p;
}

void getNode(struct node *p)
{
	struct node *q;
	q=p;
	printf("\n----TRAVERSAL----\n");
	while(q!=NULL)
	{
		printf("%d->",q->data);
		q=q->next;
	}
	printf("NULL");
}
