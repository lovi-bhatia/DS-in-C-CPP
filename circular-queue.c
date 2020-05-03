/*
In Queue Element is added from behind and deleted From Front

	----------------------------------------------------
	    0<-Deletion<- | 1 | 2 | 3 | 4 | <-Insertion<-5
	----------------------------------------------------

*/

// Inclusions
#include <stdio.h>
#include <stdlib.h>

// Defines
#define CAPACITY 10

// Making array for Queue
int Queue[CAPACITY];
int front = -1;
int rear = -1;
// front and rear are -1 because indexing begins from 0 
int count = 0;

// Function Prototypes
void Insert();
void Delete();
void Display();
int isEmpty();
int isFUll();
void peek();

void main()
{
	int ch;

	while(1)
	{
		printf("1.Insert\n");
		printf("2.Delete\n");
		printf("3.Display\n");
		printf("4.peek\n");
		printf("5.exit\n");
		scanf("%d",&ch);

		switch(ch)
		{
			case 1: Insert();
			break;

			case 2: Delete();
			break;

			case 3: Display();
			break;

			case 4: peek();
			break;

			case 5: exit(0);
			break;

			default: printf("Invalid Choice\n");
		}
	}
}

int isEmpty()
{
	if(front==-1 && rear == -1)
		return 1;
	else
		return 0;
	
}

int isFUll()
{
	if((front==rear+1)||(front==0 && rear==CAPACITY-1))
		return 1;
	else
		return 0;

}

void Insert()
{
	int item;

	if(isFUll())
		printf("Queue is is FUll\n");
	else
	{	
		printf("Enter the item\n");
		scanf("%d",&item);

		 if(front==-1 && rear ==-1)
		 	front = rear = 0;

		 else if(rear == CAPACITY-1)
		 	rear=0;
		 	
		 else
		 	rear++;

		 Queue[rear] = item;
		 count++;
	}
}

void Delete()
{
	if(isEmpty())
		printf("Queue is Empty\n");

	else if(front==rear)
	{
		front = -1;
		rear = -1;
	}

	else if(front==CAPACITY-1)
		front = 0;

	else
		front++;

}

void Display()
{
	int i;
	
	printf("\n\n\n");
	if(isEmpty())
		printf("Queue Is Empty\n");

	else
	{
		for(i=front;i!=rear;i=(i+1)%CAPACITY)	//Commonsense
		{
			printf("%d\n",Queue[i]);
		}
		printf("%d\n",Queue[i]); //because we need to print rear also
	}
}

void peek()
{
	if(isEmpty())
		printf("Queue is Empty\n");
		
	else
		printf("%d\n",Queue[rear]);
}
