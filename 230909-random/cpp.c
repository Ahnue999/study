#include <stdio.h>

#define A 10

int main(void)
{
	printf("Macro A is : %d\n", A);

#undef A
#define A 20

	printf("Macro A is : %d\n", A);
	return (0);
}
