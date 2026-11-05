#include<stdio.h>

typedef struct employee
{
	int id;
	char name[100];
	float salary;
}emp;

int main()
{
	FILE *fp;
	emp e;
	int ch;
	char choice='y';
	long int recsize=sizeof(emp);
	fp=fopen("C:\\emp102.dat","ab+");
	if(fp==NULL)
	{
		printf("\nFile cannot be open");
		getch();
		exit(0);
	}
	while(1)
	{
	       clrscr();
	       printf("\n---Program for Database Management---\n");
	       printf("\nMenu Options:");
	       printf("\n1.Add Records");
	       printf("\n2.List Records");
	       printf("\n5.Exit");
	       printf("\nEnter your choice:");
	       scanf("%d",&ch);
	       switch(ch)
	       {
			case 1:
				clrscr();
				printf("\nAdding Records\n");
				fseek(fp,0,SEEK_END);//function to set file pointer at the end
				while(choice=='y' || choice=='Y')
				{
					printf("\nEnter ID Name Salary:");
					scanf("%d %s %f",&e.id,&e.name,&e.salary);
					fwrite(&e,recsize,1,fp);
					printf("\nDo you want to continue[y/Y]:");
					fflush(stdin);
					choice=getche();
				}
				break;
			case 2:
				break;
			case 5:
				exit(0);

	       }
	       getch();

	}
	fclose(fp);
	return 0;
}