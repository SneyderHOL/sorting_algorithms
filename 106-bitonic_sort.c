#include "sort.h"

/**
 *comp_swap - compares 2 array elements and swaps if condition is true
 *@array: array of integers to be sorted
 *@j: second element in array to be compared
 *@dir: 1 for ascending order, 0 descending order
 *Return:void
 */
void comp_swap(int *array, int j, int dir)
{
	int i, dist, swaped = 0;

	dist = j / 2;
	if (j <= 1)
		return;
	for (i = 0; i < dist; i++)
	{
		if ((array[i] > array[i + dist]) == dir)
		{
			swaped = array[i];
			array[i] = array[i + dist];
			array[i + dist] = swaped;
		}
	}
	bitonic_merge(array, dist, dir);
	bitonic_merge(&(*(array + dist)), dist, dir);
}

/**
 *bitonic_merge - splits array in 2 subarray recursively
 *@array: array of integers to be sorted
 *@size: #of elements in array
 *@dir: 1 for ascending order, 0 descending order
 *Return:void
 */
void bitonic_merge(int *array, size_t size, int dir)
{

	if (size <= 1)
		return;
	comp_swap(array, size, dir);
}
/**
 *bitonic_up - splits array in 2 subarray recursively
 *@array: array of integers to be sorted
 *@size: #of elements in array
 *@dir: 1 for ascending order, 0 for descending order
 *@size_f: #of elements in array
 *Return:void
 */
void bitonic_up(int *array, size_t size, int dir, size_t size_f)
{
	int k = (int)size;

	if (size <= 1)
		return;
	if (dir == 1)
		printf("Merging [%d/%d] (UP):\n", k, (int)size_f);
	else
		printf("Merging [%d/%d] (DOWN):\n", k, (int)size_f);
	print_array(array, size);
	k = size / 2;
	bitonic_up(array, k, 1, size_f);
	bitonic_up(&(*(array + k)), size - k, 0, size_f);
	bitonic_merge(array, size, dir);
	if (dir == 1)
		printf("Result [%d/%d] (UP):\n", (int)size, (int)size_f);
	else
		printf("Result [%d/%d] (DOWN):\n", (int)size, (int)size_f);
	print_array(array, size);
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
	bitonic_up(array, size, up, size);
}
