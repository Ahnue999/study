/**
 * swap - swaps two integers
 * @a: first int.
 * @b: second int.
 *
 * Return: 1 when done.
 */
int swap(int *a, int *b)
{
		int tmp;

		tmp = *a;
		*a = *b;
		*b = tmp;

		return (1);
}
