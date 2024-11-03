#include<stdio.h>
#include<conio.h>
struct node
{
    int data;
    struct node *address;
};
struct node *head=NULL,*corunt=NULL,*temp=NULL;
struct node *Addmethod()
{
    temp=(struct node *)malloc(sizeof(struct node));
    int x;
    scanf("%d",&x);
    temp->data=x;
    temp->address=NULL;
    if(head==NULL)
    {
        head=temp;
        corunt=temp;
    }
    else
    {
        corunt->address=temp;
        corunt=corunt->address;
    }

};

void show()
{
    while(head!=NULL)
    {
        printf("%d",head->data);
        head=head->address;
    }
}

int main()
{
    int x=0;
    while(x!=-1)
    {
        scanf("%d",&x);
        switch(x)
        {
            case 1: Addmethod(); break;
            case 2: show(); break;
        }

    }
}
