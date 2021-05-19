#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>                 
#include<ctype.h>                        
#include<time.h>
int randomize(int random_num);
void login();
void menu();
void add();
void edit();
void view();
void del();
void search();
void switcher(int var);
void authenticate();
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
return 0;
}

//Major functions
void login()
{
	system("cls");
	char password[10]={"user"};
	char ch,pass[10];
	int i=0,j;
	login:
	printf("\n\n");
	printf("                       |-------------------------------------|\n");
	printf("                       | Welcome to ABC Inventory Management |\n");
	printf("                       |-------------------------------------|\n");
	printf("\n                        Password:");
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
		system("cls");
	printf("\n\n");
	printf("\t\t\t|-------------------------------------|\n");
	printf("\t\t\t|           ACCESS GRANTED!!          |\n");
	printf("\t\t\t|-------------------------------------|\n");
	printf("\n\n\t\t\t Press any key to continue...");
		getch();
		menu();
	}
	else
	{
		printf("\n\n\t\t\tIncorrect password!!\n\t\t\tpress any key to try again...");
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
					   	   system("cls");
					   	   printf("PRODUCT #%d:\n",i+1);
					   	   prod[i].ID=randomize(prod[i].ID);
                           printf("\n\n\tID:%d\n",prod[i].ID);
                           fflush(stdin);
                           
						   printf("\n\n\tNOTE: please use underscore instead of spaces\n");
                           printf("\n\tProduct name: ");
                           gets(prod[i].name);;
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
			{
				system("cls");
            	printf("\n\n\t\t\tProgram requires a relaunch after adding an entry...\n");
            	//will be fixed soon.
            	printf("\t\t\tPress any key to continue...\n");
            	getch();
            	exit(0);
        	}
}
void edit()
{
    int i, j, num, k, choice,checker=0;
    char x;
    struct product record[10000];
    FILE *fp = fopen ("products.txt", "a+");
    FILE *fp1 = fopen("copy.txt", "w+");
    system("cls");
    if(fp==NULL||fp1==NULL)
    {
    	system("cls");
    	printf("\n\n\t\t\tERROR READING FILE IN EDIT FUNCTION\n");
    	getch();
    	menu();
	}
    
    printf("\t\t\t\tRECORDDS\n\n");
    printf("\t\t\tEdit Current Inventory\n\n");
    
        printf("ID            NAME           AMOUNT         PRICE          EXPECTED PROFIT\n");
                    for(i = 0; !feof(fp); i++)
					{
                        fscanf(fp, "%d %s %d %f\n", &record[i].ID, &record[i].name, &record[i].amount, &record[i].price);
							printf(" %-14d%-15s%-15d%-15.2lf%-15.2lf\n",record[i].ID,record[i].name,record[i].amount,record[i].price,record[i].price*record[i].amount);
                        k = i + 1;
                    }
        
        printf("\n");
        printf("\nEnter 'x' to go back to main menu\n\n");            
        printf("\nEnter ID to edit product: ");
        scanf("%i", &num);
        if(num=='x')
            menu();
        system("cls");
        
        for(i = 0; !feof(fp); i++)
        {
            fscanf(fp, "%d %s %d %f\n", &record[i].ID, &record[i].name, &record[i].amount, &record[i].price);
        }
        
        for(j=0; j < k ; j++)
        {
            if(record[j].ID==num)
       		{
       			checker=1;
       			
            	do
            	{	
						system("cls");
      		  			printf("\n\t\tID            NAME           AMOUNT         PRICE          EXPECTED PROFIT\n");
						printf("\t\t %-14d%-15s%-15d%-15.2lf%-15.2lf\n",record[j].ID,record[j].name,record[j].amount,record[j].price,record[j].price*record[j].amount);
        		    	printf("\n");           
        	 	   		printf("\t\t\tPlease choose what to edit\n");
         				printf("\t1. Name\n");
         	 	  		printf("\t2. Amount\n");
         	   			printf("\t3. Price\n");
          	  			printf("\tAnswer: ");
          	  			scanf("%i", &choice);
            		if(choice==1)
            		{
                		printf("\n");
                		printf("\tOriginal name: %s\n", record[j].name);
                		printf("\tEnter new product name: ");
                		scanf("%s", record[j].name);
                		system("cls");
                		printf("\n\tRecord updated!\n");
        				printf("\n\t\tID            NAME           AMOUNT         PRICE          EXPECTED PROFIT\n");
						printf("\t\t%-14d%-15s%-15d%-15.2lf%-15.2lf\n",record[j].ID,record[j].name,record[j].amount,record[j].price,record[j].price*record[j].amount);
                		fprintf(fp, "%d \t%s \t%d \t%f\n", record[j].ID, record[j].name, record[j].amount, record[j].price);
            		}
            		else if(choice==2)
          	  		{
              			printf("\n");
                		printf("\tOriginal amount: %d\n", record[j].amount);
                		printf("\tEnter new amount: ");
               	 		scanf("%d", &record[j].amount);
               	 		system("cls");
               	 		printf("\n\tRecord updated!\n");
        				printf("\n\t\tID            NAME           AMOUNT         PRICE          EXPECTED PROFIT\n");
						printf("\t\t%-14d%-15s%-15d%-15.2lf%-15.2lf\n",record[j].ID,record[j].name,record[j].amount,record[j].price,record[j].price*record[j].amount);
                		fprintf(fp, "%d \t%s \t%d \t%f\n", record[j].ID, record[j].name, record[j].amount, record[j].price);
            		}
            		else if(choice==3)
            		{
                		printf("\n");
                		printf("\tOriginal price: %2.f\n", record[j].price);
                		printf("\tEnter new price: ");
                		scanf("%f", &record[j].price);
                		system("cls");
                		printf("\n\tRecord updated!\n");
        				printf("\n\t\tID            NAME           AMOUNT         PRICE          EXPECTED PROFIT\n");
						printf("\t\t%-14d%-15s%-15d%-15.2lf%-15.2lf\n",record[j].ID,record[j].name,record[j].amount,record[j].price,record[j].price*record[j].amount);
                		fprintf(fp, "%d \t%s \t%d \t%f\n", record[j].ID, record[j].name, record[j].amount, record[j].price);
            		}            	
				}while(choice>=4||choice<=0);
        	}   
        }
        
        for(i = 0; i < k; i++)
        {
            fprintf(fp1, "%d \t%s \t%d \t%f\n", record[i].ID, record[i].name, record[i].amount, record[i].price);
        }
        
        if(checker==0)
		{
        	fclose(fp);
        	fclose(fp1);
    
     	   	remove("products.txt");
       		rename("copy.txt", "products.txt");
    
        	printf("\n\n\tINVALID ID!!!\n");
			printf("\tpress any key to continue...\n");
            getch();
			menu();				
		}
        
        fclose(fp);
        fclose(fp1);
    
        remove("products.txt");
        rename("copy.txt", "products.txt");
    
        printf("\n\n\tThe record was successfully updated!\n");
        printf("\n\tDo you want to edit other product? (y/n)?");
        scanf(" %c", &x);
        if(x == 'y')
            edit();
        else
            menu();
}
void view()
{
        struct product record;
        FILE *fp;
        int i, j=5,ID;
        char checker[20];
        float profit,temp;
        
        fp = fopen ("products.txt", "r");
        	if(fp==NULL)
			{
				system("cls");
				printf("\nFile is empty please add an entry...");
				printf("\nPress any key to continue...\n");
				getch();
				menu();
			}
			
        system("cls");
        printf("\n\n\t\t\t\t\t\tRECORDDS\n\n");
        printf("\t\t ID            NAME           AMOUNT         PRICE          EXPECTED PROFIT");
        printf("\n\t\t----------------------------------------------------------------------------\n");
                    while(!feof(fp))
					{
                    	fscanf(fp, "%d %s %d %f\n", &record.ID, &record.name, &record.amount, &record.price);
							printf("\t\t %-14d%-15s%-15d%-15.2lf%-15.2lf\n",record.ID,record.name,record.amount,record.price,record.price*record.amount);
                    		temp=record.price*record.amount;
                    		profit=profit+temp;
					}
        printf("\t\t----------------------------------------------------------------------------\n");
                    printf("\t\t OVERALL EXPECTED PROFIT: Php %.2f",profit);
        fclose(fp);
        
        printf("\n\nPress any key to return to main menu\n\n");
		getch();
		menu();
}
void search()
{
	struct product record;
    FILE *file1;
    int i, j=4,checker=0;
    int answer,ID;
    char name[200];
    file1 = fopen ("products.txt", "r");    
    
    do
    {	
		system("cls");
    	printf("\n\n\t\t\tSearch by?\n");
    	printf("\t\t\t1.ID\n");
    	printf("\t\t\t2.Name\n");
    	printf("\t\t\t3.Return to menu\n");
    	printf("\t\t\t----------------------------\n");
    	printf("\t\t\tAnswer: ");
    	scanf("%d",&answer);
	}while(answer>=4 || answer<=0);
	
		switch(answer)
		{
			case 1:
			{	system("cls");
				printf("\n\t\t\tSEARCH BY ID\n");
				printf("\t\t\tID: ");
				scanf("%d",&ID);
				
				while(!feof(file1))
					{
                    	fscanf(file1, "%d %s %d %f\n", &record.ID, &record.name, &record.amount, &record.price);
						    
						    if(ID==record.ID)
						    {	system("cls");
								printf("\n\n\t\tID: %d\n",record.ID);
								printf("\t\tNAME: %s\n",record.name);
								printf("\t\tAMOUNT: %d\n",record.amount);
								printf("\t\tPRICE: %5.2f\n",record.price);
								printf("\n\t\tEXPECTED PROFIT: %5.2f",record.price*record.amount);
								printf("\n");
								printf("\npress any key to continue...");
								checker=1;
							}
							else
								continue;
                    }
                    	if(checker==0)
                    	{
                    		printf("\n\t\t\tNO ENTRY FOUND!!!");
                    		printf("\n\t\t\tpress any key to continue...");
						}
                    	getch();
                    	search();
				break;
			}
			case 2:
			{	
				system("cls");
				printf("\n\t\t\tSEARCH BY NAME\n");
				printf("\t\t\tNAME: ");
				scanf("%s",&name);
				
				while(!feof(file1))
					{
                    	fscanf(file1, "%d %s %d %f\n", &record.ID, &record.name, &record.amount, &record.price);
						    
						    if(strcmp(record.name,name)==0)
						    {	system("cls");
								printf("\n\n\t\tID: %d\n",record.ID);
								printf("\t\tNAME: %s\n",record.name);
								printf("\t\tAMOUNT: %d\n",record.amount);
								printf("\t\tPRICE: %5.2f\n",record.price);
								printf("\n\t\tEXPECTED PROFIT: %5.2f",record.price*record.amount);
								printf("\n");
								printf("\npress any key to continue...");
								checker=1;
							}
							else
								continue;
                    }
                    	if(checker==0)
                    	{
                    		printf("\n\t\t\tNO ENTRY FOUND!!!\n");
                    		printf("\npress any key to continue...");
						}
                    	getch();
                    	search();
				break;
				
			}
			case 3:
			{
				menu();
				break;
			}
		}
	
	fclose(file1);
}
void del()
{
	system("cls");
	authenticate();
	
	int i, j, num, k, choice;
    char x;
    struct product record[10000];
    FILE *fp = fopen ("products.txt", "a+");
    FILE *fp1 = fopen("copy.txt", "w+");
    system("cls");
    
    printf("\t\t\t\tRECORDDS\n\n");
    printf("\t\t\tDelete an inventory item\n\n");
    
        printf("ID            NAME           AMOUNT         PRICE          EXPECTED PROFIT\n");
                    for(i = 0; !feof(fp); i++){
                        fscanf(fp, "%d %s %d %f\n", &record[i].ID, &record[i].name, &record[i].amount, &record[i].price);
							printf("%-14d%-15s%-15d%-15.2lf%-15.2lf\n",record[i].ID,record[i].name,record[i].amount,record[i].price,record[i].price*record[i].amount);
                        k = i + 1;
                    }
        
        printf("\n");
        printf("\nEnter 'x' to go back to main menu\n\n");            
        printf("\nEnter ID of the to be deleted product: ");
        scanf("%i", &num);
        if(num=='x')
            menu();
        	system("cls");
        	for(i = 0; !feof(fp); i++)
        	{
           		fscanf(fp, "%d %s %d %f\n", &record[i].ID, &record[i].name, &record[i].amount, &record[i].price);
        	}
       		for(j=0; j < k ; j++)
        	{
            	if(record[j].ID==num)
       			{
					continue;
        		}
				else
					fprintf(fp1, "%d \t%s \t%d \t%f\n", record[j].ID, record[j].name, record[j].amount, record[j].price);
        	}
        fclose(fp);
        fclose(fp1);
    
        remove("products.txt");
        rename("copy.txt","products.txt");
    
        printf("\n\n\tThe record was successfully updated!\n");
        printf("\n\tDo you want to delete another product? (y/n)?");
        scanf(" %c", &x);
        if(x == 'y')
            del();
        else
            menu();
}
//minor functions
void menu()
{
	int var;
	do
	{
		system("cls");
		time_t t;
    	time(&t);
    	printf("\n                            %s", ctime(&t));
		printf("\n");
		printf("                          >>> What do you want to do? <<<\n");
		printf("                          ______________________________\n");
		printf("                          | 1.Add inventory            |\n");
		printf("                          |----------------------------|\n");
		printf("                          | 2.Edit/Update inventory    |\n");
		printf("                          |----------------------------|\n");
		printf("                          | 3.View inventory           |\n");
		printf("                          |----------------------------|\n");
		printf("                          | 4.Search inventory         |\n");
		printf("                          |----------------------------|\n");
		printf("                          | 5.Delete an entry          |\n");
		printf("                          |----------------------------|\n");
		printf("                          | 6.Exit                     |\n");
		printf("                          |----------------------------|\n\n");
		printf("                          Answer: ");
		scanf("%d",&var);
	}while(var>=7 || var<=0);
	switcher(var);
}
int randomize(int random_num)
{	
    struct product record;
    int number_generated;
    FILE *fp = fopen ("products.txt", "r");
    	if(fp==NULL)
    	{
    		printf("ERROR FILE READING IN RANDOMIZE FUNCTION!!!\n");
    		exit(1);
		}
		else
		{
			srand(time(NULL));
			random_num = (rand() % (100000 - 999999 + 1)) + 100000;
            
			while(!feof(fp))
			{
                fscanf(fp, "%d %s %d %f\n", &record.ID, &record.name, &record.amount, &record.price);
                if(random_num==record.ID)
                {
                	random_num=randomize(random_num);
				}
			}
			number_generated=random_num;
			return number_generated;
		}
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
			del();
			break;
		}
		case 6:
		{
			system("cls");
			printf("\n\n\n\n\t\t\tThank you for using This product\n");
			printf("\t\t\t\tCopyright: 2021\n\n\n");
			printf("\t\t\thttps://github.com/traxex123lord\n");
			exit(0);
			break;
		}
	}
}
void authenticate()
{
	system("cls");
	char password[10]={"user"};
	char ch,pass[10];
	int i=0,j;
		printf("\n\n\t\t Please enter the password: ");
	
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
		system("cls");
		printf("\n\t\tACCESS GRANTED!!!\n");
		printf("\n\t\tPress any key to countinue.....");
		getch();
	}
	else
	{
		printf("\n\nINCORRECT PASSWORD!!\n");
		printf("You will be returned to the login menu\n");
		printf("press any key to continue...\n");
		getch();
		login();
	}
}
