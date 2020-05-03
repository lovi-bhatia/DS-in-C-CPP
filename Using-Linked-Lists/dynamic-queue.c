// Inclusions
#include <stdio.h>
#include <stdlib.h>

// Properties Of Dynamic Queue
// 1. It will never get full
// 2. No need of circular queue

// structure Define
struct node
{
	int data;
	struct node* link;
};

struct node* front=NULL;
struct node* rear=NULL;
// initially Global variable gets value NULL

// Function Prototype
void Insert();
void Delete();
void Peek();
void Display();
int Length();

void main()
{

	int ch;

	while(1)
	{
		printf("1.Insert\n");
		printf("2.Delete\n");
		printf("3.Display\n");
		printf("4.peek\n");
		printf("5.Length\n");
		printf("6.exit\n");
		scanf("%d",&ch);

		switch(ch)
		{
			case 1: Insert();
			break;

			case 2: Delete();
			break;

			case 3: Display();
			break;

			case 4: Peek();
			break;

			case 5: printf("Length of list is %d: \n",Length());
			break;

			case 6: exit(0);
			break;

			default: printf("Invalid Choice\n");
			break;
		}
	}
}


// Insert Function
void Insert()
{
	struct node* temp;
	temp = (struct node*)malloc(sizeof(struct node));

	printf("Enter the element to be added in the list: ");
	scanf("%d",&temp->data);
	temp->link = NULL;

	if(rear==NULL)
	{
		front = temp;
		rear = temp;
	}
	else
	{
		rear->link = temp;
		rear = rear->link;
	}
}

// Delete Function
void Delete()
{
	if(front==NULL)
		printf("Queue Is Empty");

	else
	{
		
		struct node* temp;
		temp=front;
		front = front->link;
		free(temp);
	}
}

// Display Function
void Display()
{
	struct node* temp = front;

	if(rear==NULL)
		printf("Queue Is Empty");
		
	else
	{
		while(temp!=NULL)
		{
			printf("%d\n",temp->data);
			temp=temp->link;
			printf("Elements OF Queue are:\n");
		}
	}
}

// Peek Function
void Peek()
{
	if(rear==NULL)
	{
		printf("Queue Is Empty");
	}
	else
	{
		printf("Last element of Queue is: %d\n",rear->data);
	}
}

// Length Function
int Length()
{
	struct node* temp;
	int count = 0;
	if(rear==NULL)
	{
		printf("Queue Is Empty");
		return 0;
	}
	else
	{
		temp = front;
		while(temp!=NULL)
		{
			count++;
			temp=temp->link;
		}
		return count;
	}	
}