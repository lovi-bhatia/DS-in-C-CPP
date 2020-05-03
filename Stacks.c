/*
Stacks Work On Concept of LIFO(Last In First Out)
Initial Position of Top will be -1 (when stack is Empty), because Indexing of array starts from 0 

	|	4	|	<-Top
	---------
	|	3	|
	--------
	|	2	|
	---------
	|	1	|

	Last Element added is 4	any other element will be added after 4 and top will be shifted to new Element position
	Deletion Will take place at Top Position Top--, Top will be reduced by 1 and when new element will be added it will replace 4

*/
// Inclusions
#include <stdio.h>
#include <stdlib.h>

// Define
#define CAPACITY 5

// Initialization
int stack[CAPACITY];
int top = -1;

// Function Prototypes
int isEmpty();
int isFull();
void push(int );
int pop();
int peek();
void traverse();

void main()
{
	int ch;
	int element;
		
	while(1)
	{
		printf("1.Push\n");
		printf("2.pop\n");
		printf("3.traverse\n");
		printf("4.peek\n");
		printf("5.exit\n");
		scanf("%d",&ch);
	
		switch(ch)
		{
			case 1: printf("Enter element to insert: \n");
			scanf("%d",&element);
			push(element);
			break;

			case 2: printf("stack filled upto %dth position \n",pop()+1);
			break;

			case 3: traverse();
			break;

			case 4: printf("top element of stack is %d \n",peek());
			break;

			case 5: exit(0);
			break;

			default: printf("Invalid #input\n");
		}
	}
}

// isFull function
int isFull()
{
	if(top==CAPACITY-1)
	{
		return 1;
		// True stack is full
	}
	else
	{
		return 0;
	}
}

// isEmpty Function
int isEmpty()
{
	if(top==-1)
	{
		return 1;
		// true stack is empty
	}
	else
	{
		return 0;
	}
}

// push/insertion function
void push(int element)
{
	if(isFull())
	{
		printf("Stack is full\n");
	}
	else
	{
		top++;
		stack[top] = element;
		printf("element %d is pushed/inserted.\n",element);
	}
}

// pop Function
int pop()
{
	if(isEmpty())
	{
		printf("Stack is empty\n");
	}
	else
	{
		int element = stack[top];
		top--;
		return top;
	}
}

// peek Function
int peek()
{
	if(isEmpty())
	{
		printf("Stack is empty\n");
	}
	else
	{
		return stack[top];
	}	
}

// traverse Function
void traverse()
{
	if(isEmpty())
	{
		printf("Stack is empty\n");
	}
	else
	{
		for(int i=top;i>=0;i--)
		{
			printf("%d\n",stack[i]);
		}
	}
}