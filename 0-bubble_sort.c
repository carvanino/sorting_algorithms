#include "sort.h"

/**
 * bubble_sort - a function that sorts an array
 * of integers in assending order using the bubble
 * sort algorithm
 *
 * @array: the array to be sorted
 * @size: the size of the array
 */

void bubble_sort(int *array, size_t size)
{
	int i, hold, check_length = size;

	if (size < 2 || !array)
		return;
	for (i = 0; ; i++)
	{
		if (check_length == 1)
			break;
		if (i + 1 == check_length)
		{
			i = -1; /*results to 0 when the for loop iterates*/
			check_length--;
			continue;
		}
		if (array[i] > array[i + 1])
		{
			hold = array[i + 1];
			array[i + 1] = array[i];
			array[i] = hold;
			print_array(array, size);
		}
	}
}
