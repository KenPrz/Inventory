#include<windows.h>
#include<stdio.h>
#include<conio.h>
#include <stdlib.h>
#include<string.h>                 
#include<ctype.h>                   
#include<dos.h>                    
#include<time.h>
int randomize(int random_num);
void login();
void menu();
void add();
void edit();
void view();
void switcher(int var);
struct product
{
	int ID,amount;
	char name[20];
	float price;
};
int main()
{
	system("color 70");
	login();
	menu();
return 0;
}
void switcher(int var)
{
	switch(var)
	{
		case 1:
		{	
			add();
			break;
		}
		case 2:
		{
			edit();
			break;
		}
		case 3:
		{	
			view();
			break;
		}
		case 4:
		{
			system("cls");
			printf("Thank you for using This product\n");
			printf("Copyright: 2021\n");
			exit(1);
			break;
		}
	}
}
void menu()
{
	int var;
	do
	{
		system("cls");	
		printf("\n\n			What do you want to do?\n\n");
	
		printf("                            1.Add inventory\n");
		printf("                           -------------------\n");
		printf("                            2.Edit inventory\n");
		printf("                           -------------------\n");
		printf("                            3.View inventory\n");
		printf("                           -------------------\n");
		printf("                            4.Exit\n");
		printf("------------------------------------------------------------------\n");
		printf("Answer: ");
		scanf("%d",&var);
	}while(var>=5 || var<=0);
	switcher(var);
}
void login()
{
	system("cls");
	char password[10]={"1234"};
	char d[25]="Password Protected";
	char ch,pass[10];
	int i=0,j;
	login:
	printf("\n\n					Welcome to ABC Inventory Management\n\n");
	printf("   Please enter your password: ");

	while(ch!=13)
	{
		ch=getch();
		if(ch!=13 && ch!=8)
		{
			putch('*');
			pass[i] = ch;
			i++;
		}
	}
	pass[i] = '\0';
	if(strcmp(pass,password)==0)
	{
		printf("\nAccess Granted!!!\n");
		printf("\nPress any key to countinue.....");
	}
	else
	{
		printf("\n\nIncorrect password!!\n press any key to try again...");
		getch();
		login();
	}
}
void add()
{	
	    struct product prod[200];
        FILE *file1;          // pero d pa to tapos kase pano kung may parehong ID ganern
        int i, num;
        char x;
        
        if((file1 = fopen("products.txt", "a+")) == NULL)
            printf("Error: The file does not exist");
			else 
			{
                system("cls");
                    printf("'\t\tADD RECORD OF PRODUCT");
                    
                    printf("\n\n\tHow many product do you want add in record? ");
                    scanf("%i", &num);
                    
                       for(i = 0; i < num; i++)
					   {	
					   	   prod[i].ID=randomize(prod[i].ID);
                           printf("\n\n\tID:%d\n",prod[i].ID);
                           fflush(stdin);
                           
                           printf("\n\tProduct name: ");
                           gets(prod[i].name);
                           fflush(stdin);
                           
                           printf("\n\tAmount of product: ");
                           scanf("%d", &prod[i].amount);
                           fflush(stdin);
                           
                           printf("\n\tProduct price: ");
                           scanf("%f", &prod[i].price);
                           fflush(stdin);
                           fprintf(file1, "%d \t%s \t%d \t%f\n", prod[i].ID, prod[i].name, prod[i].amount, prod[i].price);
                       }
            }
            fclose(file1);
            
            printf("\n\tDo you want to add more in the records (y/n)? ");
            scanf("%c", &x);
            
            if(x == 'y')
                add();
            else
                menu();
}
void edit()
{	
	system("cls");
	printf("Inventory Editing goes here");
}
void view()
{
        struct product record[200];
        FILE *fp;
        int i, x;
        
        fp = fopen ("products.txt", "r");
        
        system("cls");
        printf("\t\t\t\tRECORDDS\n\n");
        printf("\tID \t\tNAME \t\tAMOUNT \t\tPRICE\n\n");
                    for(i = 0; !feof(fp); i++){
                        fscanf(fp, "%d %s %d %f\n", &record[i].ID, &record[i].name, &record[i].amount, &record[i].price);
                       printf("        %d            %s          %d             %.2f\n", record[i].ID, record[i].name, record[i].amount, record[i].price);
                    }
        fclose(fp);
        
        printf("\n\tDo you want to go Menu (y/n)?");
        scanf(" %c", &x);
        if(x == 'y')
            menu();
        else
            exit(2);
}
int randomize(int random_num)
{
	return random_num = (rand() % (100000 - 999999 + 1)) + 100000;
}
