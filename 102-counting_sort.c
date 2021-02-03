#include "sort.h"
#include <stdlib.h>

/**
 *
 *
 *
 */

void print_cs(int* array, int n)
{
	int i, j;
	char *sep;

	sep = "";

	for (j = 0; j < array[0]; j++)
	{
		printf("%s%d", sep, 0);
		sep = ", ";
	}

	sep = "";
	for (i = 1; i < n; i++)
	{
		for (j = array[i - 1]; j < array[i]; j++)
		{
			printf("%s%d", sep, i);
			sep = ", ";
		}
	}
	putchar(10);
}
/**
 * counting_sort - counting sort method.
 * @array: array.
 * @size: size of array.
 */

void counting_sort(int *array, size_t size)
{
	int *count, max = 0, *out, n, i, temp;

	n = size;
	for (i = 0; i < n; i++)
		if (array[i] > max)
			max = array[i];

	count = malloc(sizeof(int) * (max + 1));

	if (!count)
		return;
	for (i = 0; i <= max; i++)
		count[i] = 0;

	for (i = 0; i <= n - 1; i++)
		count[array[i]] += 1;

	for (i = 1; i <= max; i++)
		count[i] += count[i - 1];

	out = malloc(sizeof(int) * (size));

	for (i = 0; i < n; i++)
		out[i] = 0;

	for (i = n - 1; i > -1; i--)
	{
		temp = --count[array[i]];
		out[temp] = array[i];
	}

	for (i = 0; i < n; i++)
		array[i] = out[i];

	free(count);
	free(out);
	print_cs(array, n);
}
