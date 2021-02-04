#include "sort.h"

/**
 * merge_sort - sorts an array of integers in ascending order using
 * the Merge sort algorithm
 * @array: array to sort
 * @size: size of the array
 * Return: void
 */
void merge_sort(int *array, size_t size)
{
	size_t i;
	int *copy;

	if (array == NULL || size < 2)
		return;
	copy = malloc(sizeof(int) * size);
	if (copy == NULL)
		return;
	for (i = 0; i < size; i++)
		copy[i] = array[i];
	merge_sort_h(0, size, array, copy);
	free(copy);
}
