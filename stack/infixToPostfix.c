#define MAXSIZE 10
#include <stdio.h>
#include <stdlib.h>
char key;char c;
struct stack
{	
	int top;
	char a[MAXSIZE]; 
}*s;

void push(struct stack *s,char key);
int pop(struct stack *s);
void inpost(char a[]);
int preced(char q);

void main()
{ 
	int i,m,choice;char a[10];
    s=(struct stack*)malloc(sizeof(struct stack));
    s->top=-1;
 
 	do{
 	printf("Enter the infix expression, to be converted to postfix:\n");
    scanf(" %s",&a);
    printf("\nThe postfix expression is: ");
    inpost(a);
    printf(".\n");
    printf("Press 1 to continue,0 to exit.\n");
    scanf(" %d",&choice);
 	}while(choice!=0);
}
void push(struct stack *s,char key)
{
	if(s->top==MAXSIZE-1)
    printf("Stack is full!\n");
    else
    { 
    	s->top++;
   		s->a[s->top]=key;
   	}
   
}
 
int pop(struct stack *s)
{ 
	if(s->top==-1)
    {
    	printf("Stack is empty!\n");
   	}
    else
    { 
        key=s->a[s->top];
   	    s->top--;
    } 
    return(key);
}

int preced(char q)
{ 
	int x;
	if(q=='*' || q=='/')
    x=5;
      
    if(q=='+' || q=='-')
    x=3;
    
    return x;
}  
  
void inpost(char a[])
{  
	int i=0;
    char q;
    while(a[i]!='\0')
	{
		if(a[i]>=97&&a[i]<=122)
        	printf("%c",a[i]);
       	else if(s->top==-1)
        	push(s,a[i]);
  
      	else if(preced(a[i])<=preced(s->a[s->top]))
       	{
        	while(preced(s->a[s->top])>preced(a[i]))
        	{
            	c= pop(s);
           		printf("%c",c);
          	}
        	push(s,a[i]);      
       	}
       	
       	else if(a[i]=='(')
       	{
       		push(s,a[i]);
       	}
       	else if(a[i]==')')
       	{
       		while(s->a[s->top]!='('&&s->top!=-1)
       		{
       			c=pop(s);
       			printf("%c",c);
       		}
       		if(s->a[s->top]=='(')
       			pop(s);
       	}
        else
        push(s,a[i]);
        i++;
	} 
    while(s->top!=-1)
    {
    	c=pop(s);
		printf("%c",c);
	}    
     
}  
