#include "sort.h"

/**
* bubble_sort - function name
* @array: array to be sorted
* @size: number of elements in the array
* Description - this sorts an array in ascending order
*/

void bubble_sort(int *array, size_t size)
{
	size_t i;
	int store;
	int swapped;

	for (i = 0; i < size - 1; i++)
	{
		size_t j;

		swapped = 0;
		for (j = 0; j < size - 1; j++)
		{
			if (array[j] > array[j + 1])
			{
				store = array[j];
				array[j] = array[j + 1];
				array[j + 1] = store;
				swapped = 1;
				print_array(array, size);
			}
		}
		if (swapped == 0)
			break;
	}
}
