#include <conio.h>
#include <stdio.h>
#include <string.h>
#include <process.h>
#include <alloc.h>

int creat();
int add();
int add2();
int del();
int show();
int curser();
short int pass();

 FILE *bca,*bcom,*bsc,*bba,*bed,*f,*pr;
int fixfee[5];

 struct node
{ char name[20];
char fname[30];
unsigned int deposit;
unsigned int leftm;
char c[6];
struct node *link;
}*first,*last,*newadd,*temp,*temp1;



void main()
{short int i,j,k,p,c;
//_setcursortype(_NORMALCURSOR);
clrscr();
first=last=NULL;
pr=fopen("ava_dt","r+");
if(pr==NULL)
{
printf("problem in opening in the file");
getch();
exit(0);
}
if(fgetc(pr)==EOF)
{
rewind(pr);
fprintf(pr,"*");
}
rewind(pr);
while(fgetc(pr)!='*')
{
fseek(pr,-1,SEEK_CUR);
newadd=(struct node *)malloc(sizeof (struct node));
if(newadd==NULL)
{ printf("list is overflow");
exit(0);
}
fflush(stdin);
fscanf(pr,"%s%25s%18u%15u%10s\n",&newadd->name,&newadd->fname,&newadd->deposit,&newadd->leftm,&newadd->c);
if (first==NULL)
   { first=last=newadd;
     last->link=NULL;
    }
   else
   {
   last->link=newadd;
   last=newadd;
   last->link=NULL;
   }

}
fclose(pr);
f=fopen("fixfee.txt","r+");
if(fgetc(f)==EOF)
{
rewind(f);
printf ("±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±± WELCOME ±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±\n");
printf("\nEnter the amount of fixfee\n");
printf("BCA=");
scanf("%d",&fixfee[0]);
fprintf(f,"%d",fixfee[0]);
printf("B.com=");
scanf("%d",&fixfee[1]);
fprintf(f,"\n%d",fixfee[1]);
printf("B.sc=");
scanf("%d",&fixfee[2]);
fprintf(f,"\n%d",fixfee[2]);
printf("BBA=");
scanf("%d",&fixfee[3]);
fprintf(f,"\n%d",fixfee[3]);
printf("B.ed=");
scanf("%d",&fixfee[4]);
fprintf(f,"\n%d",fixfee[4]);
fclose(f);
}
else
{
rewind(f);
fscanf(f,"%d",&fixfee[0]);
fscanf(f,"\n%d",&fixfee[1]);
fscanf(f,"\n%d",&fixfee[2]);
fscanf(f,"\n%d",&fixfee[3]);
fscanf(f,"\n%d",&fixfee[4]);
fclose(f);
}
while(1)
{
clrscr();
printf ("±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±± WELCOME ±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±\n");
printf("  Creat a new file\n  Add member in the file\n  Delete a member in the file\n  Show the file\n  Control menu\n  Exit\n  show fixfee\n");
printf("\n\n\t\tPlease use 'k' to move curser downword and 'i' for upword");
i=curser(7,1,2);
switch(i)
{case 1:clrscr();printf ("±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±± WELCOME ±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±\n");
	printf ("\n\t\t\t\tCreat a new file\n");
	creat();
	break;
case 2:clrscr();printf ("±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±± WELCOME ±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±\n");
	printf ("\n\t\t\tAdd member in the file\n");
	printf("  Add only one member in exiting file\n  Add many members in exiting file\n  Back");
	printf("\n\n\t\tPlease use 'k' to move curser downword and 'i' for upword");
	j=curser(3,1,4);
	if(j==1)
	add();
	else if(j==2)
	add2();
	else if(j==3)
	break;
	break;
case 3:clrscr();printf ("±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±± WELCOME ±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±\n");
	printf ("\n\t\tDelete a member in the file\n");
	del();
	break;
case 4:clrscr();printf ("±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±± WELCOME ±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±\n");
	printf ("\n\t\tShow the file\n");
	show();
	break;
case 5:clrscr();printf ("±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±± WELCOME ±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±\n");
	printf ("\n\t\tControl menu\n");
	printf("Enter your password:\n");
	p=pass(0);
	if(p==0)
	{printf("\nYou enter wrong password");
	getch();
	break;
	}
	clrscr();printf ("±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±± WELCOME ±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±\n");
	printf ("\n\t\tControl menu\n");
	printf("  Change the amount of fixfee\n  Change the password\n  Back");
	c=curser(3,1,4);
	if(c==2)
	{pass(1);
	 printf("\npassword have been set");
	 break;
	}
	if(c==3)
	break;
	printf("\nEnter the new amount of fee:");
	f=fopen("fixfee.txt","r+");
	printf("\n\nBCA=");
	scanf("%d",&fixfee[0]);
	fprintf(f,"%d",fixfee[0]);
	printf("B.com=");
	scanf("%d",&fixfee[1]);
	fprintf(f,"\n%d",fixfee[1]);
	printf("B.sc=");
	scanf("%d",&fixfee[2]);
	fprintf(f,"\n%d",fixfee[2]);
	printf("BBA=");
	scanf("%d",&fixfee[3]);
	fprintf(f,"\n%d",fixfee[3]);
	printf("B.ed=");
	scanf("%d",&fixfee[4]);
	fprintf(f,"\n%d",fixfee[4]);
	fclose(f);
	break;

case 6:clrscr();printf ("±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±± WELCOME ±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±\n");
	printf ("\n\t\t\t\tExit\n");
	printf("  YES\n  NO\n");
	k=curser(2,1,4);
	if(k==2)
	break;
	printf ("\n\t\t\tTHANK YOU FOR USING PROGRAME\n");
	printf ("\n\n\n\n±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±± THANKYOU ±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±\n");
	getch();
	goto b;

case 7:clrscr();printf ("±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±± WELCOME ±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±\n");
	printf ("\n\t\t\tShow fixfee\n\n");
	printf("BCA=%d\n\n",fixfee[0]);
	printf("B.com=%d\n\n",fixfee[1]);
	printf("B.sc=%d\n\n",fixfee[2]);
	printf("BBA=%d\n\n",fixfee[3]);
	printf("B.ed=%d\n\n",fixfee[4]);printf("\n\npress any key"); getch();break;

default:clrscr();printf ("±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±± WELCOME ±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±\n");
	printf ("\t\tyou enter the WRONG choice\n\t\tPlease re enter the choice");getch();break;
}
}
b:
pr=fopen("ava_dt","w");
fflush(stdin);
temp1=first;
while(temp1!=NULL)
{ fprintf(pr,"%s%25s%18u%15u%10s\n",temp1->name,temp1->fname,temp1->deposit,temp1->leftm,temp1->c);
temp1=temp1->link;
}
fprintf(pr,"*");
fclose(pr);
temp1=first;
temp=temp1->link;
while(temp!=NULL)
{ free(temp1);
temp1=temp;
temp=temp->link;
}
free(temp1);

}


 int  creat()
{
int j,k;


printf("\n\tIf you choose this option \n\tthan old data will be deleted\n");
printf("\n\t\tPlease use 'k' to move curser downword and 'i' for upword\n\n");
printf("  YES\n  NO");
k=curser(2,1,10);
if(k==2)
return(0);
temp1=first;
temp=temp1->link;
while(temp!=NULL)
{ free(temp1);
temp1=temp;
temp=temp->link;
}
free(temp1);
first=last=NULL;

bca=fopen("fee_bca","w");
bba=fopen("fee_bba","w");
bsc=fopen("fee_bsc","w");
bed=fopen("fee_bed","w");
bcom=fopen("fee_bcom","w");
fprintf(bca,"\t\t\t\tCLASS: BCA\nName\t\tFather's name\t\tDeposit\t\tBalance money\n");
fprintf(bba,"\t\t\t\tCLASS: BBA\nName\t\tFather's name\t\tDeposit\t\tBalance money\n");
fprintf(bsc,"\t\t\t\tCLASS: BSC\nName\t\tFather's name\t\tDeposit\t\tBalance money\n");
fprintf(bcom,"\t\t\t\tCLASS: B.COM\nName\t\tFather's name\t\tDeposit\t\tBalance money\n");
fprintf(bed,"\t\t\t\tCLASS: B.ED\nName\t\tFather's name\t\tDeposit\t\tBalance money\n");

do
{
clrscr();
printf ("±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±± WELCOME ±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±\n");
printf ("\n\t\t\t\tCreat a new file\n");
newadd=(struct node *)malloc(sizeof(struct node));
   if (newadd==NULL)
    { printf("list is overflow");
      getch();
    return(0);
    }
fflush(stdin);
printf("Enter the student name=");
gets(newadd->name);
fflush(stdin);
printf("\nEnter the Father name of student=");
gets(newadd->fname);
printf("\nEnter the amount of fee deposit=");
scanf("%u",&newadd->deposit);
printf("\n\n(donot write any special caracter)");
printf("\nEnter the student class name=");
scanf("%s",&newadd->c);
strlwr(newadd->c);
if (first==NULL)
   { first=last=newadd;
     last->link=NULL;
    }
   else
   {
   last->link=newadd;
   last=newadd;
   last->link=NULL;
   }



if(!(strcmpi(newadd->c,"bca")))
{if(newadd->deposit>=fixfee[0])
 newadd->leftm=0;
else
newadd->leftm=fixfee[0]-newadd->deposit;
fprintf(bca,"%s%25s%18u%15u\n",newadd->name,newadd->fname,newadd->deposit,newadd->leftm);
}

else if (!(strcmpi(newadd->c,"bba")))
{if(newadd->deposit>=fixfee[3])
 newadd->leftm=0;
else
newadd->leftm=fixfee[3]-newadd->deposit;
fprintf(bba,"%s%25s%18u%15u\n",newadd->name,newadd->fname,newadd->deposit,newadd->leftm);
}

else if (!(strcmpi(newadd->c,"bcom")))
{if(newadd->deposit>=fixfee[1])
 newadd->leftm=0;
else
newadd->leftm=fixfee[1]-newadd->deposit;
fprintf(bcom,"%s%25s%18u%15u\n",newadd->name,newadd->fname,newadd->deposit,newadd->leftm);
}

else if (!(strcmpi(newadd->c,"bed")))
{if(newadd->deposit>=fixfee[4])
 newadd->leftm=0;
else
newadd->leftm=fixfee[4]-newadd->deposit;
fprintf(bed,"%s%25s%18u%15u\n",newadd->name,newadd->fname,newadd->deposit,newadd->leftm);
}

else if(!(strcmpi(newadd->c,"bsc")))
{if(newadd->deposit>=fixfee[2])
 newadd->leftm=0;
else
newadd->leftm=fixfee[2]-newadd->deposit;
fprintf(bsc,"%s%25s%18u%15u\n",newadd->name,newadd->fname,newadd->deposit,newadd->leftm);
}
printf ("\npress 1 for continue....");
scanf("%d",&j);
}while(j==1);
printf ("\n\tList has been created \n\tif you want to see than select 'show the file'");
printf ("\npress any key");
fclose(bca);
fclose(bba);
fclose(bsc);
fclose(bed);
fclose(bcom);
getch();
}

int add2()
{
int j;

bca=fopen("fee_bca","a+");
bba=fopen("fee_bba","a+");
bsc=fopen("fee_bsc","a+");
bed=fopen("fee_bed","a+");
bcom=fopen("fee_bcom","a+");

if(first==NULL)
{fprintf(bca,"\t\t\t\tCLASS: BCA\nName\t\tFather's name\t\tDeposit\t\tBalance money\n");
fprintf(bba,"\t\t\t\tCLASS: BBA\nName\t\tFather's name\t\tDeposit\t\tBalance money\n");
fprintf(bsc,"\t\t\t\tCLASS: BSC\nName\t\tFather's name\t\tDeposit\t\tBalance money\n");
fprintf(bcom,"\t\t\t\tCLASS: B.COM\nName\t\tFather's name\t\tDeposit\t\tBalance money\n");
fprintf(bed,"\t\t\t\tCLASS: B.ED\nName\t\tFather's name\t\tDeposit\t\tBalance money\n");
}
do
{
clrscr();
printf ("±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±± WELCOME ±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±\n");
printf ("\n\t\t\t\tAdd many member in the file\n");
newadd=(struct node *)malloc(sizeof(struct node));
   if (newadd==NULL)
    { printf("list is overflow");
      getch();
    return(0);
    }
fflush(stdin);
printf("Enter the student name=");
gets(newadd->name);
fflush(stdin);
printf("\nEnter the Father name of student=");
gets(newadd->fname);
printf("\nEnter the amount of fee deposit=");
scanf("%u",&newadd->deposit);

printf("\n\n(donot write any special caracter)");
printf("\nEnter the student class name=");
scanf("%s",&newadd->c);
strlwr(newadd->c);
if (first==NULL)
   { first=last=newadd;
     last->link=NULL;
    }
   else
   {
   last->link=newadd;
   last=newadd;
   last->link=NULL;
   }
if(!(strcmpi(newadd->c,"bca")))
{
if(newadd->deposit>=fixfee[0])
 newadd->leftm=0;
else
newadd->leftm=fixfee[0]-newadd->deposit;
fprintf(bca,"%s%25s%18u%15u\n",newadd->name,newadd->fname,newadd->deposit,newadd->leftm);
}

else if (!(strcmpi(newadd->c,"bba")))
{if(newadd->deposit>=fixfee[3])
 newadd->leftm=0;
else
newadd->leftm=fixfee[3]-newadd->deposit;
fprintf(bba,"%s%25s%18u%15u\n",newadd->name,newadd->fname,newadd->deposit,newadd->leftm);
}

else if (!(strcmpi(newadd->c,"bcom")))
{if(newadd->deposit>=fixfee[1])
 newadd->leftm=0;
else
newadd->leftm=fixfee[1]-newadd->deposit;
fprintf(bcom,"%s%25s%18u%15u\n",newadd->name,newadd->fname,newadd->deposit,newadd->leftm);
}

else if (!(strcmpi(newadd->c,"bed")))
{if(newadd->deposit>=fixfee[4])
 newadd->leftm=0;
else
newadd->leftm=fixfee[4]-newadd->deposit;
fprintf(bed,"%s%25s%18u%15u\n",newadd->name,newadd->fname,newadd->deposit,newadd->leftm);
}

else if(!(strcmpi(newadd->c,"bsc")))
{if(newadd->deposit>=fixfee[2])
 newadd->leftm=0;
else
newadd->leftm=fixfee[2]-newadd->deposit;
fprintf(bsc,"%s%25s%18u%15u\n",newadd->name,newadd->fname,newadd->deposit,newadd->leftm);
}
printf ("\npress 1 for continue....");
scanf("%d",&j);
}while(j==1);
printf ("\n\tList has been created \n\tif you want to see than select 'show the file'");
printf ("\npress any key");
fclose(bca);
fclose(bba);
fclose(bsc);
fclose(bed);
fclose(bcom);
getch();
}

int add()
{
clrscr();
printf ("±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±± WELCOME ±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±\n");
printf ("\n\t\t\tAdd only one member in the file\n");
newadd=(struct node *)malloc(sizeof(struct node));
   if (newadd==NULL)
    { printf("list is overflow");
	getch();
     return(0);
    }
fflush(stdin);
printf("Enter the student name=");
gets(newadd->name);
fflush(stdin);
printf("\nEnter the Father name of student=");
gets(newadd->fname);
printf("\nEnter the amount of fee deposit=");
scanf("%d",&newadd->deposit);

printf("\n\n(donot write any special caracter)");
printf("\nEnter the student class name=");
scanf("%s",&newadd->c);
strlwr(newadd->c);

if(first==NULL)
{first=last=newadd;
last->link=NULL;
}
else
{newadd->link=first;
first=newadd;
}

bca=fopen("fee_bca","a+");
bba=fopen("fee_bba","a+");
bsc=fopen("fee_bsc","a+");
bed=fopen("fee_bed","a+");
bcom=fopen("fee_bcom","a+");

if (first==NULL)
{
fprintf(bca,"\t\t\t\tCLASS: BCA\nName\t\tFather's name\t\tDeposit\t\tBalance money\n");
fprintf(bba,"\t\t\t\tCLASS: BBA\nName\t\tFather's name\t\tDeposit\t\tBalance money\n");
fprintf(bsc,"\t\t\t\tCLASS: BSC\nName\t\tFather's name\t\tDeposit\t\tBalance money\n");
fprintf(bcom,"\t\t\t\tCLASS: B.COM\nName\t\tFather's name\t\tDeposit\t\tBalance money\n");
fprintf(bed,"\t\t\t\tCLASS: B.ED\nName\t\tFather's name\t\tDeposit\t\tBalance money\n");
}

if(!(strcmpi(newadd->c,"bca")))
{
if(newadd->deposit>=fixfee[0])
 newadd->leftm=0;
else
newadd->leftm=fixfee[0]-newadd->deposit;
fprintf(bca,"%s%25s%18u%15u\n",newadd->name,newadd->fname,newadd->deposit,newadd->leftm);
}

else if (!(strcmpi(newadd->c,"bba")))
{if(newadd->deposit>=fixfee[3])
 newadd->leftm=0;
else
newadd->leftm=fixfee[3]-newadd->deposit;
fprintf(bba,"%s%25s%18u%15u\n",newadd->name,newadd->fname,newadd->deposit,newadd->leftm);
}

else if (!(strcmpi(newadd->c,"bcom")))
{if(newadd->deposit>=fixfee[1])
 newadd->leftm=0;
else
newadd->leftm=fixfee[1]-newadd->deposit;
fprintf(bcom,"%s%25s%18u%15u\n",newadd->name,newadd->fname,newadd->deposit,newadd->leftm);
}

else if (!(strcmpi(newadd->c,"bed")))
{if(newadd->deposit>=fixfee[4])
 newadd->leftm=0;
else
newadd->leftm=fixfee[4]-newadd->deposit;
fprintf(bed,"%s%25s%18u%15u\n",newadd->name,newadd->fname,newadd->deposit,newadd->leftm);
}

else if(!(strcmpi(newadd->c,"bsc")))
{if(newadd->deposit>=fixfee[2])
 newadd->leftm=0;
else
newadd->leftm=fixfee[2]-newadd->deposit;
fprintf(bsc,"%s%25s%18u%15u\n",newadd->name,newadd->fname,newadd->deposit,newadd->leftm);
}
printf ("\nThe new data has been save \nif you want to check\nthan select option 'show the file'");
printf ("\npress any key");
fclose(bca);
fclose(bba);
fclose(bsc);
fclose(bed);
fclose(bcom);
getch();
}



int show()
{ int n;char cl[6];
c:
clrscr();
printf ("±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±± WELCOME ±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±\n");
printf ("\n\t\t\t\tShow the file\n");
printf("\tSelect the class:\n");
printf("  BCA\n  BBA\n  BSC\n  B.com\n  B.ed\n  Back");
printf("\n\n\t\tPlease use 'k' to move curser downword and 'i' for upword");
n=curser(6,1,5);
 if(n==6)
return(0);
else if(n==1)
strcpy(cl,"bca");
else if(n==2)
strcpy(cl,"bba");
else if(n==3)
strcpy(cl,"bsc");
else if(n==4)
strcpy(cl,"bcom");
else if(n==5)
strcpy(cl,"bed");
clrscr();
printf ("±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±± WELCOME ±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±\n");
printf ("\n\t\t\t\tShow the file\n");
printf ("\n\t\t\t the list of fee Defaulter of class %s\n",strupr(cl));
printf ("\nName\t\tfather's name\t\tDeposit\t\tBalancefee\n\n");
temp=first;
while(temp!=NULL)
{
if(!(strcmpi(temp->c,cl)))
{
printf("%s",temp->name);
printf("%25s",temp->fname);
printf("%18u",temp->deposit);
printf("%15u\n",temp->leftm);
}
temp=temp->link;
}
if(!(strcmpi(cl,"bca")))
printf("\n\nFixfee=%d",fixfee[0]);
else if(!(strcmpi(cl,"bcom")))
printf("\n\nFixfee=%d",fixfee[1]);
else if(!(strcmpi(cl,"bsc")))
printf("\n\nFixfee=%d",fixfee[2]);
else if(!(strcmpi(cl,"bba")))
printf("\n\nFixfee=%d",fixfee[3]);
else if(!(strcmpi(cl,"bed")))
printf("\n\nFixfee=%d",fixfee[4]);
printf("\n\npress any key");
getch();
goto c;
}

int del()
{
char n[30],cl2[6];
int n1,f1;
fflush(stdin);
printf ("\nEnter the name of student to delete=");
gets(n);
fflush(stdin);
printf("\nEnter the class of student to delete=");
gets(cl2);
strlwr(cl2);
temp=first;
while(temp!=NULL)
{
n1=strcmpi(temp->name,n);
f1=strcmpi(temp->c,cl2);
if (n1==0 && f1==0)
  {  if (temp==first)
       {temp1=first;
	first=first->link;
	free(temp1);
       break;
       }
    else if (temp==last)
       { temp1=first;
	 while(temp1->link!=last)
	  temp1=temp1->link;
	  free(last);
	  last=temp1;
	  last->link=NULL;
	 break;
       }
    else
      { temp1=first;
       while(temp1->link!=temp)
       temp1=temp1->link;
       temp1->link=temp->link;
       free(temp);
       break;
      }
  }
temp=temp->link;
}
if (temp==NULL)
printf("\n\nThe data is not found in the list");
else
{printf ("\n\tThe Data will be deleted \nif you want to check\nthan select option 'show the file'");
fflush(stdin);
bca=fopen("fee_bca","w");
bba=fopen("fee_bba","w");
bsc=fopen("fee_bsc","w");
bed=fopen("fee_bed","w");
bcom=fopen("fee_bcom","w");
temp1=first;
fprintf(bca,"\t\t\t\tCLASS: BCA\nName\t\tFather's name\t\tDeposit\t\tBalance money\n");
fprintf(bba,"\t\t\t\tCLASS: BBA\nName\t\tFather's name\t\tDeposit\t\tBalance money\n");
fprintf(bsc,"\t\t\t\tCLASS: BSC\nName\t\tFather's name\t\tDeposit\t\tBalance money\n");
fprintf(bcom,"\t\t\t\tCLASS: B.COM\nName\t\tFather's name\t\tDeposit\t\tBalance money\n");
fprintf(bed,"\t\t\t\tCLASS: B.ED\nName\t\tFather's name\t\tDeposit\t\tBalance money\n");


while(temp1!=NULL)
{
if(!(strcmpi(temp1->c,"bca")))
fprintf(bca,"%s%25s%18u%15u\n",temp1->name,temp1->fname,temp1->deposit,temp1->leftm);
else if (!(strcmpi(temp1->c,"bba")))
fprintf(bca,"%s%25s%18u%15u\n",temp1->name,temp1->fname,temp1->deposit,temp1->leftm);
else if (!(strcmpi(temp1->c,"bcom")))
fprintf(bca,"%s%25s%18u%15u\n",temp1->name,temp1->fname,temp1->deposit,temp1->leftm);
else if (!(strcmpi(temp1->c,"bed")))
fprintf(bca,"%s%25s%18u%15u\n",temp1->name,temp1->fname,temp1->deposit,temp1->leftm);
else if(!(strcmpi(temp1->c,"bsc")))
fprintf(bca,"%s%25s%18u%15u\n",temp1->name,temp1->fname,temp1->deposit,temp1->leftm);
temp1=temp1->link;
}
fclose(bca);
fclose(bba);
fclose(bsc);
fclose(bed);
fclose(bcom);
}
getch();
}

int curser(int maxitem, short int x,short int y)
{ int i=1,j;
char ch;
fflush(stdin);
do
{
gotoxy(x,y);
for(j=1;j<=maxitem+1;j++)
{ if(j==i)
  printf("¯");
  else
  printf(" \n");
}
fflush(stdin);
ch=getch();
if(ch=='i')
{ if(i==1)
 i=maxitem;
 else
 i=i-1;
}
else if(ch=='k')
{ if(i==maxitem)
  i=1;
  else
  i=i+1;
}

}while(ch!=13);
return(i);
}

short int pass(short int n)
{
FILE *p1;
char p[15],ip[15];
short int l;
p1=fopen("prot","r+");
if(p1==NULL)
{printf("problem");
return(0);
}
if(fgetc(p1)==EOF || n==1)
{
fclose(p1);
p1=fopen("prot","w");
printf("\nplease set the password (10 char not allow backspace) :\n");
gets(p);
fprintf(p1,"%s",p);
fclose(p1);
return(0);
}
else
{
rewind(p1);
fscanf(p1,"%s",p);
fclose(p1);
}

fflush(stdin);
//scanf("%s",&ip);
gets(ip);
if(!strcmpi(p,ip))
l=1;
else
l=0;
return(l);
}
