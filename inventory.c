#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>                 
#include<ctype.h>                        
#include<time.h>
#include<windows.h>
COORD coord = {0, 0};
int randomize(int random_num);
void login();
void menu();
void add();
void edit();
void view();
void search();
void switcher(int var);
void gotoxy (int x, int y)
{
coord.X = x; coord.Y = y; 
SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
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
//Major functions
void login()
{
	system("cls");
	char password[10]={"user"};
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
        char temp[200];
        
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
                           printf("\n\n\tNOTE: please use underscore instead of spaces\n");
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
	getch();
	menu();
}
void view()
{
        struct product record[200];
        FILE *fp;
        int i, j=4;
        float profit,temp;
        
        fp = fopen ("products.txt", "r");
        
        system("cls");
        printf("\t\t\t\tRECORDDS\n\n");
        printf("\n ID           NAME          AMOUNT          PRICE          EXPECTED PROFIT");
                    while(!feof(fp))
					{
                    	fscanf(fp, "%d %s %d %f\n", &record[i].ID, &record[i].name, &record[i].amount, &record[i].price);
						    gotoxy(1,j);
							printf("%d",record[i].ID);
							gotoxy(14,j);
							printf("%s",record[i].name);
							gotoxy(28,j);
							printf("%d",record[i].amount);
							gotoxy(44,j);
							printf("%5.2f",record[i].price);
							gotoxy(59,j);
							printf("%.2f\n",record[i].price*record[i].amount);
							temp=record[i].price*record[i].amount;
							profit=profit+temp;
							printf("\n\n");
							i++,j++;
                    }
                    printf("-------------------------------------------------\n");
                    printf(" OVERALL EXPECTED PROFIT: Php %.2f",profit);
        fclose(fp);
        
        printf("\n\nPress any key to retrun to main menu\n\n");
		getch();
		menu();
}
void search()
{
	    struct product record[200];
        int var,id,i;
        int checker=0;
        char name[200];
		FILE *file1;
        file1 = fopen ("products.txt", "r");
        	if(file1==NULL)
			{
				printf("Error in Record search function\n");
        		exit(1);
			}
			else
			{
				do
				{
				system("cls");
				gotoxy(10,7);
				printf("v Search v\n");
				gotoxy(8,10);
				printf("1. Search By ID\n");
				gotoxy(8,12);
				printf("2. Search By Name\n");
				gotoxy(8,14);
				printf("3.Return to menu\n");
				gotoxy(8,15);
				printf("Answer: ");
				scanf("%d",&var);
				}while(var>=4 || var<=0);
				switch(var)
				{
					case 1:
					{
						system("cls");
						gotoxy(25,4);
						
						printf("ID SEARCH\n\n");
						gotoxy(20,5);
						printf("ID: ");
						scanf("%d",&id);
						gotoxy(20,7);
                    	
						while(!feof(file1))
						{
                    		fscanf(file1, "%d %s %d %f\n", &record[i].ID, &record[i].name, &record[i].amount, &record[i].price);
							if(record[i].ID==id)
							{	checker=1;
								printf("ID: %d\n",record[i].ID);
								gotoxy(20,8);
								printf("NAME: %s\n",record[i].name);
								gotoxy(20,9);
								printf("Amount: %d\n",record[i].amount);
								gotoxy(20,10);
								printf("PRICE: %5.2f\n",record[i].price);
								printf("\n\n");
								
								printf("Search again? y/n\n");
								if(getch()=='y')
								{
									search();
								}
								else
								{
									menu();
								}
							}
							if(checker!=1)
							{
								gotoxy(20,12);
								printf("No Entry found!!\n");
								gotoxy(20,14);
								printf("Press any key to search again\n");
								getch();
								search();
									
							}
						i++;					
						}
					break;
					menu();
					}
					case 2:
					{	
						system("cls");
						gotoxy(25,4);
						
						printf("NAME SEARCH\n\n");
						gotoxy(20,5);
						printf("NAME: ");
						scanf("%s",&name);
						gotoxy(20,7);
                    	
						while(!feof(file1))
						{
                    		fscanf(file1, "%d %s %d %f\n", &record[i].ID, &record[i].name, &record[i].amount, &record[i].price);
							if(strcmp(record[i].name,name)==0)
							{
								checker=1;
								printf("ID: %d\n",record[i].ID);
								gotoxy(20,8);
								printf("NAME: %s\n",record[i].name);
								gotoxy(20,9);
								printf("Amount: %d\n",record[i].amount);
								gotoxy(20,10);
								printf("PRICE: %5.2f\n",record[i].price);
								printf("\n\n");
								printf("Search again? y/n\n");
								if(getch()=='y')
								{
									search();
								}
								else
								{
									menu();
								}
							}
							if(checker!=1)
							{
								gotoxy(20,12);
								printf("No Entry found!!\n");
								gotoxy(20,14);								
								printf("Press any key to search again\n");
								getch();
								search();
							}
						i++;					
						}
						break;
						menu();	
						break;
					}
					case 3:
					{
						menu();
						break;
					}
				}
			}
	fclose(file1);
	}

//minor functions
void menu()
{
	int var;
	do
	{
		system("cls");	
		printf("\n\n			What do you want to do?\n\n");
	
		printf("                            1.Add inventory\n");
		printf("                           -------------------\n");
		printf("                            2.Edit/Update inventory\n");
		printf("                           -------------------\n");
		printf("                            3.View inventory\n");
		printf("                           -------------------\n");
		printf("                            4.Search inventory\n");
		printf("                           -------------------\n");
		printf("                            5.Exit\n");
		printf("------------------------------------------------------------------\n");
		printf("Answer: ");
		scanf("%d",&var);
	}while(var>=6 || var<=0);
	switcher(var);
}
int randomize(int random_num)
{
	srand(time(NULL)); // randomize seed
	return random_num = (rand() % (100000 - 999999 + 1)) + 100000;
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
			search();
			break;
		}
		case 5:
		{
			system("cls");
			printf("               Thank you for using This product\n");
			printf("                        Copyright: 2021\n");
			exit(1);
			break;
		}
	}
}
