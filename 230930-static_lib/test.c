#include <stdio.h>
#include "mylib.h"

int main(void)
{
	int x, y;

	x = 10;
	y = 5;
	
	printf("x + y is %d\n", add(x, y));
	printf("x + y is %d\n", substract(x, y));

	return (0);
}
