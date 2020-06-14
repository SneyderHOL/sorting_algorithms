#include "sort.h"

/**
 *quick_sort -  sorts array of integers, ascending order using the Quick sort
 *@array: array of integers
 *@size: # of elements in array
 *Return: void
 */
void quick_sort(int *array, size_t size)
{

	if (array == NULL || size <= 1)
		return;
	partition(array, size, array, size);
}

/**
 *partition - sorts 2 subarrays form quick_sort input
 *@array: original array for printing
 *@size: size of array
 *@vector: copy of array to make partitions
 *@len: size of each partition
 *Return: void
 */
void partition(int *array, size_t size, int *vector, size_t len)
{

	size_t low = 0, high = len - 1, i, j;
	int pivot = 0, swap = 0;

	if (len <= 1)
		return;
	i = low - 1, j = low;
	pivot = vector[high];
	for (; j < high; j++)
	{
		if (vector[j] <= pivot)
		{
			i++;
			if (i != j)
			{
				swap = vector[i];
				vector[i] = vector[j];
				vector[j] = swap;
				print_array(array, size);
			}
		}
	}
	if (pivot < vector[i + 1])
	{
		swap = vector[i + 1];
		vector[i + 1] = vector[high];
		vector[high] = swap;
		print_array(array, size);
	}

	partition(array, size, vector, (i + 1));
	partition(array, size, &vector[i + 2], (high - (i + 1)));
}
