/*
STACK: One-end closed data structure implemented by LIFO - Last In First Out

Basic Operations: 
	1. Reinitial stack/Create Stack
	2. Push
	3. Pop - Remove the last element
	4. Is Empty
	5. Is Full
	6. Get Top	
	7. Display

Write a menu driven program in C.
*/

#include <stdio.h>
#define max 6

void push(int x); int pop(); 
int isFull(); int isEmpty();
int getTop(); 

int top = -1, a[max];

int main(void)
{
    int choice,y,x,n,i=0;    

    do
    {
    
    printf("\tMENU\t\nPress 1 for pushing an element,\nPress 2 for popping an element,\nPress 3 for checking if the stack is full,\nPress 4 for checking if the stack is empty,\nPress 5 to 'get top' element,\nPress 6 to view the stack.\n");
    scanf(" %d",&choice);
    
    switch(choice)
    {
        case 1:
        printf("Pushing the element: \n");
        scanf(" %d",&x);
        push(x);
        break;
    
        case 2:
        printf("Popping an element.\n");
        y=pop(x);
        printf("Element popped: %d \n",y);
        break;
        
        case 3:
        printf("Checking if the stack is full.\n");
        y=isFull();
        printf("1 is True,0 is false: %d\n",y);
        break;
        
        case 4:
        printf("Checking if the stack is empty.\n");
        y=isEmpty(); 
        printf("1 is True,0 is false: %d\n",y);
        break;
        
        case 5:
        printf("'Getting' top element.\n");
        y=getTop();
        printf("The element is: %d\n",y);
        break; 
        
        case 6:
        y=isEmpty(); 
        if(y==0)
        {
        for(i=top;i>=0;i--)
        {
            printf("%d  ",a[i]);
        }
        printf("\n");
        }
        else
        {
        printf("Empty stack,Oops!\n");
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

void push(int x)
{
    int i;
    
    if(!isFull())
    {
        top=top+1;
        a[top]=x;
	}
}

int pop()
{
    int x;
    x=a[top];
    top = top-1;
    return x;
}


int isFull()
{
    if(top==(max-1))
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
    if(top==-1 )
    {
        return 1; //true
    }
    else
    {
        return 0; //false
    }
}

int getTop()
{
    if(isEmpty())
    {
    	printf("The stack is empty.Oops!\n");
    }
    
    else
    {
    	return a[top];
    }
}












