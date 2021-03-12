#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
struct Node
{
    int Data;
    struct Node*Next;
};

void Insert_At_First(struct Node **First,int Num)
{
    struct Node *NewN=NULL;        //Creating Pointer For New Node

    NewN = (struct Node*)malloc(sizeof(struct Node));  //Allocation Dynamic Memory for New Node in DataSection By Malloc

    NewN->Data=Num;              //Setting Values Of New Node
    NewN->Next=NULL;

    //*First=NewN;             //Setting Values Of New Node
    if(NULL == *First)          //Only Once Means for inserting Very First Element in LinkList
    {
        *First=NewN;
        printf("\n Link List is Already Empty...!! Inside Block Inserted First\n");
        getch();
    }
    else                   //Works For Every Next Element i.e Form 2nd Element OnWords
    {
        NewN->Next=*First;
        *First = NewN;
    }
    printf("\n %d Element Inserted Element Successfully..!!\n",Num);
}

void Display_Link_List(struct Node *First)
{
    if(NULL == First)
    {
        printf("\n Given Link List is Empty...!!\n");
    }
    else
    {
        printf("\n\n Element in Given Link List Are => \n\n");
        while(First!=NULL)
        {
            printf("\t | %d |",First->Data);
            First=First->Next;
        }
        printf("NULL|");
    }
}

int main()
{
    int No = 21;
    struct Node*Head=NULL;

    Insert_At_First(&Head,No);
    Insert_At_First(&Head,75);
    Insert_At_First(&Head,80);

    getch();
    system("cls");

    Display_Link_List(Head);
    getch();

    printf("\n Thank You....!!!");
    getch();
    return 0;
}
