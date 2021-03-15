#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
struct Node
{
    int Data;
    struct Node *Next;
};

void Insert_First(struct Node **First,int Num)
{
    struct Node *NewN = NULL;
    NewN = (struct Node*)malloc(sizeof(struct Node));

    NewN->Data=Num;
    NewN->Next=NULL;

    if(NULL==*First)
    {
        *First=NewN;

    }
    else
    {
        NewN->Next=*First;
        *First=NewN;
    }
    printf("\n %d Element Inserted First Successfully\n",NewN->Data);
}
void Insert_Last(struct Node **First,int Num)
{
    struct Node *NewN = NULL;
    NewN = (struct Node*)malloc(sizeof(struct Node));

    NewN->Data=Num;
    NewN->Next=NULL;

    if(NULL==*First)
    {
        *First=NewN;
    }
    else
    {
        struct Node *temp = *First;
        while(temp->Next != NULL)
        {
            temp=temp->Next;
        }
        temp->Next=NewN;
    }
    printf("\n\n %d Element Inserted at Last Position Successfully",NewN->Data);

}
void Display(struct Node *First)
{

    if(NULL==First)
    {
        printf("\n Given Link List is Empty");
    }
    else
    {
        printf("\n Element Of Given Link List Are => ");
        while(First!=NULL)
        {
            printf("\t |%d|",First->Data);
            First=First->Next;
        }
        printf(" NULL");
    }
    return;
}
int main()
{
    int No = 27;
    struct Node *Head = NULL;
    Display(Head);

    Insert_First(&Head,No);
    Insert_Last(&Head,85);
    Insert_First(&Head,30);
    Insert_Last(&Head,50);
    Insert_First(&Head,60);
    Insert_Last(&Head,90);

    getch();
    system("cls");

    Display(Head);

    printf("\n\n Thank You...!!");
    getch();
    return 0;
}
