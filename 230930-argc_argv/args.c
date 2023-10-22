#include <stdio.h>

int main(int argc, char *argv[])
{
	int i;

	printf("The number of arguments is : %d\n", argc);
	
	for (i = 1; i < argc; i++)
	{
		printf("argv[%d} is : %s\n",i , argv[i]);
	}

	return (0);
}

