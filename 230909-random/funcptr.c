#include <stdio.h>
#include <stdlib.h>

int add(int, int);
int sub(int, int);

int main(void)

{
	int choice;

	int (*funcptr[])(int, int) = {add, sub};
	printf("Choose a number \n1.add\n2.sub\n");


	scanf("%d", &choice);
	printf("%d\n", funcptr[choice](1, 2));

	return (0);
}

int add(int a, int b)
{
	return (a + b);
}
int sub(int a, int b)
{
	return (a - b);
}
