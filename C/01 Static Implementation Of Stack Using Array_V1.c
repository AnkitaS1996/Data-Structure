#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

#define Max 7 //Element Capacity of stack

int Stack[Max] = {0}; //Declare - Create Stack
int Top = -1;

void push(int iNo);
int Is_Stack_Full();
void pop();
int Is_Stack_Empty();
void Display_Stack();

int main()
{
    push(20);
    push(30);
    push(55);
    pop();
    _getch();
    Display_Stack();
    _getch();
    system("cls");
    push(40);
    push(84);
    push(22);
    push(65);
    push(61);
    push(10);
    Display_Stack();
    _getch();
    pop();
    pop();
    Display_Stack();
    _getch();
    return 0;
}

void push(int iNo)
{
    int Return = Is_Stack_Full();
    if(1 == Return)
    {
        printf("\n stack is already Full..Cannot Insert New Element");
    }
    else
    {
        Stack[Top+1] = iNo;
        //Top++;
        printf("\n Element %d Inserted in Stack Successfully",iNo);
        Top++;
    }
}

int Is_Stack_Full()
{
    if(Top+1 == Max)
    {
        return 1;
    }
    return 0;
}
void pop()
{
    int Ret = Is_Stack_Empty();
    if(1 == Ret)
    {
        printf("\n Stack is Already Empty");
    }
    else
    {
        printf("\n Removed Element From Stack is = %d",Stack[Top]);
        Top--;
    }
    return;
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
        printf("\n Stack is Already Empty.. No Elements Display.");
    }
    else
    {
        printf("\n\n Display Stack Element Are ==> \n");
        int i = 0;
        while(i < Top+1)
        {
            printf("\n\t\t | %d |",Stack[i]);
            i++;
        }
    }
    return;
}

