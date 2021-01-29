#include "sort.h"

/**
 * bubble_sort - sorts an array of integers in
 * ascending order using the bubble_sort algorithm
 * @array: array to be sorted
 * @size: size of the array
 */

void bubble_sort(int *array, size_t size)
{
	size_t i, x, new;
	int swap;

	if (array == NULL || size == 0)
		return;

	x = size;
	while (x > 0)
	{
		new = 0;
		for (i = 0; i < x - 1; i++)
		{
			if (array[i] > array[i + 1])
			{
				swap = array[i];
				array[i] = array[i + 1];
				array[i + 1] = swap;
				new = i + 1;
				print_array(array, size);
			}
		}
		x = new;
	}
}
