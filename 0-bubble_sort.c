#include "sort.h"

/**
 * bubble_sort - sorts an array of integers in ascending order using Bubble
 * sort algorithm.
 * @array: pointer to the array to sort
 * @size: size of the array
 *
 */
void bubble_sort(int *array, size_t size)
{
	size_t i = -1, aux = 0, length = size;

	if (array == NULL && size <= 1)
		return;
	while (i != 0)
	{
		i = 0;
		while (i < length - 1)
		{
			if (array[i] > array[i + 1])
			{
				aux = array[i + 1];
				array[i + 1] = array[i];
				array[i] = aux;
				print_array(array, size);
			}
			i++;
		}
		length--;
	}
}
