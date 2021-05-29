#include <stdio.h>
#include <conio.h>
#include <string.h>
#include<stdlib.h>

void entry()
{
    FILE *fp;
    char da[20];
    char uname[20];
    char bname[20];
    long int cost;
    char cont[20];
    printf("\nEnter the date of entry               :-");
    scanf("%s",&da);
    printf("\nEnter the name of the buyer           :-");
    scanf("%s",&uname);
    printf("\nEnter the name of the book            :-");
    scanf("%s",&bname);
    printf("\nEnter the cost of the book            :-");
    scanf("%ld",&cost);
    printf("\nEnter the contact number of the buyer :-");
    scanf("%s",&cont);
    fp=fopen("Record.txt","a");
    fprintf(fp,"%s\t%s\t%s\t%ld\t%s\n",da,uname,bname,cost,cont);
    printf("\n Record written successfully !!! ");
    fclose(fp);
}
void display(char date[])
{
    FILE *fp;
    char da[20];
    char uname[20];
    char bname[20];
    char cont[20];
    long int cost;
    int cmp;
    int i=0;
    fp=fopen("Record.txt","r");
    while(fscanf(fp,"%s%s%s%ld%s\n",da,uname,bname,&cost,cont)!=EOF)
    {
        cmp=strcmp(da,date);
        if(cmp==0)
        {
            printf("\nBuyer's Name     :-%s\n",uname);
            printf("\nBook Name        :-%s\n",bname);
            printf("\nCost of the book :-%ld\n",cost);
            printf("\nContact Number   :-%s\n",cont);
            i++;
        }
    }
    printf("\nTotal enteries on %s are %d\n",date,i);
    fclose(fp);
}
void main()
{
   char x;
   char date[20];
   do
   {
          clrscr();
          printf("\n*******************************************WELCOME TO THE OM'S BOOK SHOP************************************************");
          printf("\nEnter 1 to create entry of a book\n");
          printf("\nEnter 2 to display on specific date\n");
          printf("\nEnter 0 to exit\n");
          printf("\nEnter your choice:-");
          scanf("%d",&x);
          switch(x)
            {
                case 1: entry();
                break;
                case 2: printf("\nEnter the date:-");
                        scanf("%s",&date);
                        display(date);
                break;
                case 0: exit(0);
                break;
                default: printf("\nYour choice is in appropriate!!");
            }
          getch();
   }while(x!=0);
}
