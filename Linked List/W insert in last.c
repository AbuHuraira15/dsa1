#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next,*last;
};
struct node *lastposition=NULL,*carent=NULL,*temp=NULL;
struct node *addList(struct node *start)
{
    temp=(struct node *)malloc(sizeof(struct node));
    int x;
    printf("Enter element:");
    scanf("%d",&x);
    temp->data=x;
    temp->last=NULL;
    temp->next=NULL;
    if(start==NULL)
    {
        start=temp;
        carent=temp;
        lastposition=temp;
    }
    else
    {
        carent->next=temp;
        temp->last=carent;
        lastposition=temp;
        carent=carent->next;
    }
    return start;
};

void frontmove(struct node *start)
{
    while(start!=NULL)
    {
        printf("%d \n",start->data);
        start=start->next;
    }
}
void backmove(struct node *lastend)
{
    while(lastend!=NULL)
    {
        printf("%d \n",lastend->data);
        lastend=lastend->last;
    }
}

struct node *addfirst(struct node *st)
{
    printf("Enter element in first position :");
    int x;
    scanf("%d",&x);
    struct node *temp=(struct node *)malloc(sizeof(struct node));
    temp->next=st;
    st->last=temp;
    temp->data=x;
    return temp;
};

struct node *midset(struct node *st)
{
    struct node *travers=st,*first=st,*End=st;
    int count=0,x=0;
    while(travers!=NULL)
    {
        count++;
        travers=travers->next;
    }
    printf("Enter position :");
    scanf("%d",&x);
    if((x>1)&&(count>=x))
    {
        for(int i=1;i<x;i++)
        {
            if(i==(x-1))
            {
                first=End;
                End=End->next;
                int x;
                printf("Enter number:");
                scanf("%d",&x);
                temp=(struct node *)malloc(sizeof(struct node));
                temp->data=x;
                temp->last=first;
                temp->next=End;
                first->next=temp;
                End->last=temp;
                break;

            }
            else
            {
                //first=End;
                End=End->next;
            }
        }
    }
    return st;

};

struct node *deletefirst(struct node *arr)
{
    arr=arr->next;
    arr->last=NULL;
    return arr;
};

void deletemid(struct node *mid)
{
    struct node *first=mid;
    int count=0;
    while(first!=NULL)
    {
        count++;
        first=first->next;
    }
    int x=0;
    printf("Enter position:");
    scanf("%d",&x);
    if((x>1)&&(x<count))
    {
        struct node *End=mid;
        for(int i=1;i<x;i++)
        {
            if(i==x-1)
            {
               first=End;
               End=End->next;
               End=End->next;
               first->next=End;
               End->last=first;
            }
            else
            {
                End=End->next;
            }
        }
    }

}

void deletelast(struct node *arr)
{
    struct node *End=arr;
    while(arr!=NULL)
    {
        //struct node *leg=arr;
        End=arr->next;
        if(End->next==NULL)
        {
            End->next=NULL;
            lastposition=End->last;
            break;
        }
        else
        {
            arr=arr->next;
        }
    }
}


int main()
{
    int x=0;
    struct node *start=NULL;
    while(x!=-1)
    {
        printf(" 1 for create linked list\n 2 for forward \n 3 for back ward move\n ");
        printf("4 for add in first position \n 5 insert mid position\n 6 for delete first position\n ");
        printf("7 for mid delete element\n 8 for delete last\n");
        printf("enter your choice:");
        scanf("%d",&x);
        switch(x)
        {
            case 1:start=addList(start);break;
            case 2:frontmove(start);break;
            case 3: backmove(lastposition);break;
            case 4: start=addfirst(start);break;
            case 5: start=midset(start);break;
            case 6: start=deletefirst(start);break;
            case 7: deletemid(start);break;
            case 8:deletelast(start);break;
        }
    }
}

