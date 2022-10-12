#include "sort.h"

/**
 * selection_sort - Sorts an array of integers in ascending order
 * Using the selection sort algorithm
 *
 * @array: Array of integers
 * @size: Number of element in array
 *
 */

void selection_sort(int *array, size_t size)
{
	int i, j;
	int min;
	int index = size - 1;
	int temp;

	
	for (i = 0; i < index; i++)
	{
		min = i;
		for (j = i + 1; j <= index; j++)
		{
			if (array[j] < array[min])
			{
				min = j;
			}
		}
		if (min != i)
		{
			temp = array[i];
			array[i] = array[min];
			array[min] = temp;
			print_array(array, size);
		}
	}
}
