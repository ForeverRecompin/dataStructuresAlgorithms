#include <stdio.h>
#include <stdlib.h> 
#define MAX 20
struct stack
{
	char a[MAX];
	int top;
}*s;

void push( struct stack*s,char d )
{
	  
    if(s->top==MAX-1)
    {
    	printf("Stack is full.\n");
    }
    else
    {
    	s->top++;
    	s->a[s->top]=d;
    }
}

int pop(struct stack*s)
{
	int y;
	if(s->top==-1)
	{
		printf("Stack is empty.\n");
	} 
	else
	{
		y=s->a[s->top];
		s->top--;
	}
	
	return y;
}

int main(void)
{
	int i,n,temp;
	s=(struct stack*)malloc(sizeof(struct stack));
	s->top=-1;
	
	printf("Enter the number for which we're simulating factorial using recursion in a stack: ");
	scanf(" %d",&n);
	
	for(i=n;i>=1;i=i-1)
	{
		push(s,i);
	}
	
	while(s->top>0)
	{
		temp=pop(s);
		push(s,temp*pop(s));
	}

	printf("The factorial of %d is %d.\n",n,pop(s));
	return 0;
}
