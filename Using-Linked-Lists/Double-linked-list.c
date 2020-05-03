// Double Linked List Contains 3 things:
// 										1.Data
// 										2.Link to Right Node
// 										3.Link to Left Node
#include <stdio.h>
#include <stdlib.h>

struct node
{
	int data;
	struct node* left;
	struct node* right;
};

struct node* root;


// Function Prototypes
void Append();
void AddatBegin();
void AddatAfter();
int Length();
void Dispaly();
void Delete();
void Pop();
struct node* Create();

int main()
{
	int ch; //choice
	while(1)
	{
		printf("Double Linked list operations\n");
		printf("1.Append\n");
		printf("2.Add at Begin\n");
		printf("3.Add at After\n");
		printf("4.Length of list\n");
		printf("5.Display\n");
		printf("6.Delete a node\n");
		printf("7.Pop a node\n");
		printf("8.Quit\n");
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

			case 7: Pop();
			break;

			case 8: exit(0);
			break;

			default: printf("Invalid choice\n");
		}
	}

}

// Create Function to Create Node
// return type will be struct node with pointer (because Create()Function is returning address of temp ) //statememt is in doubt, if you know correct then inform me
struct node* Create()
{
	struct node* temp;
	temp = (struct node*)malloc(sizeof(struct node));
	printf("Enter data of node:\n");
	scanf("%d",&temp->data);
	temp->right = NULL;
	temp->left = NULL;

	return temp;
}

// @Append Function new node will be last node
void Append()
{
	struct node* temp;

	temp = Create();

	if(root == NULL)
	{
		root = temp;
	}
	else
	{
		struct node* p=root;
		while(p->right!=NULL)
		{
			p = p->right;
		}
		p->right = temp;
		temp->left = p;
	}
}

// @Add At Begin new node will point to first node(root is also pointing to first node) and then root will point to new node
void AddatBegin()
{
	struct node* temp;
	temp = Create();

	if(root == NULL)
	{
		root = temp;
	}
	else
	{
		root->left = temp;
		temp->right = root;
		root = temp;
	}
}

// Added after a particular location
void AddatAfter()
{
	int location;
	int i=0;
	struct node* temp;
	struct node* p=root;

	printf("Enter the location\n");
	scanf("%d",&location);

	if(location>Length())
	{
		printf("Invalid Input\n");
		printf("Length of list is %d\n\n",Length());
	}
	else
	{
		
		temp = Create();

		while(i<location-1)
		{
			p = p->right;
		}
		temp->right = p->right;
		temp->left = p;
		p->right = temp;
	}
}

int Length()
{
	struct node* temp = root;
	int count;

	if(root == NULL)
	{
		return count;
	}
	else
	{
		while(temp!=NULL)
		{
			count++;
			temp= temp->right;
		}
		return count;
	}
}


void Dispaly()
{
	struct node* temp=root;
	int i=1;

	if(root == NULL)
	{
		printf("list is empty\n");
	}
	else
	{
		while(temp!=NULL)
		{
			printf("%d. %d\n",i,temp->data);
			i++;
			temp = temp->right;
		}
	}
}

// Last Element will be deleted
void Pop()
{
	struct node* temp;
	struct node* p;

	if(root==NULL)
	{
		printf("List is empty\n");
	}
	else
	{
		while(p->right->right!=NULL)
		{
			p=p->right;
		}
		temp = p;
		p=p->right;

		temp->right = NULL;
		p->left = NULL; //p->right is already null

		free(p);
	}
}

// Element from particular location will be deleted
void Delete()
{
	struct node* temp;
	struct node* p; //will point to q
	struct node* q; //will point to temp
	// p->q->temp
	// q will be deleted
	int location;

	printf("Enter the location to be deleted: \n");
	scanf("%d",location);

	if(location>Length()||location<=0)
	{
		printf("Invalid Input\n");
	}
	else if(location==1)
	{
		temp = root;
		root = root->right;
		root->left = NULL; //because we want root->right to remain connected
		temp->right = NULL; //because temp->left is alredy null
		free(temp);
	}
	else
	{
		p = root;

		int i;
		while(i<location-1)
		{
			i++;
			p = p->right;
		}
		q = p->right;
		temp = q->right;

		p->right = q->right;
		temp->left = p;
		q->right = NULL;
		q->left = NULL;
		free(q);
	}
}
