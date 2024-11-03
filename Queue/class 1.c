#include<stdio.h>
#define max 10
int Queue[max],rear=-1,front=0;
void insert()
{
    if(rear==max)
    {
        printf("array over");
    }
    else
    {
        printf("Enter your element");
        scanf("%d",&Queue[++rear]);
    }
}

void deleteed()
{
    if(front>rear)
    {
        printf("Queue is empty\n");
    }
    else
    {
        printf("Deleted element is %d \n",Queue[front++]);
    }
}

void display()
{
    if(front>rear)
    {
        printf("Queue is an empty");
    }
    else
    {
        printf("Queue element are :");
        for(int i=rear; i>=front;i--)
        {
            printf("%d \n",Queue[i]);
        }
    }
}
void main()
{
    int x=0;
    do
    {
        printf("-----Queue------");
        printf("1 for insert \n 2 for delete \n 3 for display \n 4 for exit \n Enter your choice:");
        scanf("%d",&x);
        switch(x)
        {
            case 1: insert(); break;
            case 2: deleteed();break;
            case 3: display();break;
        }
    }while(x!=4);
}


