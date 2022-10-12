#include "sort.h"

void swap(int *arr, int a, int b, int size);
int patition(int *a, int start, int end, int arr_size);
int *sort(int *array, int start, int end, int arr_size);

/**
 * quick_sort - a function that sorts an array
 * using the quick sort algorithm
 *
 * @array: the array
 * @size: the size of the array
 */

void quick_sort(int *array, size_t size)
{
	if (size < 2 || array == NULL)
		return;

	sort(array, 0, size - 1, size);
}

/**
 * swap - swaps two elements
 *
 * @arr: the array
 * @a: first index
 * @b: the second index
 * @size: the size of the array
 */

void swap(int *arr, int a, int b, int size)
{
	int tmp;

	tmp = arr[a];
	arr[a] = arr[b];
	arr[b] = tmp;
	print_array(arr, size);
}

/**
 * patition - patition the array
 *
 * @a: the array
 * @start: the index to start from i.e the pi
 * @end: the end of the array, i.e pivot
 * @arr_size: size of the array
 *
 * Return: the patition index
 */

int patition(int *a, int start, int end, int arr_size)
{
	int pivot, pi, i;

	pivot = a[end];
	pi = start;

	for (i = start; i < end; i++)
	{
		if (a[i] <= pivot)
		{
			if (i != pi && a[i] != a[pi])
			{
				swap(a, pi, i, arr_size);
				pi++;
			}
			/*print_array(a, arr_size);*/
		}
	}

	if (start != end && a[pi] != a[end])
		swap(a, pi, end, arr_size);
	/*print_array(a, arr_size);*/
	return (pi);
}

/**
 * sort - the actual sort function
 *
 * @array: the array
 * @start: the index to start from
 * @end: the end
 * @arr_size: the size of the array
 *
 * Return: 1
 */

int *sort(int *array, int start, int end, int arr_size)
{
	int pi;

	if (start >= end)
		return (array);

	pi = patition(array, start, end, arr_size);
	sort(array, start, pi - 1, arr_size);
	sort(array, pi + 1, end, arr_size);

	return (0);
}
