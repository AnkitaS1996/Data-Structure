#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#define Max 10

int Stack[Max] = {0};
int Top = -1;
int Cnt = 0;

void Push(int No);
int Is_Stack_Empty();
int Pop(int item);
int Is_Stack_Full();
void Display_Stack();
int Count_Element_Of_Stack();
int Search_Element_Of_Stack();
void Is_Min_Stack_Element();
void Is_Max_Stack_Element();

int main()
{
    int Choice,Element;
    int Ret = 1;
    while(1 == Ret)
    {
        printf("\n 1. Push Elements : ");
        printf("\n 2. Pop Elements :");
        printf("\n 3. Display All Stack Elements");
        printf("\n 4. Count Of Stack Elements");
        printf("\n 5. Search Elements");
        printf("\n 6. Maximum Elements Of Stack");
        printf("\n 7. Minimum Elements Of Stack");
        printf("\n 8. Exit");

        printf("\n\n Enter Your Choice : ");
        scanf("%d",&Choice);

        switch(Choice)
        {
            case 1:
                printf("\n Enter the Elements to Push : ");
                scanf("%d",&Element);
                Push(Element);
                _getch();
                system("cls");
                break;
            case 2:
                Pop(Element);
                _getch();
                system("cls");
                break;

            case 3:
                Display_Stack();
                _getch();
                system("cls");
                break;
            case 4:
                Element = Count_Element_Of_Stack();
                printf("\n Number Of Count Elements Of Stack is = %d.",Element);
                _getch();
                system("cls");
                break;
            case 5:
                Search_Element_Of_Stack();
                _getch();
                system("cls");
                break;
            case 6:
                //printf("\n Maximum Element Of Stack is = %d.",Is_Max_Stack_Element());
                Is_Max_Stack_Element();
                _getch();
                system("cls");
                break;
            case 7:
                //printf("\n Minimum Element Of Stack is = %d.",Is_Min_Stack_Element());
                Is_Min_Stack_Element();
                _getch();
                system("cls");
                break;
            case 8:
                printf("\n Thank You For Visiting Application Of Stack Implementation.\n");
                printf("\n Press Any Key To Continue...!!!\n");
                exit(Ret);
                break;
            default:
                printf("\n Invalid Choice ....!!!");
                _getch();
                system("cls");
        }
    }
    _getch();
    return 0;
}

void Push(int No)
{
    int Ret = Is_Stack_Full();
    if(1 == Ret)
    {
        printf("\n Stack is Already Full..Cannot Push The Elements");
    }
    else
    {
        Stack[Top + 1] = No;
        printf("\n Stack Of Elements is %d is Successfully Inserted.",No);
        Top++;
    }
    return;
}

int Is_Stack_Full()
{
    if(Top + 1 == Max)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int Pop(int item)
{
    int Ret = Is_Stack_Empty();
    if(1 == Ret)
    {
        printf("\n Stack is Already Empty.. Push The New Elements..");
    }
    else
    {
        item = Stack[Top];
        printf("\n Pop The Elements Of Stack is = %d",item);
        Top--;
    }
    return item;
}

int Is_Stack_Empty()
{
    if(-1 == Top)
    {
        return 1;
    }
    return 0;
}

void Display_Stack()
{
    int Ret = Is_Stack_Empty();
    if(1 == Ret)
    {
        printf("\n No Display Elements ..Stack is Already Empty..");
    }
    else
    {
         printf("\n Display Stack Elements Are == >");
         for(Cnt = Top;Cnt >= 0;Cnt--)
         {
             printf("\n\t\t | %d |",Stack[Cnt]);
             //Cnt++;
         }
    }
    return;
}

int Count_Element_Of_Stack()
{
    if(Is_Stack_Empty())
    {
        printf("\n Stack is Already Empty.. Cannot Count Elements Of Stack");
    }
    else
    {
         return Top+1;
    }
}

void Is_Max_Stack_Element()
{
    int Max_Ele = 0;
    if(Is_Stack_Empty())
    {
        printf("\n Stack is Already Empty Cannot Find Maximum Elements..");
    }
    else
    {
        for(Cnt = 0;Cnt <= Top;Cnt++)
        {
            if(Stack[Cnt] > Max_Ele)
            {
                Max_Ele = Stack[Cnt];
            }
        }
        printf("\n Maximum Element Of Stack is = %d.",Max_Ele);
        //return Max_Ele;
    }
    return;
}

void Is_Min_Stack_Element()
{
    if(Is_Stack_Empty())
    {
        printf("\n Stack is Already Empty..cannot Find Minimum Elements Of Stack");
        return;
    }
    else
    {
        int Min_Ele = 0;
        for(Cnt = 0; Cnt <= Top;Cnt++)
        {
            if(Cnt == 0)
            {
                Min_Ele = Stack[Cnt];
            }
            if(Stack[Cnt] < Min_Ele)
            {
                Min_Ele = Stack[Cnt];
            }
        }
        printf("\n Minimum Element Of Stack is = %d.",Min_Ele);
    }
}

int Search_Element_Of_Stack()
{
    int Search_Element = 0;
    int Return = Is_Stack_Empty();
    if(1 == Return)
    {
        printf("\n Stack is Already Empty ... Cannot Search Element in Stack");
    }
    else
    {
        printf("\n Enter Element To Search in Stack ==> ");
        scanf("%d",&Search_Element);

        int i = 0;
        while(i <= Top)
        {
            if(Stack[i] == Search_Element)
            {
                break;
            }
            i++;
            //Top++;
        }
        if(i == Top+1)
        {
            printf("\n Given Elements %d is Not Found in Stack",Search_Element);
        }
        else
        {
            printf("\n Given Elements %d is Found At Stack And Location is = %d",Search_Element,i+1);
        }
    }
}
