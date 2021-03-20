#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
struct Node
{
    int Data;
    struct Node *Next;
};

void Insert_First(struct Node **First,int iNo)
{
    struct Node *NewN = NULL;
    NewN = (struct Node*)malloc(sizeof(struct Node));
    NewN->Data = iNo;
    NewN->Next = NULL;
    if(NULL==*First)
    {
        *First = NewN;
        //printf("\n Insert if Block Of Insert First.");
    }
    else
    {
        NewN->Next = *First;
        *First = NewN;
    }
    printf("\n %d Inserted Elements At First Position Successfully.\n",NewN->Data);
    return;
}

void Insert_Last(struct Node **First,int iNo)
{
    struct Node *NewN = NULL;
    NewN = (struct Node*)malloc(sizeof(struct Node));
    NewN->Data=iNo;
    NewN->Next=NULL;
    if(NULL == *First)
    {
        *First = NewN;
       // printf("\n Inserted If Block Last First");
    }
    else
    {
        struct Node *Temp = *First;
        while(Temp->Next != NULL)
        {
            Temp=Temp->Next;
        }
        Temp->Next=NewN;
    }
    printf("\n %d Elements Inserted At Last Position Successfully.\n",NewN->Data);
    return;
}

void Display_Link_List(struct Node *First)
{
    if(NULL == First)
    {
        printf("\n Given Link List is Empty..\n");
    }
    else
    {
        printf("\n Elements Of Given Link List Are =>> \n");
        printf("\n");
        while(First != NULL)
        {
            printf("\t |%d|",First->Data);
            First = First->Next;
        }
        printf("NULL");
    }
    return;
}

void Delete_First(struct Node **First)
{
    if(NULL == *First)
    {
        printf("\n Link List Already Empty..!!");
    }
    else
    {
        struct Node *Temp = *First;
        *First = Temp->Next;
        printf("\n\n Deleted First Elements in Link List is = %d\n",Temp->Data);
        free(Temp);
    }
    return;
}

void Delete_Last(struct Node **First)
{
   if(NULL == *First)
   {
       printf("\n Link List Already Empty...!!");
   }
   else
   {
       struct Node*Temp = *First;
       if(Temp->Next!=NULL)
       {
           while(Temp->Next->Next!=NULL)
           {
               Temp = Temp->Next;
           }
       }
       printf("\n Deleted Last Elements in Link List is = %d\n",Temp->Next->Data);
       free(Temp->Next);
       Temp->Next=NULL;
   }
   return;
}

int main()
{
    struct Node *Head = NULL;

    Display_Link_List(Head);
    getch();

    Insert_First(&Head,10);
    Insert_Last(&Head,30);
    Insert_First(&Head,50);
    Insert_Last(&Head,100);
    Insert_First(&Head,22);
    Insert_Last(&Head,98);
    getch();
    system("cls");
    getch();
    Display_Link_List(Head);
    getch();

    Delete_First(&Head);

    Display_Link_List(Head);
    printf("\n");
    getch();

    Delete_Last(&Head);

    Display_Link_List(Head);
    printf("\n");
    printf("\n Thank You...!!!");

    getch();
}
