#include "sort.h"

/**
 * radix_sort - function that sorts an array of integers in ascending order
 * using the Radix sort algorithm
 * @array: pointer to the array to sort
 * @size: size of the array
 *
 */
void radix_sort(int *array, size_t size)
{
	int max = 0, div = 1, radix = 10;
	size_t i = 0;

	if (array == NULL || size <= 1)
		return;

	max = array[0];
	for (i = 0; i < size; i++)
	{
		if (array[i] > max)
			max = array[i];
	}
	while (max / div >= 1)
	{
		sort_digit(array, size, radix, div);
		div *= radix;
	}
}
/**
 * sort_digit - function that sorts an array of integers in ascending order
 * using the Radix sort algorithm
 * @array: pointer to the array to sort
 * @size: size of the array
 * @radix: base number of digits
 * @div: number to divide the element in array to operate with the result
 *
 */
void sort_digit(int *array, size_t size, int radix, int div)
{
	int *buckets = NULL, *output = NULL, b_index = 0, i = 0;
	size_t j = 0;

	buckets = malloc(sizeof(int) * radix);
	if (buckets == NULL)
		return;
	output = malloc(sizeof(int) * size);
	if (output == NULL)
	{
		free(buckets);
		return;
	}
	for (i = 0; i < radix; i++)
		buckets[i] = 0;
	for (j = 0; j < size; j++)
	{
		b_index = (array[j] / div) % radix;
		buckets[b_index] += 1;
	}
	for (i = 1; i < radix; i++)
		buckets[i] += buckets[i - 1];
	for (i = (int)size - 1; i >= 0; i--)
	{
		b_index = (array[i] / div) % radix;
		output[--buckets[b_index]] = array[i];
	}
	for (j = 0; j < size; j++)
		array[j] = output[j];
	print_array(array, size);
	free(buckets);
	free(output);
}
