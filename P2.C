#include<stdio.h>
#include<stdlib.h>

struct node* insertAtBegin(struct node *p);
struct node* insertAtMid(struct node *p);
struct node* insertAtEnd(struct node *p);
void getNode(struct node *p);

struct node
{
	int data;
	struct node *next;
};

int main()
{
	struct node *p;
	int choice;
	clrscr();
	p=(struct node*)malloc(sizeof(struct node));
	printf("\nEnter the data for first node:");
	scanf("%d",&p->data);
	p->next=NULL;
	do
	{
		clrscr();
		printf("\n----Menu Driven Linked-List Program----\n");
		printf("----1.Insertion at the Beginning----\n");
		printf("----2.Insertion at the Middle----\n");
		printf("----3.Insertion at the End----\n");
		printf("----4.Travesal----\n");
		printf("----5.Exit----\n");
		printf("\nEnter Your Choice[1-5]:");
		scanf("%d",&choice);

		switch(choice){
			     case 1:
				printf("\n----Insertion at the Beginning----\n");
				p=insertAtBegin(p);
				break;

			     case 2:
				printf("\n----Insertion at the Middle----\n");
				p=insertAtMid(p);
				break;

			     case 3:
				printf("\n----Insertion at the End----\n");
				p=insertAtEnd(p);
				break;
			     case 4:
				getNode(p);
				break;
		}
		getch();
	}while(choice!=5);
	return 0;
}

void getNode(struct node *p)
{
	struct node *q;
	q=p;
	printf("\n----Traversal----\n");
	while(q!=NULL)
	{
		printf("%d->",q->data);
		q=q->next;
	}
	printf("NULL");
}

//Function to Insert Node in the Beginning
struct node* insertAtBegin(struct node *p)
{
	struct node *r;
	r=(struct node*)malloc(sizeof(struct node));
	printf("Enter the data for the new node:");
	scanf("%d",&r->data);
	r->next=p;
	p=r;
	return p;
}

//Function to Insert between two Nodes
struct node* insertAtMid(struct node *p)
{
	struct node *q,*r;
	int n;
	q=p;
	r=(struct node*)malloc(sizeof(struct node));
	printf("Enter the value to insert after:");
	scanf("%d",&n);
	while(q->data!=n)
	{
		q=q->next;
	}
	printf("Enter the data for the new node:");
	scanf("%d",&r->data);
	r->next=q->next;
	q->next=r;
	return p;
}

//Function to Insert Node at the End
struct node* insertAtEnd(struct node *p)
{
	struct node *q,*r;
	int n;
	q=p;
	r=(struct node*)malloc(sizeof(struct node));
	while(q->next!=NULL)
	{
		q=q->next;
	}
	printf("Enter the data for the new node:");
	scanf("%d",&r->data);
	r->next=NULL;
	q->next=r;
	return p;
}