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

int main()
{
    struct node *start=NULL;
    int x=0;
    while(x!=5)
    {
        printf("1 for First insert\n 2 for create Linked List\n 3 for display\n ");
        scanf("%d",&x);
        switch(x)
        {
            case 1:start= firstInsertmethod(start); break;
            case 2: start=createLinkedList(start);break;
            case 3: displayList(start); break;
        }
    }
}
