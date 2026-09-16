#include<stdio.h>
#include<stdlib.h>

struct node* createNode(struct node *p);
void getNode(struct node *p);

struct node
{
	int data;
	struct node *next;
};

int main()
{
	struct node *p,*q,*r;
	int choice,n;
	clrscr();
	p=(struct node*)malloc(sizeof(struct node));
	printf("\nEnter the data for first node:");
	scanf("%d",&p->data);
	p->next=NULL;
	p=createNode(p);
	do
	{
		clrscr();
		printf("\n----Menu Driven Linked-List Program----\n");
		printf("----1.Deletion at the Beginning----\n");
		printf("----2.Deletion at the Middle----\n");
		printf("----3.Deletion at the End----\n");
		printf("----4.Traversal----\n");
		printf("----5.EXIT----\n");
		printf("\nEnter Your Choice[1-5]:");
		scanf("%d",&choice);

		switch(choice){
			case 1: //Deletion at the beginning
				if(p==NULL){
					printf("\nLinked-List is empty");
				}
				q=p;
				p=p->next;
				free(q);
				break;

			case 2: //Deletion at the middle
				if(p==NULL){
					printf("\nLinked-List is empty");
				}
				r=p;
				printf("\nEnter the value to Delete:");
				scanf("%d",&n);
				while(r->data!=n)
				{
					q=r;
					r=r->next;
				}
				q->next=r->next;
				free(r);
				break;

			case 3: //Deletion at the end
				if(p==NULL){
					printf("\nLinked-List is empty");
				}
				r=p;
				while(r->next!=NULL)
				{
					q=r;
					r=r->next;
				}
				q->next=NULL;
				free(r);
				break;
			case 4:
				getNode(p);
				break;
		}
		getch();
	}while(choice!=5);
	return 0;
}

//Function to display the values of linked-liist
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

//Function to create new Node
struct node* createNode(struct node *p)
{
	int n,i;
	struct node *q,*r;
	q=p;
	printf("Enter the number of Nodes to create:");
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		r=(struct node*)malloc(sizeof(struct node));
		printf("Enter the value for Node %d:",i+1);
		scanf("%d",&r->data);
		r->next=NULL;
		q->next=r;
		q=r;
	}
	return p;
}