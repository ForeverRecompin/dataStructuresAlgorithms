#include <stdio.h>
#include <stdlib.h>
#define MAX 20

struct queue
{
	int a[MAX],front,rear;
}*q;

void frontEnqueue(struct queue *,int dataIn);
int frontDequeue(struct queue *);
void rearEnqueue(struct queue *,int dataIn);
int rearDequeue(struct queue *);

int main(void)
{
	int choice,menu,dataIn,dataOut,i;

	q=(struct queue*)malloc(sizeof(struct queue));
	q->front=-1;
	q->rear=-1;
	do
	{
		printf("\tMENU\nPress 1 to Front-Enqueue,\nPress 2 to Front-Dequeue,\nPress 3 to Rear-Enqueue,\nPress 4 to Rear-Dequeue,\nPress 5 to Display the queue.\n");
		scanf(" %d",&menu);
		switch(menu)
		{
			case 1:
				printf("Enter data: ");
				scanf(" %d",&dataIn);
				frontEnqueue(q,dataIn);
			break;
			case 2:
				dataOut=frontDequeue(q);
				printf("Element Dequeued: %d.\n",dataOut);
			break;
			case 3:
				printf("Enter data: ");
				scanf(" %d",&dataIn);
				rearEnqueue(q,dataIn);
			break;
			case 4:
				dataOut=rearDequeue(q);
				printf("Element Dequeued: %d.\n",dataOut);
			break;
			case 5:
				
				if(q->rear==0)
				{
					printf("%d ",q->a[q->rear]);
					printf("\n");
				}
				else
				{
					for (i=q->front;i<=q->rear;i=i+1)
						{
							printf("%d ",q->a[i]);
						}
				}
					printf("\n");
			break;
			default:
				printf("Bad option provided.\n");
			break;
		}
		printf("Press 1 to continue,0 to exit.\n");
		scanf(" %d",&choice);
	}while(choice!=0);


	return 0;
}

void frontEnqueue(struct queue *q,int dataIn)
{
	if(q->front==0)
	{
		printf("Queue is full.\n");
	}
	else if(q->front==-1)
	{
		q->front++;
		q->a[q->front]=dataIn;
	}
	else
	{
		q->front--;
		q->a[q->front]=dataIn;
	}
}

int frontDequeue(struct queue *q)
{
	int dataOutLocal=NULL;
	if(q->front==-1)
	{
		printf("Queue is empty.\n");
	}
	else if(q->front==q->rear)
	{
		dataOutLocal=q->a[q->front];
		q->front=-1;
		q->rear=-1;
	}
	else
	{
		dataOutLocal=q->a[q->front];
		q->front++;
	}
	return dataOutLocal;
}

void rearEnqueue(struct queue *q,int dataIn)
{
	if(q->rear==MAX-1)
	{
		printf("Queue is full.\n");
	}
	else if(q->front==-1)
	{
		q->front++;
		q->rear++;
		q->a[q->rear]=dataIn;
	}

	else
	{
		q->rear++;
		q->a[q->rear]=dataIn;
	}
}

int rearDequeue(struct queue *q)
{
	int dataOutLocal=NULL;
	if(q->rear=-1)
	{
		printf("Queue is empty.\n");
	}
	else if(q->front==q->rear)
	{
		dataOutLocal=q->a[q->rear];
		q->front=-1;
		q->rear=-1;
	}
	else
	{
		dataOutLocal=q->a[q->rear];
		q->rear--;
	}
	return dataOutLocal;
}