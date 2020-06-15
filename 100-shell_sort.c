#include "sort.h"

/**
 *shell_sort - sorts array of int, ascending order using,with Knuth sequence
 *@array: array or integers
 *@size: # of element in array
 *Return: void
 */
void shell_sort(int *array, size_t size)
{
	int inter = 1, swap, close, far;

	if (array == NULL)
		return;

	while (inter < (int)size / 3)
		inter = (inter * 3) + 1;

	while (inter > 0)
	{
		for (far = inter; far < (int)size; far++)
		{
			swap = array[far];
			close = far;
			while (close > inter - 1 && array[close - inter] > swap)
			{
				array[close] = array[close - inter];
				close = close - inter;
			}
			array[close] = swap;
		}
		inter = (inter - 1) / 3;
		print_array(array, size);
	}
}
