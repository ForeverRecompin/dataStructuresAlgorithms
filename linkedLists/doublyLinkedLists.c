#include <stdio.h>
#include <stdlib.h>

void insertBeginning(int dataIn);void insertMiddle(int dataIn,int positionIn);void insertEnd(int dataIn);
void deleteBeginning();void deleteMiddle(int positionOut);void deleteEnd();
void displayDLL();

struct dLL
{
	int data;
	struct dLL *next;
	struct dLL *previous;
}*head,*p,*q;

int main(void)
{
	int choice,menu,dataIn,positionIn,dataOut,positionOut;char subMenu;
	
	do
	{
	printf("MENU\nPress 1 to insert,\nPress 2 to delete and\nPress 3 to display elements in the DLL.\n");
	scanf(" %d",&menu);
	if(menu==1)
	{
		printf("Insertion is being performed.Where do you want it to be done? Press a to insert at the beginning,b to insert in the middle at a suitable position and c to insert in the end of the DLL.\n");
		scanf(" %c",&subMenu);
		if(subMenu=='a')
		{
			printf("You've chosen insertion at the beginning.Provide the data to be inserted.\n");
			scanf(" %d",&dataIn);
			insertBeginning(dataIn);
		}
		else if(subMenu=='b')
		{
			printf("You've chosen insertion in the middle.Provide the data to be inserted and it's position.Positions start from 0.\n");
			scanf(" %d",&dataIn);
			printf("Enter position.\n");
			scanf(" %d",&positionIn);
			insertMiddle(dataIn,positionIn);
		}
		else if(subMenu=='c')
		{
			printf("You've chosen insertion at the end.Provide the data to be inserted.\n");
			scanf(" %d",&dataIn);
			insertEnd(dataIn);
		}
	}
	else if(menu==2)
	{
		printf("Deletion is being performed.Where do you want it to be done?Press a to delete at the beginning,b to delete in the middle at a suitable position and c to delete in the end of the DLL.\n");
		scanf(" %c",&subMenu);
		if(subMenu=='a')
		{
			printf("You've chosen deletion at the beginning.\n");
			deleteBeginning();
		}
		else if(subMenu=='b')
		{
			printf("You've chosen deletion in the middle.Provide the position starting from 0.\n");
			printf("Enter position.\n");
			scanf(" %d",&positionOut);
			deleteMiddle(positionOut);
		}
		else if(subMenu=='c')
		{
			printf("You've chosen deletion at the end.\n");
			deleteEnd();
		}
	}
	else if(menu==3)
	{
		printf("You've chosen to view the elements in the DLL.\n");
		displayDLL();
	}
	else
	{
		printf("Invalid option provided.\n");
	}
	printf("Press 1 to continue,0 to exit.");
	scanf(" %d",&choice);
	}while(choice!=0);

	return 0;
}

void insertBeginning(int dataIn)
{
	p=(struct dLL*)malloc(sizeof(struct dLL));
	p->data=dataIn;
	if(head==NULL)
	{
	p->next=NULL;p->previous=NULL;
	head=p;q=p;
	}
	else
	{
	p->next=head;
	head->previous=p;
	head=p;
	head->previous=NULL;
	}

	printf("Insertion Successful.\n");
}

void insertMiddle(int dataIn,int positionIn)
{
	
	int positionCount=0; struct dLL *temp;
	p=(struct dLL*)malloc(sizeof(struct dLL));
	p->data=dataIn;
	
	temp=head;
	while(positionCount!=positionIn)
	{
		temp=temp->next;
		positionCount++;
	}
	p->previous=temp->previous;
	p->previous->next=p;
	p->next=temp;
	temp->previous=p;
	
	printf("Insertion Successful.\n");
}

void insertEnd(int dataIn)
{
	struct dLL *temp;
	p=(struct dLL*)malloc(sizeof(struct dLL));
	p->data=dataIn;
	
	temp=head;
	while(temp->next!=NULL)
	{
		temp=temp->next;
	}
	p->next=NULL;
	temp->next=p;
	p->previous=temp;
	
	printf("Insertion Successful.\n");
}

void deleteBeginning()
{
	struct dLL *temp;
	temp=head;
	head=head->next;
	head->previous=NULL;
	free(temp);
	printf("Deletion Successful.\n");
}

void deleteMiddle(int positionOut)
{
	int positionCount=0;struct dLL *temp;
	temp=head;
	while(positionCount!=positionOut)
	{
		temp=temp->next;
		positionCount++;
	}
	
	temp->previous->next=temp->next;
	temp->next->previous=temp->previous;
	free(temp);
	
	printf("Deletion Successful.\n");
}

void deleteEnd()
{
	struct dLL *temp;
	temp=head;
	while(temp->next!=NULL)
	{
	temp=temp->next;
	}
	temp->previous->next=NULL;
	free(temp);
	printf("Deletion Successful.\n");
}

void displayDLL()
{
	struct dLL *temp;
	temp=head;
	printf("\t");
	while(temp!=NULL)
	{
		printf("%d ",temp->data);
		temp=temp->next;
	}
	printf(" .\n");
}





























