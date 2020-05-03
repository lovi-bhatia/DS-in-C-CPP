// Inclusions
#include <stdio.h>
#include <stdlib.h>

// Structure Define
struct node
{
	int data;
	struct node* link;
};

struct node* root = NULL;

// All global variables are defined default value i.e. NULL

// Function Prototypes
void Append();
void AddatBegin();
void AddatAfter();
int Length();
void Dispaly();
void Delete();

void main()
{
	int ch; //choice
	while(1)
	{
		printf("Single Linked list operations\n");
		printf("1.Append\n");
		printf("2.AddatBegin\n");
		printf("3.AddatAfter\n");
		printf("4.Length of list\n");
		printf("5.Dispaly\n");
		printf("6.Delete a node\n");
		printf("7.Quit\n");
		printf("Enter Your choice:	");
		scanf("%d",&ch);

		switch(ch)
		{
			case 1: Append();
			break;

			case 2: AddatBegin();
			break;

			case 3: AddatAfter();
			break;

			case 4: printf("Length Of list is: %d\n",Length()); 
			break;

			case 5: Dispaly();
			break;

			case 6: Delete();
			break;

			case 7: exit(0);
			break;

			default: printf("Invalid choice\n");
		}
	}
	
}

// Append Function
void Append()
{
	// local temporary variable
	struct node* temp;
	temp = (struct node*)malloc(sizeof(struct node));

	// read information
	printf("Enter Node Data:	");
	scanf("%d",&temp->data);
	temp->link = NULL;

	// checking if root = Null i.e. list is empty
	if(root == NULL)
	{
		root = temp;
	}
	else
	{
		// another temporary value
		struct node* p;
		p = root;
		while(p->link!=NULL)
		{
			p = p->link;
		}

		p->link = temp;
	}
}


// Add At Begin Function
void AddatBegin()
{
	struct node* temp;
	temp = (struct node*)malloc(sizeof(struct node));

	// reading information to be added
	printf("Enter the data:	");
	scanf("%d",&temp->data);
	temp->link = NULL;

	if(root == NULL)
	{
		root = temp;
	}
	else
	{
		temp->link = root;
		root = temp; 
	}
}

// Add At After Function
void AddatAfter()
{
	struct node* temp;
	// initially p = root
	struct node* p = root;
	struct node* q;
	temp = (struct node*)malloc(sizeof(struct node));

	int i = 1;

	// read the location
	int location;
	printf("Enter the location where new data should be added:	");
	scanf("%d",&location);

	// reading information to be added
	printf("Enter the data:	");
	scanf("%d",&temp->data);
	// temp->link = NULL;

	if(location>Length())
	{
		printf("Invalid location\n");
		printf("Current list have %d Elements\n",Length());
	}
	else
	{
		while(i<location)
		{
			i++;
			p = p->link;
		}
		temp->link = p->link;
		p->link = temp;
	}
	
}

// Length Function
int Length()
{
	int count = 0;
	// temp variable p for loop
	struct node* temp = root;

	while(temp!=NULL)
	{
		count++;
		temp = temp->link;
	}
	return count;
}

// Displaying Elements
void Dispaly()
{
	struct node* p = root;
	printf("Elements in linked lists are:\n");
	if(p == NULL)
	{
		printf("There are no Elements to Dispaly\n");
	}
	else
	{
		while(p!=NULL)
		{
			printf("%d\n",p->data);
			p = p->link;
		}
	}
}

void Delete()
{
	struct node* temp;
	struct node* p;	
	struct node* q;
	// p->q->temp
	int location;

	if(Length()==0)
	{
		printf("List is empty\n");
	}
	else
	{
		printf("Enter the location of Element to be deleted:");
		scanf("%d",&location);
		
		if(location>Length())
		{
			printf("Invalid Input\n");
		}
		else if(location==1)
		{
			temp = root;
			root = temp->link;
			temp->link = NULL;
			free(temp);
		}
		else
		{
			// we will acces location-1 because address of location is in location-1, we will change it to location+1
			p = root;
			
			int i = 1;

			while(i<location-1)
			{
				i++;
				p = p->link;
			}
			q = p->link;
			p->link = q->link;
			q->link = NULL;
			free(q);
		}
	}
}