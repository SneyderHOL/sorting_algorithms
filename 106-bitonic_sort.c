#include "sort.h"

/**
 *comp_swap - compares 2 array elements and swaps if condition is true
 *@array: array of integers to be sorted
 *@i: fisrt element in array to be compared
 *@j: second element in array to be compared
 *@dir: 1 for ascending order, 0 descending order
 *Return:void
 */
void comp_swap(int *array, int i, int j, int dir, size_t size_f)
{
	int swaped = 0, dist = 0, k = 0;

	dist = j / 2;
	for (k = i; k < dist; k++)
	{
		if ((array[k] > array[k + dist]) && dir)
		{
			swaped = array[k + dist];
			array[k + dist] = array[k];
			array[k] = swaped;
			printf("Result [%d / %d] (UP):\n", j, (int)size_f);
			print_array(array, (size_t)j);
		}
		else if (!(array[k] > array[k + dist]) && !dir)
		{
			swaped = array[k + dist];
			array[k + dist] = array[k];
			array[k] = swaped;
			printf("Result [%d / %d] (DOWN):\n", j, (int)size_f);
			print_array(array, (size_t)j);
		}

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
void bitonic_merge(int *array, int low, size_t size, int dir, size_t size_f)
{
	int i = low, k = 0;

	if (size > 1)
	{
		k = size / 2;
		comp_swap(array, i, size, dir, size_f);
		bitonic_merge(array, low, k, dir, size_f);
		bitonic_merge(array, low + k, k, dir, size_f);
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
void bitonic_up(int *array, int low, size_t size, int dir, size_t size_f)
{
	int k = (int)size;

	if (size > 1)
	{
		if (dir == 1)
		{
			printf("Merging [%d / %d] (UP):\n", k, (int)size_f);
			print_array(array, size);
		}
		else
		{
			printf("Merging [%d / %d] (DOWN):\n", k, (int)size_f);
			print_array(array, size);
		}
		k = size / 2;
		bitonic_up(array, low, k, 1, size_f);
		bitonic_up(array, low + k, k, 0, size_f);
		bitonic_merge(array, low, size, dir, size_f);
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
	bitonic_up(array, 0, size, up, size);
}
