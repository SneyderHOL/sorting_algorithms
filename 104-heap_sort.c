#include "sort.h"

/**
 *heap_sort - sorts array of integers, ascending order, Heap sort-siftdown
 *@array: array of integers to be sorted
 *@size: # of element in array
 *Retrunr: void
 */
void heap_sort(int *array, size_t size)
{
	int len = size, swap, l = 0;

	make_heap(array, size);
	while (len > 1)
	{
		swap = array[0];
		len--;
		array[0] = array[len];
		array[len] = swap;
		print_array(array, size);
		sift_down(array, len, l, size);
	}
}

/**
 *make_heap - makes a in-place heap for array
 *@array: array of integer to make heap
 *@size: # of elements in array
 *Return:void
 */
void make_heap(int *array, size_t size)
{
	int half = size / 2;

	while (half)
	{
		half--;
		sift_down(array, size, half, size);
	}
}

/**
 *sift_down - orders heap for array in siftdown implementation
 *@array: array of integer to make heap
 *@size: # of elements in array
 *@size1: # of elements in array
 *@len: modified size from calling function
 *Return:void
 */
void sift_down(int *array, size_t size, int len, size_t size1)
{
	int k = len, j = 2 * k + 1;
	int x = array[k], size2 = (int)size;

	while (j < size2)
	{
		if (j < size2 - 1)
			if (array[j] < array[j + 1])
				j++;
		if (x >= array[j])
			break;
		if (k != j)
		{
			array[k] = array[j];
			array[j] = x;
			print_array(array, size1);
		}
		k = j;
		j = 2 * k + 1;
	}
}
