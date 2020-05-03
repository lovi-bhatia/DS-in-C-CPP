// Stack Implementation Like Queue i.e. pseudo-Stack working on concept of FIFO
/*
Queue works on FIFO concept
Stacks works on lIFO concept

Queue 1 2 3 4 5 6
Delete() = 1

Stacks 1 2 3 4 5 6
Pop()= 6

To make stacks works like Queue we will require 2 stacks, Stack 1 and Stack 2
all elements are poped from stack 1 and pushed in stack 2 and then last element is poped and again elemnts are pushed back in stack 2

*/

// Inclusions
#include <stdio.h>
#include <stdlib.h>

// Defines
# define SIZE 5

// Function Prototype
int isEmpty();  //Function for checking if stack is empty or not
int isFull();   //Function for checking if stack is full or not
void Push();    //Function for adding element in stack
void Delete();  //Function for deleting element
void Traverse();    //Function for Displaying elements

// initialization related to stack 1
int Stack1[SIZE];
int top1 =-1;

// initialization related to stack 2
int Stack2[SIZE];
int top2 = -1;

void main()
{
    int ch; // ch is varoiable and short for choice
    
    while(1)
    {
        printf("1.Push\n");
        printf("2.Delete\n");
        printf("3.Traverse\n");
        printf("4.exit\n");

        printf("Enter the choice::::\t");
        scanf("%d",&ch);


        switch (ch)
        {
        case 1: Push();
            break;
        case 2: Delete();
            break;
        case 3: Traverse();
            break;
        case 4: exit(0); 
            break;
        default:
            printf("invalid INput\n\n");
            break;
        }
    }
}

int isEmpty()
{
    if(top1==-1)
    return 1;
    else
    return 0;
}

int isFull()
{
    if(top1==SIZE-1)
    return 1;
    else
    return 0 ;
}

void Push()
{
    int element;
    if(isFull())
        printf("Stack is Full");
        
    else
    {
        printf("Enter The element");
        scanf("%d",&element);
        top1++;
        Stack1[top1] = element;
    }
    
}

void Delete()
{
    int i; //iterator
    if(isEmpty())
        printf("Stack is empty, Add few elements then try.");

    else
    {
        // loop for inserting elemnt of stack1 in stack2
        for(i=top1;i>=0;i--)
        {
            top2++;
            Stack2[top2] = Stack1[i];
        }
        // Making Stack 1 Empty
        top1 = -1;
        printf("Deleted element is %d\n",Stack2[top2]);
        // Deleting First Element of stack 1 and Last Element of Stack 2 
        top2--;

        //Loop for inserting elements of stack 2 in stack 1 back;
        for(i=top2;i>=0;i--)
        {
            top1++;
            Stack1[top1] = Stack2[i];
        }
        top2 = -1; //making stack 2 empty again
    
    }
    
}


void Traverse()
{
    int i; //iterator
    if(isEmpty())
    {
        printf("Stack is Empty\n");
    }
    else
        {
            for (i=top1;i>=0;i--)
            {
                printf("%d\n",Stack1[i]);
            }
        }
}