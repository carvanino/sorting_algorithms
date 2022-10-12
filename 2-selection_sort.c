#include "sort.h"

/**
 * selection_sort - a function that sorts an
 * array using the selection sort algorithm
 *
 * @array: the array to be sorted
 * @size: the size of the array
 */

void selection_sort(int *array, size_t size)
{
	int current, temp, smallest;
	size_t i, j, idx;

	if (size < 2)
		return;

	for (i = 0; i < size; i++)
	{
		current = array[i];
		smallest = current;
		idx = i;
		for (j = i; j < size; j++)
		{
			if (smallest > array[j])
			{
				smallest = array[j];
				idx = j;
			}
		}
		if (idx != i)
		{
			temp = array[i];
			array[i] = array[idx];
			array[idx] = temp;
			print_array(array, size);
		}
	}
}
