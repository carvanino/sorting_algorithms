#include "sort.h"

/**
 * bubble_sort - sorts an array of integers in ascending order using
 * the Bubble sort algorithm
 *
 * @array: Array of integers to sort
 * @size: Number of element in array
 *
 */

void bubble_sort(int *array, size_t size)
{
	int index = 0, temp = 0;
	int i, j;

	index = size - 1;
	if (size < 2)
	{
		return;
	}

	for (i = 0; i < index; i++)
	{
		for (j = 0; j < index - i; j++)
		{
			if (array[j] > array[j + 1])
			{
				temp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = temp;
				print_array(array, size);
			}
		}
	}
}
