#include<stdio.h>
void main()
{
	char username[50];
	char password[50];
	printf("Enter username=");
	scanf("%s" ,&username);
	printf("Enter password=");
	scanf("%s" ,&password);
	FILE *fptr1;
	fptr1=fopen("authentication.txt" ,"w");
	fprintf(fptr1 ,"%s %s" ,username,password);
}
