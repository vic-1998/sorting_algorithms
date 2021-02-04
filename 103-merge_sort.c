#include "sort.h"


void merge_sort_h(size_t start, size_t end, int *array, int *copy)
{
        size_t middle;
        if (end - start < 2)
                return;
        middle = (start + end) / 2;
merge_sort_h(start, middle, array, copy);
        merge_sort_h(middle, end, array, copy);
        merge(start, middle, end, array, copy);
        for (middle = start; middle < end; middle++)
        copy[middle] = array[middle];
}

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
