#include "sort.h"

/**
 * swap - swaps elements in an array
 * @a: The element to swap
 * @b: The element to swap
 */
void swap(int *a, int *b)
{
	int temp;

	temp = *a;
	*a = *b;
	*b = temp;
}
/**
 * lom_partition - Prints the lomuto partition scheme
 * @array: The array to be sorted
 * @high: the high index
 * @low: the low index
 * @size: size of array
 *
 * Return: The pivot index
 */
size_t lom_partition(int *array, size_t size, ssize_t low, ssize_t high)
{
	int pivot;
	ssize_t i, j;

	pivot = array[high];
	for (i = j = low; j < high; j++)
	{
		if (array[j] < pivot)
		{
			swap(&array[i], &array[j]);
			print_array(array, size);
			i++;
		}
	}

	swap(&array[i], &array[high]);
	print_array(array, size);
	return (i);
}

/**
 * quicksort - sorts the array in ascending order
 * @array: the array to be sorted
 * @low: low index
 * @high: high index
 * @size: size of array
 */

void quicksort(int *array, size_t size, ssize_t low, ssize_t high)
{
	size_t p;

	if (low < high)
	{
		p = lom_partition(array, size, low, high);

		quicksort(array, size, low, p - 1);
		quicksort(array, size, p + 1, high);
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
	if (!array || size < 2)
		return;
	quicksort(array, 0, size, size - 1);
}
