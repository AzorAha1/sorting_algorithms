#include "sort.h"

/**
 * quick_sort - a function that sorts an array of integers
 * in ascending order using the quick sort algorithm
 * @array: The array to be sorted
 * @size: the size of the list to be sorted from
 */

void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	quicksort(array, 0, size - 1, size);
}

/**
 * quicksort - sorst an array using quick sort with lomuto
 * @array: the array to be sorted
 * @low: the low index to be sorted
 * @high: the high index to be sorted
 * @size: the size of the array
 */

void quicksort(int *array, int low, int high, size_t size)
{
	int part_index;


	if (low < high)
	{
		part_index = lomuto_partition(array, low, high, size);

		quicksort(array, low, part_index - 1, size);
		quicksort(array, part_index + 1, high, size);
	}
}

/**
 * lomuto_partition - Iterates over the input array, swapping
 * elements that are strictly < pre-selected pivot elem
 * @array: the array to be sorted
 * @low: the low index in the array
 * @high: the high index in the array
 * @size: the size of the array
 *
 * Return: The pivot index.
 */

int lomuto_partition(int *array, int low, int high, size_t size)
{
	int pivot;
	int i, j, temp;

	pivot = array[high];
	i = low - 1;

	for (j = low; j <= high - 1; j++)
	{
		if (array[j] <= pivot)
		{
			i++;
			temp = array[i];
			array[i] = array[j];
			array[j] = temp;
			print_array(array, size);
		}
	}

	temp = array[i + 1];
	array[i + 1] = temp;
	array[high] = temp;
	print_array(array, size);

	return (i + 1);
}
