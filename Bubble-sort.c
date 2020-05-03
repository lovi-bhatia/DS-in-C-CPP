#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define CAPACITY 10

int Sort(int array[]);

void main()
{
	// for random numbers everytime
	srand(time(0));

	int array[CAPACITY];
	int i,j;

	for(i=0;i<CAPACITY;i++)
	{
		array[i] = (rand()%100)*10;
	}

	printf("\n\n\n");

	Sort(array);
}

int Sort(int array[])
{
	int i,temp,j,count = 0;
	printf("\n");
	for(i=0;i<=CAPACITY;i++)
	{
		printf("%d\n",array[i]);
	}

	printf("\n\n\n");

	for(j=0;j<CAPACITY;j++	)
		{
			for(i=0;i<CAPACITY;i++)
				{
					if(array[i]>array[i+1])
					{
						temp = array[i];
						array[i] = array[i+1];
						array[i+1] = temp;
						count++;
					}
				}
		}

	for(i=0;i<=CAPACITY;i++)
	{
		printf("%d\n",array[i]);
	}

	printf("\nNumber of Exchanges made for sorting:: %d\n",count);
}