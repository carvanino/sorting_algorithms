#include "sort.h"


void swap_element(int *array, int size, int idx_1, int idx_2);
/*size_t n = 10;*/

/**
 * quick_sort - sorts an array of integers in ascending orders
 * using the Quick sort algorithm and the Lomuto partition scheme
 *
 * @array: Array to be sorted
 * @size: Number of element in array
 *
 */

void quick_sort(int *array, size_t size)
{
	int end = size - 1;

	if (array == NULL || size < 2)
	{
		return;
	}

	_quick_sort(array, size, 0, end);
}

/**
 * _quick_sort - sorts by partitions the array repeatedly until
 * the appropriate position of an element is found
 *
 * @array: Array to sort
 * @size: size of given array
 * @start: beginning of the array
 * @end: end of the array
 *
 */

void _quick_sort(int *array, size_t size, size_t start, size_t end)
{
	int pi; /* pivot index */
	int a = 0; /* comparison index */
	/*size_t start = 0;*/
	/*size_t end = size - 1;*/
	/*const int n = size;*/
	/*size_t n = 0;*/

	/*print_array(array, end);*/
	if (start < end)
	{
		pi = end;
		a = start;

		while (pi != a)
		{
			if (array[pi] > array[a] && pi < a)
			{
				swap_element(array, size, pi, a);
			}
			else if (array[pi] < array[a] && pi > a)
			{
				swap_element(array, size, pi, a);
			}
			else
			{
			}

			if (pi < a)
			{
				a -= 1;
			}
			else if (pi > a)
			{
				a += 1;
			}
		}
		if (array[pi] > array[pi - 1])
		{
			end = pi - 1;
			_quick_sort(array, size, 0, end);
		}
		else
		{
			start = pi + 1;
			end = size - 1;
			_quick_sort(array, size, start, end);
		}
	}
}



/**
 * swap_element - swap the position of two elemnt in an array
 *
 * @array: The array that contains the element to swap
 * @size: size of the array
 * @idx_1: An element index to be swapped
 * @idx_2: An element index to be swapped
 *
 */

void swap_element(int *array, int size, int idx_1, int idx_2)
{
	int temp = 0;


	/* Swaps Array Element */
	temp = array[idx_1];
	array[idx_1] = array[idx_2];
	array[idx_2] = temp;

	/* Swaps Index */
	temp = idx_1;
	idx_1 = idx_2;
	idx_2 = temp;
	print_array(array, size);


}
