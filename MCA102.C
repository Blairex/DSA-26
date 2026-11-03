#include<stdio.h>

int main()
{
	FILE *fp;
	char s[100];
	clrscr();
	printf("\nProgram to read a file using string functions");
	fp=fopen("C:\\mca.txt","r");
	if(fp==NULL)
	{
		printf("\nCannot open file");
		getch();
		exit(0);
	}
	printf("\nThe contents of the file are:\n");
	while(fgets(s,99,fp)!=NULL)
	{
		printf("%s",s);
	}
	printf("\n\nEnd of File reached!.... Press any key to exit");
	getch();
	return 0;
}