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
	size_t current = 0, next = 0, minor = 0;
	int aux = 0;

	if (array == NULL)
		return;
	for (current = 0; current < size - 1; current++)
	{
		next = current + 1;
		aux = array[current];
		while (next < size)
		{
			if (aux > array[next])
			{
				minor = next;
				aux = array[next];
			}
			next++;
		}
		if (array[minor] != array[current])
		{
			aux = array[current];
			array[current] = array[minor];
			array[minor] = aux;
			print_array(array, size);
		}
	}
}
