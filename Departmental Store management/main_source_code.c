#include<stdio.h>
#include<string.h>
#include<conio.h>
#include<stdlib.h>
struct product{
	int productid;
	char productname[50];
	int productquantity;
	int productrate;
};
int login();
void showmainmenu();
void addproduct();
void editproduct();
void deleteproduct();
void searchproduct();
void showlistofproducts();
void searchproductbyId();
void searchproductbyname();
struct product takeinputofproduct();
void main()
{
	struct product pro;
	int loginplease;
	loginplease=login();
	if(loginplease!=1)
	{
		exit(1);
	}
	system("cls");//clears the console screen
	showmainmenu();
}
int login()
{
	char file_password[50];
	char file_username[50];
	char enterusername[50];
	char enterpassword[50];
	printf("Enter username=");
	scanf("%s" ,&enterusername);
	printf("Enter  password=");
	scanf("%s" ,&enterpassword);
	FILE *fptr1;
	fptr1=fopen("authentication.txt" ,"r");
	fscanf(fptr1 ,"%s %s" ,&file_username,&file_password);
	if(fptr1==NULL)
	{
		printf("AUTHENTICATION FILE DOES NOT EXIST.");
	}
		if(strcmp(file_username,enterusername)==0&&strcmp(file_password,enterpassword)==0)
		{
			return 1;
		}
		else
		{
			printf("wrong entry");
			return 0;
		}
	
}
void showmainmenu()
{
	int choice;
	printf("Enter 1 to Add products");
	printf("\nEnter 2 for search products.");
	printf("\nEnter 3 for edit products.");
	printf("\nEnter 4 for delete products.");
	printf("\nEnter 5 for show list of products.");
	printf("\nEnter 6 to Exit");
	printf("\nEnter your choice=");
	scanf("%d" ,&choice);
	switch(choice)
	{
		case 1:
			addproduct();
			break;
		case 2:
			searchproduct();
			break;
		case 3:
			editproduct();
			break;
		case 4:
			deleteproduct();
			break;
		case 5:
			showlistofproducts();
		case 6:
			system("cls");
			exit(0);
		default:
			system("cls");
			showmainmenu();
	}
}
void addproduct()
{
	struct product pro;
	pro=takeinputofproduct();
	FILE *fptr2;
	fptr2=fopen("productinfo.txt" ,"a");
	fprintf(fptr2 ,"%d,%s,%d,%d\n" ,pro.productid,pro.productname,pro.productquantity,pro.productrate);
	fclose(fptr2);
	system("cls");
	printf("\n*****Sucessfully Added*****\n");
	printf("\n.........PRESS ANY KEY TO GO BACK.........\n");
	getch();//to hold the output screen.
	system("cls");
	showmainmenu();
}
struct product takeinputofproduct(){
	struct product p;
	system("cls");
	printf("\nEnter product ID=");
	scanf("%d" ,&p.productid);
	printf("\nEnter product name=");
	scanf("%s" ,&p.productname);
	printf("\nEnter product quantity=");
	scanf("%d" ,&p.productquantity);
	printf("\nEnter product rate=");
	scanf("%d" ,&p.productrate);
	return p;
}
void showlistofproducts()
{
	system("cls");
	struct product pro;
	printf("\nProduct_ID\tProduct_Name\tProduct_Quantity\tProduct_Rate\n");
	FILE *fptr2;
	fptr2=fopen("productinfo.txt" ,"r");
	while(fscanf(fptr2, "%d,%[^,],%d,%d" ,&pro.productid,&pro.productname,&pro.productquantity,&pro.productrate)!=EOF)
	{
		printf("\n%d \t\t %s\t\t %d  \t\t\t\t %d\n" ,pro.productid,pro.productname,pro.productquantity,pro.productrate);
	}
	fclose(fptr2);
	printf("\n*****Press any key to go back*****\n");
	getch();//hold output screen
	system("cls");
	showmainmenu();	
}
void editproduct()
{
	struct product pro;
	system("cls");
	int user_id;
	FILE *fptr2;
	FILE *fptr3;
	fptr2=fopen("productinfo.txt" ,"r");
	fptr3=fopen("temp.txt" ,"w");
	printf("Enter id to Edit record=");
	scanf("%d" ,&user_id);
	while(fscanf(fptr2, "%d,%[^,],%d,%d" ,&pro.productid,&pro.productname,&pro.productquantity,&pro.productrate)!=EOF)
	{
		if(pro.productid==user_id)
		{
			printf("\nEnter new Product Name=");
			scanf("%s" ,&pro.productname);
			printf("\nEnter new product quantity=");
			scanf("%d" ,&pro.productquantity);
			printf("\nEnter new product rate=");
			scanf("%d" ,&pro.productrate);
		}
		fprintf(fptr3 ,"%d,%s,%d,%d\n" ,pro.productid,pro.productname,pro.productquantity,pro.productrate);
	}
	fclose(fptr2);
	fclose(fptr3);
	remove("productinfo.txt");
	rename("temp.txt" ,"productinfo.txt");
	system("cls");
	printf("    SUCCESSFULLY EDIT COMPLETE   ");
	printf("\n*****Press any key to go Main menu*******\n");
	getch();//hold console output screen
	system("cls");
	showmainmenu();
}
void deleteproduct()
{
	struct product pro;
	system("cls");
	int user_id;
	FILE *fptr2;
	FILE *fptr4;
	fptr2=fopen("productinfo.txt" ,"r");
	fptr4=fopen("temp1.txt" ,"w");
	printf("Enter id to Delete record=");
	scanf("%d" ,&user_id);
	while(fscanf(fptr2, "%d,%[^,],%d,%d" ,&pro.productid,&pro.productname,&pro.productquantity,&pro.productrate)!=EOF)
	{
		if(pro.productid==user_id)
		{
			continue;
		}
		fprintf(fptr4 ,"%d,%s,%d,%d\n" ,pro.productid,pro.productname,pro.productquantity,pro.productrate);
	}
	fclose(fptr2);
	fclose(fptr4);
	remove("productinfo.txt");
	rename("temp1.txt" ,"productinfo.txt");
	system("cls");
	printf("    SUCCESSFULLY DELETE COMPLETE   ");
	printf("\n*****Press any key to go Main menu*******\n");
	getch();//hold console output screen
	system("cls");
	showmainmenu();
}
void searchproduct()
{
	system("cls");
	int searchchoice;
	printf("\nEnter 1 to Search product by ID");
	printf("\nEnter 2 to Search product by Name");
	printf("\nGoto Main menu");
	printf("\nEnter your Choice=");
	scanf("%d" ,&searchchoice);
	switch(searchchoice)
	{
		case 1:
			searchproductbyId();
			break;
		case 2:
			searchproductbyname();
			break;
		default:
			system("cls");
			showmainmenu();
	}
}
void searchproductbyId()
{
	system("cls");
	struct product pro;
	FILE *fptr2;
	fptr2=fopen("productinfo.txt" ,"r");
	int userid;
	printf("\nEnter id to search=");
	scanf("%d" ,&userid);
	printf("\nProduct_ID\tProduct_Name\tProduct_Quantity\tProduct_Rate\n");
	while(fscanf(fptr2, "%d,%[^,],%d,%d\n" ,&pro.productid,&pro.productname,&pro.productquantity,&pro.productrate)!=EOF)
	{
		if(pro.productid==userid)
		{
			printf("\n%d \t\t %s\t\t %d  \t\t\t\t %d\n" ,pro.productid,pro.productname,pro.productquantity,pro.productrate);
		}
	}
	fclose(fptr2);
	printf("\n********* PRESS ANY KEY TO GO BACK***********\n");
	getch();// holds the console output screen
	system("cls");
	searchproduct();
}
void searchproductbyname()
{
	system("cls");
	struct product pro;
	char usernamee[50];
	printf("\nEnter Name to Search=");
	scanf("%s" ,&usernamee);
	FILE *fptr2;
	fptr2=fopen("productinfo.txt" ,"r");
	printf("\nProduct_ID\tProduct_Name\tProduct_Quantity\tProduct_Rate\n");
	while(fscanf(fptr2, "%d,%[^,],%d,%d\n" ,&pro.productid,&pro.productname,&pro.productquantity,&pro.productrate)!=EOF)
	{
		if(strcmp(pro.productname,usernamee)==0)
		{
			printf("\n%d \t\t %s\t\t %d  \t\t\t\t %d\n" ,pro.productid,pro.productname,pro.productquantity,pro.productrate);
		}
		
	}
	fclose(fptr2);
	printf("\n********* PRESS ANY KEY TO GO BACK***********\n");
	getch();// holds the console output screen
	system("cls");
	searchproduct();
}
