#include "sort.h"

/**
 *shell_sort - sorts array of int, ascending order using,with Knuth sequence
 *@array: array or integers
 *@size: # of element in array
 *Return: void
 */
void shell_sort(int *array, size_t size)
{
	int inter = 1, swaped = 0, close = 0, far = 0;

	if (array == NULL && size <= 1)
		return;

	while (inter < (int)size)
		inter = (inter * 3) + 1;
	if (inter >= (int)size)
		inter = (inter - 1) / 3;

	while (inter > 0)
	{
		for (far = inter; far < (int)size; far++)
		{
			swaped = array[far];
			close = far;
			while (close > inter - 1 && array[close - inter] > swaped)
			{
				array[close] = array[close - inter];
				close = close - inter;
			}
			array[close] = swaped;
		}
		inter = (inter - 1) / 3;
		print_array(array, size);
	}
}
