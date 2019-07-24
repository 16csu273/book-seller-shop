#include<stdio.h>
#include<process.h>
#include<string.h>
#include<conio.h>

FILE *fp1;
int n;
char m;
struct book
{
char pname[20];
char bname[20];
int cost;
int qty;
}b[10];
void add(int);
void search(char a[]);
void buy(char c[]);
void display();
void main()
{
int i,ch;
char a[10],c[10];
clrscr();
z:
printf("......................................\n");
printf(":         press<1> for add           :\n");
printf(":         press<2> for search        :\n");
printf(":         press<3> for buy book      :\n");
printf(":         press <4> for display      :\n");
printf(":         press<0> for exit          :\n");
printf(":....................................:\n");
printf("\tenter the choice");
scanf("%d",&ch);
switch(ch)
{
case 1:
	printf("enter the number of book do you want to add\n");
       scanf("%d",&n);
       add(n);
       break;
case 2:
	printf("enter the book name for search\n");
	scanf("%s",a);
	search(a);
	break;
case 3:
	printf("enter the book name do u want to buy\n");
	scanf("%s",c);
	buy(c);
	break;
case 4:
	printf("content of the file is :::::\n");
       display();
       break;
case 0:
	exit(0);
	break;
default:
	 printf("not valid\n");
	 break;
}
printf("do you want to continue (y/n)");
scanf("%s",&m);
if('y'==m)goto z;
}
void add(int n)
{
int i;
fp1=fopen("data","a");
for(i=0;i<n;i++)
{
printf("***********************************\n");
printf("for %d book\n",i+1);
printf("enter the publisher name\n");
scanf("%s",b[i].pname);
printf("enter the book name\n");
scanf("%s",b[i].bname);
printf("enter the quantity of book \n");
scanf("%d",&b[i].qty);
printf("enter the cost \n");
scanf("%d",&b[i].cost);
fprintf(fp1,"*************************************\npublisher of book is %s\n name of book is %s\n quantity of book avaliable is %d\n cost of each book is %d\n************************************\n",b[i].pname,b[i].bname,b[i].qty,b[i].cost);
}
fclose(fp1);
}
void search (char a[10])
{
int k,i,flag=1;
fp1=fopen("data","r+");
for(i=0;i<n;i++)
{
k=strcmp(a,b[i].bname);
if(k==0)
{
printf("\nbook find successul\n");
printf("publisher name is ::: %s\n",b[i].pname);
printf("book name is ::: %s\n",b[i].bname);
fscanf(fp1,"%s",b[i].qty);
printf("quantity of book is  is ::: %d\n",b[i].qty);
fscanf(fp1,"%d",b[i].cost);
printf("cost of book  is  ::: %d\n",b[i].cost);

flag=1;
break;
}
}
if(flag==0)
printf("book not found\n");
fclose(fp1);
}
void buy(char c[10])
{
float bill;
int i,q,k;
for(i=0;i<n;i++)
if(strcmp(c,b[i].bname)==0)
{
printf("this book is avalabe in stock\n");
printf("enter the number of book u want to buy\n");
scanf("%d",&q);
if(b[i].qty>q)
{
printf("the book is enough in stock\n");
b[i].qty=b[i].qty-q;
fprintf(fp1," new quantity is %d",b[i].qty);
printf("the bill of %d book is %d ",q,q*b[i].cost);
}
else
printf("book is not sufficient in stock");
}
fclose(fp1);
}
void display()
{
char ch;
fp1=fopen("data","r");
while((ch=getc(fp1))!=EOF)
{
  printf("%c",ch);
}
fclose(fp1);
}



