#include <stdio.h>
#define max 6

void insert(int x); int delete(); 
int isFull(); int isEmpty(); 

int front,rear,a[6];

int main(void)
{
    int choice,y,x,n,i=0;a[6];    
    front=-1,rear=-1;

    do
    {
    
    printf("\tMENU\t\nPress 1 for inserting an element,\nPress 2 for deleting an element,\nPress 3 for checking if the queue is full,\nPress 4 for checking if the queue is empty,\nPress 5 to view the queue.\n");
    scanf(" %d",&choice);
    
    switch(choice)
    {
        case 1:
        printf("Insert the element:\n");
        scanf(" %d",&x);
        insert(x);
        break;
    
        case 2:
        printf("Deleting an element.\n");
        y=delete(x);
        printf("Element deleted: %d",y);
        break;
        
        case 3:
        printf("Checking if the queue is full.\n");
        y=isFull();
        printf("1 is True,0 is false: %d",y);
        break;
        
        case 4:
        printf("Checking if the queue is empty.\n");
        y=isEmpty(); 
        printf("1 is True,0 is false: %d\n",y);
        break;
        
        case 5:
        y=isEmpty(); 
        if(y==0)
        {
        for(i=front;i<=rear;i++)
        {
            printf("%d  ",a[i]);
        }
        printf("\n");
        }
        else
        {
        printf("Empty queue,Oops!\n");
        }
        break;
        
        default: printf("Invalid input.\n");
        break;
    
    }
    printf("Press 1 to continue,0 to exit.\n");
    scanf(" %d",&n);
    }while(n==1);
    
    return 0;
}

void insert(int x)
{
    int i,n;
    
    if(isEmpty())
    {
        front=0;rear=0;
        a[rear]=x;
       
    }
    
    else if(!isFull())
    {
        rear=rear+1;
        a[rear]=x;
    }
}

int delete()
{
    int x;
    x=a[front];
    front=front + 1;
    return x;
}


int isFull()
{
    if(rear==(max-1))
    {
        return 1; //true
    }
    else
    {
        return 0; //false
    }

}

int isEmpty()
{
    if((rear == -1 && front == -1) || (rear == max && front == max) )
    {
        return 1; //true
    }
    else
    {
        return 0; //false
    }

}














