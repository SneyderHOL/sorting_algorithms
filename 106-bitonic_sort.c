#include "sort.h"

/**
 *comp_swap - compares 2 array elements and swaps if condition is true
 *@array: array of integers to be sorted
 *@i: fisrt element in array to be compared
 *@j: second element in array to be compared
 *@dir: 1 for ascending order, 0 descending order
 *Return:void
 */
void comp_swap(int *array, int i, int j, int dir)
{
	int swap = 0;

	if (dir == (array[i] > array[j]))
	{
		swap = array[j];
		array[j] = array[i];
		array[i] = swap;
	}
}

/**
 *bitonic_merge - splits array in 2 subarray recursively
 *@array: array of integers to be sorted
 *@low: base value to start ascending order
 *@size: #of elements in array
 *@dir: 1 for ascending order, 0 descending order
 *Return:void
 */
void bitonic_merge(int *array, int low, size_t size, int dir)
{
	int i = low, k = 0;

	if (size > 1)
	{
		k = size / 2;
		for (; i < low + k; i++)
		{
			comp_swap(array, i, i + k, dir);
			bitonic_merge(array, low, k, dir);
			print_array(array, size);
			bitonic_merge(array, low + k, k, dir);

		}
	}
}
/**
 *bitonic_up - splits array in 2 subarray recursively
 *@array: array of integers to be sorted
 *@low: base value to start ascending order
 *@size: #of elements in array
 *@dir: 1 for ascending order, 0 descending order
 *Return:void
 */
void bitonic_up(int *array, int low, size_t size, int dir)
{
	int k = 0;

	printf("Merging [%d / %d] (UP):\n", k, k);
	print_array(array, size);
	if (size > 1)
	{
		k = size / 2;
		bitonic_up(array, low, k, 1);
		bitonic_up(array, low + k, k, 0);
		bitonic_merge(array, low, size, dir);
	}
}
/**
 *bitonic_sort - sorts an array of integers in ascending order
 *@array: array of integers to be sorted
 *@size: #of elements in array
 *Return:void
 */
void bitonic_sort(int *array, size_t size)
{
	int up = 1;

	if (array == NULL || size <= 1)
		return;
	bitonic_up(array, 0, size, up);
}
