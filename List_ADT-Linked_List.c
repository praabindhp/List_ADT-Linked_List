#include<stdio.h>
#include<alloca.h>
#include<stdlib.h>
struct Node
{ int data;
struct Node *Next;
};
typedef struct Node *PtrToNode;
typedef PtrToNode LIST;
typedef PtrToNode POSITION;
int IsEmpty(LIST L)
{
return L->Next==NULL;
}
LIST createlist()
{
LIST L;
L=(struct Node *)malloc(sizeof(struct Node));
if(L==NULL)
printf("fatal error");
else
{ L->data=-1;
L->Next=NULL;
}
return L;
}
void Insert(int x,POSITION P)
{
PtrToNode Temp;
Temp=(struct Node*)malloc(sizeof(struct Node));
if(Temp==NULL)
printf("fatal error");
else
{
Temp->data=x;
Temp->Next=P->Next;
P->Next=Temp;
}
}
POSITION FindPrevious(int x,LIST L)
{
POSITION P;
P=L;
while(P->Next !=NULL && P->Next->data!=x)
P=P->Next;
return P;
}
int IsLast(POSITION P)
{
return P->Next==NULL;
}
void Delete(int x,LIST L)
{
POSITION P, Tempcell;
P=FindPrevious(x,L);
if(!IsLast(P))
{
Tempcell=P->Next;
P->Next=Tempcell->Next;
free(Tempcell);
}
}
void MakeEmpty(LIST L)
{
if(L==NULL)
printf("list is not created");
else
{
while(!IsEmpty(L))
Delete(L->Next->data,L);
}
}
POSITION Find(int x,LIST L)
{
POSITION Temp;
Temp=L;
while(Temp!=NULL)
{
if(Temp->data==x)
return Temp;
Temp=Temp->Next;
}
return Temp;
}
void Display(LIST L)
{
L=L->Next;
while(L!=NULL)
{
printf("\n%d",L->data);
L=L->Next;

}
}
LIST Deletelist(LIST L)
{
MakeEmpty(L);
free(L);
L=NULL;
return L;
}
void main()
{
LIST L=NULL;
POSITION P;
char ch;
int n,x,y,z;
printf("\n\n1.Create \n2.Insert \n3.Delete \n4.MakeEmpty \n5.Find \n6.IsEmpty \n7.Display \n8.Deletelist \n9.Exit\n");
A:
printf("\nEnter ur option:\t");
scanf("%d",&n);
switch(n)
{
case 1:
if(L==NULL)
{
L=createlist();
printf("\nList is created\t");
}
else
printf("\nList is already created");
break;
case 2:
if(L==NULL)
printf("\nList is not created");
else
{
printf("\nEnter the value:\t");
scanf("%d",&x);
if(L->Next==NULL)
Insert(x,L);
else
{
printf("\nWhere u want to insert:\t");
scanf("%d",&y);
P=Find(y,L);

if(P!=NULL)
Insert(x,P);
else
printf("\nElement not in the list");
}
}
break;
case 3:
if(L==NULL)
printf("\nList is not yet created");
else if(L->Next==NULL)
printf("List is empty");
else
{
printf("\nEnter the value to delete:\t");
scanf("%d",&y);
Delete(y,L);
}
break;
case 4:
if(L==NULL)
printf("\nList is not yet created");
else
{
if(L->Next==NULL)
printf("\nList is empty");
else
MakeEmpty(L);
printf("\n\n Now list is Empty");
}
break;
case 5:
if(L==NULL)
printf("\nList is not created");
else
{
if(L->Next==NULL)
printf("\nList is empty");
else
{
printf("\nEnter the value to find:\t");
scanf("%d",&z);
P=Find(z,L);
if(P==NULL)
printf("\nElement is not in the list");
else
printf("\nElement present in the list");
}
}
break;
case 6:
if(L==NULL)
printf("\nList is not created");
else if(IsEmpty(L))
printf("\nList is empty");
else
printf("\nList contains some elements");
break;
case 7:
if(L==NULL)
printf("\nList is empty");
else
Display(L);
break;
case 8:
if(L==NULL)
printf("\n List is empty");
else
{
L=Deletelist(L);
printf("\n\n List is deleted");
}
break;
case 9:
exit(0);
default:
printf("\n\n\t\t....WRONG ENTRY....");
}
goto A;
}