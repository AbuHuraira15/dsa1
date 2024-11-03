#include<stdio.h>
#include<stdlib.h>
struct node {
int data;
struct node *add;
};

struct node *temp=NULL,*head=NULL,*corunt=NULL;

struct node *firstInsertmethod(struct node *arr)
{
    temp=(struct node *)malloc(sizeof(struct node));
    int x;
    scanf("%d",&x);
    temp->data=x;
    temp->add=arr;
    return temp;
};

struct node *createLinkedList(struct node *Linked)
{
    temp=(struct node *)malloc(sizeof(struct node));
    int x;
    printf("Enter element :");
    scanf("%d",&x);
    temp->data=x;
    temp->add=NULL;
    if(Linked==NULL)
    {
        Linked=temp;
        corunt=temp;
    }
    else
    {
        corunt->add=temp;
        corunt=corunt->add;
    }
    return Linked;

};
void displayList(struct node * arr)
{
    while(arr!=NULL)
    {
        printf("%d \n",arr->data);
        arr=arr->add;
    }
}

void InsertLast(struct node  *last)
{
    struct node *head=last;
    int count=0;
    while(head!=NULL)
    {
        count++;
        head=head->add;
    }
    head=last;
    printf("You have to insert 2nd position to %d position \n",count);
    int p=0;
    struct node *lasthead;
    scanf("%d",&p);
    if((p>1)&&(count>=p))
    {
        for(int i=1;i<p;i++)
        {
            lasthead=head;
            head=head->add;
        }
        struct node *newhead=(struct  node *)malloc(sizeof(struct node));
        scanf("%d",&p);
        newhead->data=p;
        newhead->add=head;
        lasthead->add=newhead;
    }
    else
    {
        printf("Invalid input !!!\n try again");
    }
}

struct node *firstPositionDelete(struct node *arr)
{
    arr=arr->add;
    return arr;
}

void deleteLastposition(struct node *last)

{
    struct node *temp=last;
    while(temp!=NULL)
    {
        temp=last;
        last=last->add;
        if(last->add==NULL)
        {
            temp->add=NULL;
            break;
        }
    }
};


void deleteMidposition(struct node *arr)
{
    struct node *head=arr;
    int count=0;
    while(head!=NULL)
    {
        count++;
        head=head->add;
    }
    int x;
    printf("Enter delete position :");
    scanf("%d",&x);
    if((count >x) &&(x>1))
    {
        for(int i=1;i<x;i++)
        {
            if(i==x-1)
            {
                struct node *st=arr;
                arr=arr->add;
                struct node *end=arr->add;
                st->add=end;
            }
            else
            {
                arr=arr->add;
            }
        }
    }
    else
    {
        printf("Invalid input from user \n");
    }
}



int main()
{
    struct node *start=NULL;
    int x=0;
    while(x!=-1)
    {
        printf("1 for First insert\n 2 for create Linked List\n 3 for display\n ");
        printf("4 for insert mid position \n 5 for delete first position \n 6 for delete last position \n 7 for delete mid position \n -1 for exit \n enter your choice :");

        scanf("%d",&x);
        switch(x)
        {
            case 1:start= firstInsertmethod(start); break;
            case 2: start=createLinkedList(start);break;
            case 3: displayList(start); break;
            case 4: InsertLast(start);break;
            case 5: start=firstPositionDelete(start);break;
            case 6: deleteLastposition(start);break;
            case 7:deleteMidposition(start);break;
        }
    }
}

