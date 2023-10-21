#include "sort.h"

/**
* selection_sort - function name
* @array: array
* @size: size of array
* Description - this sorts doubly linked list of int in ascending order
*/
void selection_sort(int *array, size_t size)
{
	size_t i, j, minimum, temp;

	if (!array && size < 2)
	{
		return;
	}
	for (i = 0; i < size - 1; i++)
	{
		minimum = i;
		for (j = i + 1; j < size; j++)
		{
			if (array[minimum] > array[j])
			{
				minimum = j;
			}
		}
		if (i != minimum)
		{
			temp = array[i];
			array[i] = array[minimum];
			array[minimum] = temp;
			print_array(array, size);
		}
	}


}
