// Inclusions
#include <stdio.h>
#include <stdlib.h>

// Structure Define
struct node
{
	int data;
	struct node* link;
};

struct node* top;
struct node* root;

// Function Prototype
void Push(int element);
void Pop();
void Traverse();
int Peek();
int Length();

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
		printf("5.Length\n");
		printf("6.exit\n");

		scanf("%d",&ch);
	
		switch(ch)
		{
			case 1: printf("Enter element to insert: \n");
			scanf("%d",&element);
			Push(element);
			break;

			case 2: Pop();
			break;

			case 3: Traverse();
			break;

			case 4: if(Peek()=='e')
					{
						printf("Stack is empty");
					}
					else
					{
						printf("Last element of stack is %d: \n",Peek());
					}
			
			break;

			case 5: printf("Length of list is: %d\n",Length());
			break;

			case 6: exit(0);
			break;

			default: printf("Invalid #input\n");
			break;
		}
	}
}

void Push(int element)
{
	struct node* temp;

	temp = (struct node* )malloc(sizeof(struct node));

	temp->data = element;
	temp->link = NULL;

	if(top==NULL)
	{
		root = temp;
		top = temp;
	}
	else
	{
		top->link = temp;
		top = top->link;
	}
}

void Pop()
{
	// defining temporary variable p
	struct node* p=root;
	struct node* temp = top;

	if(top==NULL)
	{
		printf("Stack is Empty\n");
		
	}
	else
	{
		if(root->link==NULL)
		{
			root = NULL;
			top = NULL;
		}
		else
		{
			while(p->link!=top) //because last element is top and we want last-1 address, so when p->link is equal to address of top then we willl terminate the loop
			{
				p = p->link;
			}
			p->link = NULL;
			top = p;
			free(temp);
		}
	}
}

void Traverse()
{
	struct node* temp;

	if(root==NULL)
	{
		printf("Stack is Empty\n");
	}
	else
	{
		printf("\nElements Of Stacks are:\n");
		temp = root;
		while(temp!=NULL)
		{
			printf("%d\n",temp->data);
			temp=temp->link;
		}
	}
}


int Peek()
{
	if(top==NULL)
	{
		return 'e';
	}
	else
	{
		return top->data;
	}
}

int Length()
{
	int count = 0;
	struct node* temp;
	if(root==NULL)
	{
		return count;
	}
	else
	{
		temp=root;
		while(temp!=NULL)
		{
			count++;
			temp= temp->link;
		}
		return count;
	}
}