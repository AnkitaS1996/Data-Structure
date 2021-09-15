#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

struct Node
{
    int Data;
    struct Node *Next;
};

void Insert_At_Position(struct Node**, int,int);
void Insert_First(struct Node**,int);
void Insert_Last(struct Node**,int);
int Count_Link_List_Element(struct Node*);
void Display_Link_List(struct Node*);

int main()
{
    struct Node *Head = NULL;
    Insert_First(&Head,11);
    Insert_First(&Head,10);
    Display_Link_List(Head);
    printf("\n\n Count Of Link List Elements Are ==> %d.",Count_Link_List_Element(Head));
    _getch();
    Insert_At_Position(&Head,100,7);
    Insert_At_Position(&Head,200,1);
    Insert_At_Position(&Head,300,0);
    Insert_At_Position(&Head,400,4);
    Insert_At_Position(&Head,500,2);
    Insert_At_Position(&Head,600,3);
    Display_Link_List(Head);
    printf("\n\n Count Of Link List Elements Are ==> %d.",Count_Link_List_Element(Head));
    _getch();
    return 0;
}
void Insert_At_Position(struct Node **First,int Element,int Pos)
{
    int Cnt = Count_Link_List_Element(*First);

    if(Pos <= 0 || Pos > Cnt+1)
    {
        printf("\n\n Element is %d And Position Of Element is %d Invalid Position.",Element,Pos);
    }
    else if(Pos == 1)
    {
        Insert_First(First,Element);
    }
    else if(Pos == Cnt+1)
    {
        Insert_Last(First,Element);
    }
    else
    {
        struct Node *NewN = NULL;
        struct Node *Temp = *First;
        NewN = (struct Node*)malloc(sizeof(struct Node));
        if(NULL == NewN)
        {
            printf("\n Some Memory Level Issue..");
            return;
        }
        NewN -> Data = Element;
        NewN -> Next = NULL;
        while(Pos > 2)
        {
            Temp = Temp -> Next;
            Pos--;
        }
        NewN->Next = Temp->Next;
        Temp->Next = NewN;
    }
    return;
}
void Insert_First(struct Node **First,int Element)
{
    struct Node *NewN = NULL;
    NewN = (struct Node*)malloc(sizeof(struct Node));
    if(NULL == NewN)
    {
        printf("\n Memory Level Issue..");
    }
    NewN -> Data = Element;
    NewN -> Next = NULL;
    if(NULL == *First)
    {
        *First = NewN;
    }
    else
    {
        NewN -> Next = *First;
        *First = NewN;
    }
    //printf("\n Elements %d Inserted Successfully.",NewN->Data);
    return;
}
void Insert_Last(struct Node **First,int Element)
{
    struct Node *NewN = NULL;
    NewN = (struct Node*) malloc (sizeof(struct Node));
    if(NULL == NewN)
    {
        printf("\n Node Don't Created some Memory Level Issue..");
    }
    NewN -> Data = Element;
    NewN -> Next = NULL;
    if(NULL == *First)
    {
        *First = NewN;
    }
    else
    {
        struct Node *Temp = *First;
        while(Temp -> Next != NULL)
        {
            Temp = Temp -> Next;
        }
        Temp -> Next = NewN;
    }
    printf("\n %d Element %d Inserted Successfully.",NewN->Data);
}
int Count_Link_List_Element(struct Node *First)
{
    int Cnt = 0;
    if(NULL != First)
    {
        while(First != NULL)
        {
            First = First -> Next;
            Cnt++;
        }
    }
    return Cnt;
}
void Display_Link_List(struct Node *First)
{
    if(NULL == First)
    {
        printf("\n Node Creation Denied..Some Memory Level issue..");
    }
    else
    {
        printf("\n\n Display Link List Are => ");
        while(First != NULL)
        {
            printf("| %d |-> ",First->Data);
            First = First -> Next;
        }
        printf("NULL");
    }
}



