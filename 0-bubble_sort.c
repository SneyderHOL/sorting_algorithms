#include "sort.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * bubble_sort - sorts array of integers in ascending order Bubble sort algor
 * @array: array of integers to be sorted
 * @size: size of array
 * Return: void
 */

void bubble_sort(int *array, size_t size)
{
	size_t j = 1, size2 = size;
	int aux = 0;

	if (array != NULL && size > 1)
	{
		while (j != 0)
		{
			j = 0;
			while (j < (size2 - 1))
			{
				if (array[j] > array[j + 1])
				{
					aux = array[j + 1];
					array[j + 1] = array[j];
					array[j] = aux;
					print_array(array, size);
				}
			j++;
			}
			 size2--;
		}
	}
}
