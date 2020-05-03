#include <stdio.h>
#include <stdlib.h>


/*
	*(array+location/index no.*[Multiply]sizeof(data type));
*/

void main()
{
	int int_arr[5] = {10,20,30,40,50};
	char char_arr[5] = {'a','b','c','d','e'};

	printf("Initial address of char array:%d\n",&char_arr);
	printf("size of char array:%d\n",sizeof(char_arr));
	printf("size of char element %d\n",sizeof(char));

	printf("Initial address of integer array:%d\n",&int_arr);
	printf("size of integer array:%d\n",sizeof(int_arr));
	printf("size of integer element %d\n",sizeof(int));

	printf("\n");

	printf("with passing size of data type\n");
	printf("\n");

	for(int j=0;j<5;j++){
		printf("%c\n",*(char_arr+j*sizeof(char)));
	}

	printf("with index number\n");
	printf("\n");

	for(int i=0;i<5;i++){
		printf("%d %d\n",i,*(int_arr+i));	
	}
	
}