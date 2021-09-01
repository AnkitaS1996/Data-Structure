#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#define Size 7

int Queue[Size] = {0};
int Rear = 0, Front = 0,i = 0;

void Enqueue(int Ele);
int Is_Queue_Full();
void Dequeue();
int Is_Queue_Empty();
void Display_Queue();
int Is_Count_Queue();
void Is_Queue_Peek();
void Is_Search_Queue_Element();

int main()
{
    int Choice = 0,No = 0;
    for(;;)
    {
        printf("\n ======***** Static Queue Implementation *****======\n");
        printf("\n======================================================\n");
        printf("\n\t 1. Enqueue Elements Of Queue.");
        printf("\n\t 2. Dequeue Elements Of Queue.");
        printf("\n\t 3. Display Elements Of Queue.");
        printf("\n\t 4. Count Elements Of Queue.");
        printf("\n\t 5. Top Elements Of Queue.");
        printf("\n\t 6. Search Elements Of Queue.");
        printf("\n\t 7. Exit. \n");
        printf("\n======================================================\n");
        printf("\n Enter Your Choice : ");
        scanf("%d",&Choice);
        printf("\n======================================================\n");
        switch(Choice)
        {
            case 1:
                printf("\n Enter Elements Of Queue : ");
                scanf("%d",&No);
                Enqueue(No);
                _getch();
                system("cls");
                break;
            case 2:
                Dequeue();
                _getch();
                system("cls");
                break;
            case 3:
                Display_Queue();
                _getch();
                system("cls");
                break;
            case 4:
                printf("\n Count Elements Of Queue is %d.",Is_Count_Queue());
                _getch();
                system("cls");
                break;
            case 5:
                Is_Queue_Peek();
                _getch();
                system("cls");
                break;
            case 6:
                Is_Search_Queue_Element();
                _getch();
                system("cls");
                break;
            case 7:
                fflush(stdin);
                printf("\n Are You Sure Close Application...\n Press YES / NO : ");
                char ch = getchar();
                fflush(stdin);
                if(ch == 'Y' || ch == 'y')
                {
                    goto DWN;
                }
                system("cls");
                break;
            default:
                printf("\n Invalid Choice...!!");
                _getch();
                system("cls");
                break;

        }
    }
    DWN:
        printf("\n Thank You For Using Application Of Queue..\n");
        printf("\n Press Any Key To Continue..\n");
        printf("\n ======================================================== \n");
    _getch();
    return 0;
}
void Enqueue(int Ele)
{
    if(Is_Queue_Full())
    {
        printf("\n Queue Of Element is Already Full..Can't Inserted New Elements = %d.",Ele);
    }
    else
    {
        Queue[Rear] = Ele;
        Rear++;
        printf("\n Queue Element %d is Successfully Inserted.",Ele);
    }
    return;
}

int Is_Queue_Full()
{
    if(Rear==Size)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void Dequeue()
{
    if(Is_Queue_Empty())
    {
        printf("\n Queue is Already Empty.. Can Inserted New Elements");
    }
    else
    {
        printf("\n Dequeue Elements is %d.",Queue[Front]);
        Queue[Front] = 0;
        Front++;
    }
    return;
}

int Is_Queue_Empty()
{
    if(Front == Rear)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void Display_Queue()
{
    if(Is_Queue_Empty())
    {
        printf("\n Queue is Empty Can't Display Elements.");
    }
    else
    {
        printf("\n Queue Of Element Display Are ==> \n");
        for(i = Front;i < Rear;i++)
        {
            printf("\t | %2d |",Queue[i]);
        }
    }
    return;
}

int Is_Count_Queue()
{
    if(Is_Queue_Empty())
    {
        printf("\n Queue is Empty Can't Count Elements in Queue..");
    }
    else
    {
        return Rear - Front;
    }
}

void Is_Search_Queue_Element()
{
    int Srch_Ele = 0;
    if(Is_Queue_Empty())
    {
        printf("\n Queue is Empty Can't Search Elements.");
    }
    else
    {
        printf("\n Enter Elements To Search : ");
        scanf("%d",&Srch_Ele);

        for(i = Front;i < Rear;i++)
        {
            if(Srch_Ele == Queue[i])
            {
                break;
            }
        }
        if( i == Rear)
        {
            printf("\n Search Elements %d is Not Found.",Srch_Ele);
        }
        else
        {
            printf("\n Search Elements %d is Found At Location is %d",Srch_Ele,i+1);
        }
    }
}

void Is_Queue_Peek()
{
    if(Is_Queue_Empty())
    {
        printf("\n Queue is Empty Top Element is Not Found.");
    }
    else
    {
        printf("\n Top Elements Of Queue is %d.",Queue[Front]);
    }
    return;
}

