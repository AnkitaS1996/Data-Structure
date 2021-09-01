#include<stdio.h>
#include<conio.h>
#define MAX 7

int Queue[MAX] = {0};
int Rear = 0, Front = 0,i = 0;

void Enqueue(int Ele);
int Is_Queue_Full();
void Dequeue();
int Is_Queue_Empty();
void Display_Queue();

int main()
{
   Dequeue();
    Enqueue(10);
    Enqueue(20);
    Enqueue(30);
    Dequeue();
    Dequeue();
    Enqueue(600);
    Enqueue(50);
    Display_Queue();
    Dequeue();
    Enqueue(800);
    Enqueue(300);
    Display_Queue();
    Dequeue();
    Enqueue(90);
    Enqueue(100);
    Display_Queue();
    _getch();
    return 0;
}

void Enqueue(int Ele)
{
    if(Is_Queue_Full())
    {
        printf("\n Queue is Already Full.. Element %d is Can't Inserted in Enqueue.",Ele);
    }
    else
    {
        Queue[Rear] = Ele;
        Rear++;
        printf("\n Element %d is Inserted Successfully.",Ele);
    }
    return;
}
int Is_Queue_Full()
{
    if(MAX == Rear)
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
        printf("\n Queue is Already Empty.. Can't Dequeue Elements.");
    }
    else
    {
        printf("\n Element %d is Dequeue.",Queue[Front]);
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
        printf("\n Queue is Already Empty..Can't Display Element Queue.");
    }
    else
    {
        printf("\n =====**** Display Elements Are ****=====\n");
        for(i = Front;i < Rear;i++)
        {
            printf("\t| %4d |",Queue[i]);
        }
    }
    return;
}

