#include "sort.h"

/**
 * lom_partition - Prints the lomuto partition scheme
 * @array: The array to be sorted
 * @high: the high index
 * @low: the low index
 *
 * Return: The pivot index
 */
size_t lom_partition(int *array, ssize_t low, ssize_t high)
{
	int pivot, temp;
	ssize_t i = low -1, j;

	pivot = array[high];
	for (j = low; j < high; j++)
	{
		if (array[j] <= pivot)
		{
			i++;
			temp = array[i];
			array[i] = array[j];
			array[j] = temp;

			print_array(array, high + 1);
		}
	}
	temp = array[i + 1];
	array[i + 1] = array[high];
	array[high] = temp;

	print_array(array, high + 1);
	return (i + 1);
}

/**
 * quicksort - sorts the array in ascending order
 * @array: the array to be sorted
 * @low: low index
 * @high: high index
 */

void quicksort(int *array, ssize_t low, ssize_t high)
{
	size_t p;

	if (low < high)
	{
		p = lom_partition(array, low, high);

		quicksort(array, low, p - 1);
		quicksort(array, p + 1, high);
	}
}

/**
 * quick_sort - Sorts an array of integers in ascending order
 * using the quick sort algorithm
 * @array: The array to be sorted
 * @size: The size of the array
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	quicksort(array, 0, size - 1);
}
