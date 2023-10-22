#include "sort.h"

/**
 * swap - swaps elements in an array
 * @a: The element to swap
 * @b: The element to swap
 * @size: The size of the array
 */
void swap(int *array, size_t size, int *a, int *b)
{
	if (*a != *b)
	{
		*a = *a + *b;
		*b = *b - *a;
		*a = *a - *b;
		print_array((const int *)array, size);
	}
}
/**
 * lom_partition - Prints the lomuto partition scheme
 * @array: The array to be sorted
 * @high: the high index
 * @low: the low index
 * @size: the size of the array
 *
 * Return: The pivot index
 */
size_t lom_partition(int *array, size_t size, ssize_t low, ssize_t high)
{
	int i, j, pivot;

	pivot = array[high];
	for (i = j = low; j < high; j++)
		if (array[j] < pivot)
			swap(array, size, &array[j], &array[i++]);

	swap(array, size, &array[i], &array[high]);
	return (i);

}

/**
 * quicksort - sorts the array in ascending order
 * @array: the array to be sorted
 * @low: low index
 * @high: high index
 * @size: The size of the arrat
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
	if (!array || !size)
		return;
	quicksort(array, size, 0, size - 1);
}
