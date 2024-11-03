#include<stdio.h>
#define max 10
int cq[max],front=-1,rear=-1;
void insert()
{
    if((rear+1)%max==rear)
    {
        printf("overflow circular queue");
    }
    else
    {
        printf("Enter element: ");
        int n;
        scanf("%d",&n);
        if(rear==-1 && front==-1)
        {
            rear=0;
            front=0;
        }
        else
        {
            rear=(rear+1)%max;
        }
        cq[rear]=n;
    }
}

void deleteed()
{
    if(rear==-1 &&front==-1)
    {
        printf("Empty Queue");
    }
    else
    {
        if(front==rear)
        {
            rear=-1;
            front=-1;
        }
        else
            printf("delete number is : %d",cq[front++]);
    }
}

void display()
{
    if(front==-1)
    {
        printf("Empty Queue\n");
    }
    else
    {

        for(int i=front;i!=rear+1;i=(i+1)%max)
        {
            printf("%d \n",cq[i]);
        }
    }
}

void main()
{
    int x=0;
    do
    {
        printf("----circular---Queue----\n");
        printf(" 1 for insert \n 2 for delete \n 3 for display \n 4 for exit\n Enter your choice:");
        scanf("%d",&x);
        switch(x)
        {
            case 1: insert();break;
            case 2: deleteed();break;
            case 3: display();break;
        }
    }while(x!=4);
}
