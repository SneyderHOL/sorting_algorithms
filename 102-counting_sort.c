#include "sort.h"

/**
 * counting_sort - sorts array int, ascending order, Counting sort algorithm
 * @array: array of integers
 * @size: # of element in array
 * Return: vois
 */
void counting_sort(int *array, size_t size)
{
	int max = 0, i = 0, j = (int)size;
	int *count = NULL, *sorted = NULL;

	if (array == NULL || size <= 1)
		return;
	for (i = 0; i < j; i++)
	{
		if (max < array[i])
			max = array[i];
	}
	count = malloc(sizeof(int) * (max + 1));
	if (!count)
		return;
	for (i = 0; i <= max; i++)
		count[i] = 0;
	for (i = 0; i < j; i++)
		count[array[i]] += 1;
	for (i = 1; i <= max; i++)
		count[i] += count[i - 1];
	print_array(count, max + 1);
	sorted = malloc(sizeof(int) * size);
	if (!sorted)
	{
		free(count);
		return;
	}
	for (i = j - 1; i >= 0; i--)
	{
		sorted[count[array[i]] - 1] = array[i];
		count[array[i]] -= 1;
	}
	for (i = 0; i < j; i++)
		array[i] = sorted[i];
	free(count);
	free(sorted);
}
