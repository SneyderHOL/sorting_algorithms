#include "sort.h"
/**
 * selection_sort -function that sorts an array of integers in ascending order
 * using the Selection sort algorithm
 * @array: pointer to the array to sort
 * @size: size of the array
 *
 */
void selection_sort(int *array, size_t size)
{
	size_t current = 0, next = 0, aux = 0;

	if (array == NULL && size <= 1)
		return;
	for (current = 0; current < size - 1; current++)
	{
		next = current + 1;
		while (next < size)
		{
			if (array[current] > array[next])
			{
				aux = array[current];
				array[current] = array[next];
				array[next] = aux;
			}
			next++;
		}
		print_array(array, size);
	}
}
