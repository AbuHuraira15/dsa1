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


int main()
{
    int x=0;
    struct node *start=NULL;
    while(x!=-1)
    {
        printf(" 1 for create linked list\n 2 for forward \n 3 for back ward move\n ");
        printf("4 for add in first position \n enter your choice:");
        scanf("%d",&x);
        switch(x)
        {
            case 1:start=addList(start);break;
            case 2:frontmove(start);break;
            case 3: backmove(lastposition);break;
            case 4: start=addfirst(start);break;
        }
    }
}
