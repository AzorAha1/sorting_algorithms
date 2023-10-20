#include "sort.h"
/**
* bubble_sort - function name
* @array: array
* @size: size
* Description - this sorts an array in ascending order
*/
void bubble_sort(int *array, size_t size)
{
	size_t i;
	size_t j;
	size_t store;
	size_t k;

	for (i = 0; i < size - 1; i++)
	{
		for (j = 0; j < size - 1; j++)
		{
			if (array[j] > array[j + 1])
			{
				store = array[j];
				array[j] = array[j + 1];
				array[j + 1] = store;
				for (k = 0; k < size; k++)
				{
					if (k > 0)
					{
						printf(", ");
					}
					printf("%d", array[k]);
				}
				printf("\n");
			}
		}
	}
}
