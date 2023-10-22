#include <stdio.h>

struct person {
	int age;
	int order;
};

struct details {
	struct person location;
	struct person personality;
};

int main()
{
	struct person Ahmed;
	struct details Fahad;

	Ahmed.age = 12;
	Ahmed.order = 3;

	Fahad.location.age = 4;

	printf("Ahmed's age is   : %d\n", Ahmed.age);
	printf("And his order is : %02d\n", Ahmed.order);
	printf("Fahad age is     : %02d\n", Fahad.location.age);

	return (0);
}
