#include "sort.h"

/**
 * partition - divide numbers around pivot.
 * @array: array
 * @size: size of array.
 * @lo: low value, or init.
 * @hi: high value, or last.
 * Return: i.
 */

int partition(int *array, size_t size, int lo, int hi)
{
	int pivot, i, j, temp;

	pivot = array[hi];
	i = lo;

	for (j = lo; j < hi; j++)
	{
		if (array[j] < pivot)
		{
			temp = array[i];
			array[i] = array[j];
			array[j] = temp;
			i++;
		}
	}
	temp = array[i];
	array[i] = array[hi];
	array[hi] = temp;

	print_array(array, size);
	return (i);
}

/**
 * quicksort - recursive function.
 * @array: array.
 * @size: size of array.
 * @lo: low value, or init.
 * @hi: high value, or last.
 */

void quicksort(int *array, size_t size, int lo, int hi)
{
	int p;

	if (lo < hi)
	{
		p = partition(array, size, lo, hi);
		quicksort(array, size, lo, p - 1);
		quicksort(array, size, p + 1, hi);
	}
}

/**
 * quick_sort - quick insertion method.
 * @array: array.
 * @size: size of array.
 */

void quick_sort(int *array, size_t size)
{
	if (array && size > 1)
		quicksort(array, size, 0, size - 1);
}
