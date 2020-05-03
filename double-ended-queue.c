// Double ended Queue
// Implementing using circular array
/*

In double ended Queue we can insert as well delete from both sides
                  front               rear
----------------------------------------------------------
Insert/Delete->   | 1 | 2| 3 | 4 | 5 | 6 | <- Insert/Delete
----------------------------------------------------------

*/

// Inclusions
#include <stdio.h>
#include <stdlib.h>

// Size
#define SIZE 5

int Queue[SIZE];

//front is first element in array 
int front = -1;
// rear is last element in array
int rear = -1;

// ################################
// Function Protoypes
// ###############################

// Queue is Full or not
int isFull();
// Queue is Empty or not
int isEmpty();
//Insert from front side
void InsertAtBegin();
// Insert From rear side
void InsertAtEnd();
// Delete Front element
void DeleteFront();
// Delete rear element
void DeleteRear();
// Display from front
void TraverseFromFront();
// Dispaly from rear
void TraverseFromRear();


void main()
{
    int ch;

    while(1)
    {
        printf("1.Insert At Begin\n");
        printf("2.Insert At End\n");
        printf("3.Delete Front\n");
        printf("4.Delete Rear\n");
        printf("5.Traverse From Front\n");
        printf("6.Traverse From Rear\n");
        printf("7.Exit\n");
        scanf("%d",&ch);

        printf("\n");

        switch (ch)
        {
            case 1: InsertAtBegin();
                break;
            case 2: InsertAtEnd();
                break;
            case 3: DeleteFront();
                break;
            case 4: DeleteRear();
                break;
            case 5: TraverseFromFront();
                break;
            case 6: TraverseFromRear();
                break;
            case 7: exit(0);
                break;
            default: printf("Invalid INput\n");
                break;
        }
    }
}

int isFull()
{
    if((front==0 && rear == SIZE-1)||(front == rear+1))
        // True
        return 1;
    else
        // False
        return 0;
    
}

int isEmpty()
{
    if(front==-1 && rear==-1)
        // True
        return 1;
    else
        // False
        return 0;
}

// When We insert element from front side then front will be shifted backward
// Because Front is the element which is at first position in Queue
// @SIZE-1 position:  If front is at 0 and rear !=0 then element will be added at 0 -1 position, but -1 is a null position and Queue is circular as well
// Then the element will be added at SIZE-1 Position and will be considered as front

void InsertAtBegin()
{
    // element which will be added in Queue
    int element;

    if(isFull())
    {
        printf("Queue is Full\n");
    }
    else
    {   
        printf("Enter the element::\t");
        scanf("%d",&element); 
        
        if(isEmpty())
        {
            front = rear = 0;
        }
        else if(front == 0)
        {
            front = SIZE-1;
        }
        else
        {
            // because adding element previous to front
            front--;
        }
        Queue[front] = element;
    } 
}

// When we insert at element at rear position then rear position will be incremented and will be the position of new element
// @SIZE-1 Position: if rear is at last positon and 0th position is not full then next element will be added to 0 th position because Queue is @cicrular

void InsertAtEnd()
{
    // element which will be added in Queue
    int element;
    if(isFull())
    {
        printf("Queue is Full");
    }
    else 
    {
        printf("Enter the element::\t");
        scanf("%d",&element);
        
        if(isEmpty())
        {
            front = rear = 0;
        }
        else if(rear==SIZE-1)
        {
            rear = 0;
        }
        else
        {
            // adding element at end after rear
            rear++;
        }
        Queue[rear] = element;
    }
}

void DeleteFront()
{
    if(isEmpty())
    {
        printf("Queue is Empty");
    }
    else
    {
        printf("Deleted Element is:: %d\n",Queue[front]);
        if(front==rear)
        {
            front = rear = -1;
        }
        else if(front == SIZE-1)
        {
            front = 0;
        }
        else
        {
            front++;
        }
    }
}

void DeleteRear()
{
    if(isEmpty())
    {
        printf("Queue is Empty");
    }
    else
    {
        printf("Deleted Element is:: %d\n",Queue[rear]);
        if(front==rear)
        {
            front = rear = -1;
        }
        else if(rear == 0)
        {
            rear = SIZE-1;
        }
        else
        {
            rear--;
        }
    }
}

void TraverseFromFront()
{
    int i; //iterator
    if(isEmpty())
    {
        printf("Queue is Empty");
    }
    else
    {
        for(i=front;i!=rear;i=(i+1)%SIZE)
        {
            printf("%d\n",Queue[i]);
        }
        printf("%d\n",Queue[i]); //Becasue We need to print last element as well
    }
}


// Error
// If you know about this tell me also
void TraverseFromRear()
{
    int i;
    if(isEmpty())
    {
        printf("Queue is Empty");
    }
    else
    {
        for(i=rear;i!=front;i=(i-1)%SIZE)
        {
            printf("%d\n",Queue[i]);
        }
        printf("%d\n",Queue[i]); //because we need to print last element as well
    }
}