#include<stdio.h>
#include<conio.h>
typedef struct employee
{
	int empid;
	char name[100];
	float salary;
}emp;
void main()
{
	FILE *fp,*ft;
	int choice ;
	int e_id;
	long int recsize = sizeof(emp);
	emp e ;
	char ch='Y';
	fp=fopen("C:\\emp117.dat","rb+");
	if(fp==NULL)
	{
		fp=fopen("C:\\emp117.dat","wb+");
		if(fp==NULL)
		{
			printf("\nFile cannot open ");
			getch();
			exit(0);
		}
	}
	while (1)
	{
		clrscr();
		printf("Program for database management");
		printf("\n 1. Add records ");
		printf("\n 2. List records ");
		printf("\n 3. Modify records");
		printf("\n 4. Deleting records");
		printf("\n 5. Exit:");
		printf("\n Enter your choice:");
		scanf("%d",&choice);
		switch (choice)
		{
		case 1:
			clrscr();
			printf("TO Add Records: ");
			fseek(fp,0,SEEK_END); //file pointer is at the end
			while(ch=='y'||ch=='Y')
			{
				printf("\nEnter employee : EMPLOYEEID  NAME   SALARY");
				scanf("%d %s %f" , & e.empid , &e.name , &e.salary);
				fwrite(&e,recsize,1,fp);
				printf("\n Do you want to continue[y||Y]:");
				fflush(stdin);
				ch=getche();
			}
			break;
		case 2:
			clrscr();
			printf("Listing of Records:");
			rewind(fp);//placing the file pointer to the first record
			printf("\nID\tName\tSalary\n");
			while(fread(&e,recsize,1,fp)==1)
			{
				printf("%d\t%s\t%.2f\n",e.empid,e.name,e.salary);
			}
			printf("\nPress any key to see menu.");
			getch();
			break;
		case 3:
			clrscr();
			printf("\nModify the records.");
			rewind(fp);
			ch='y';
			while(ch=='y' || ch=='Y')
			{
				printf("\nEnter employee ID to modify:");
				scanf("%d",&e_id);
				while(fread(&e,recsize,1,fp)==1)
				{
					if(e_id==e.empid)
					{
						printf("\nEnter new Name Salary: ");
						scanf("%s %f",&e.name,&e.salary);
						fseek(fp,-recsize,SEEK_CUR);
						fwrite(&e,recsize,1,fp);
						break;//if it is a value which is common for any records that's why we need to break
					}
				}
				printf("\nDo you want to continue?[y,Y]:");
				fflush(stdin);
				ch=getche();
			}
			break;
		case 4:
			clrscr();
			printf("\nDeleting Records:");
			ft=fopen("C:\\temp.dat","wb");
			if(ft==NULL)
			{
				printf("Cannot perform deletion");
				getch();
				break;
			}
			printf("\nEnter id to delete: ");
			scanf("%d",&e_id);
			//fclose(fp);
			//fp=fopen("C:\\emp117.dat","wb");
			rewind(fp);
			while(fread(&e,recsize,1,fp)==1)
			{
				 if(e.empid==e_id)
				 {
					continue;
				 }
				 fwrite(&e,recsize,1,ft);
				 //printf("%d %s %f",e.empid,e.name,e.salary);
			}
			fclose(fp);
			fclose(ft);
			remove("C:\\emp117.dat");
			rename("C:\\temp.dat","C:\\emp117.dat");
			fp=fopen("C:\\emp117.dat","rb+");
			printf("\nRecord deleted");
			getch();
			break;
		case 5:
			fclose(fp);
			exit(0);
		}
	}
}
