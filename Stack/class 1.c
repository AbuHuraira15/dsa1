#include<Stdio.h>
#include<conio.h>
#define Max 10
int Stack[Max],top=-1;


void pop()
{
    if(top==-1)
    {
        printf("Empty Stack");
    }
    else
    {
        int n=Stack[top];
        top--;
        printf("Deleted number is: %d\n",n);
    }

}

void push()
{
    if(top==Max-1)
    {
        printf("Store full");
    }
    else
    {
        printf("\nEnter number:");
        scanf("%d",&Stack[++top]);
    }
}

void display()
{
    if(top==-1)
    {
        printf("Stack is empty");
    }
    else
    {
        for(int i=top; i>=0; i--)
        {
            printf("%d \n",Stack[i]);
        }
    }
}

int main()
{
    int x=1;
    while(x!=0)
    {
        printf("-----Stack------");
        printf("\n 1 for pop\n 2 for push \n 3 for display\n 4 Exit \n Enter your choice :");
        scanf("%d",&x);

        switch(x)
        {
        case 1:
            pop();
            break;
        case 2:
            push();
            break;
        case 3:
            display();
            break;
        }
    }

}
