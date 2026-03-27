#include <stdlib.h>
#include "sort.h"

/**
 * counting_sort - Sorts array by a specific digit place
 * @array: The array to sort
 * @size: Number of elements in the array
 * @exp: The current digit place (1, 10, 100, ...)
 *
 * Return: 0 on success, 1 on failure
 */
static int counting_sort(int *array, size_t size, int exp)
{
	int *output;
	int count[10] = {0};
	size_t i;

	output = malloc(sizeof(int) * size);
	if (!output)
		return (1);

	for (i = 0; i < size; i++)
		count[(array[i] / exp) % 10]++;

	for (i = 1; i < 10; i++)
		count[i] += count[i - 1];

	for (i = size; i > 0; i--)
	{
		output[count[(array[i - 1] / exp) % 10] - 1] = array[i - 1];
		count[(array[i - 1] / exp) % 10]--;
	}

	for (i = 0; i < size; i++)
		array[i] = output[i];

	free(output);
	return (0);
}

/**
 * get_max - Returns the maximum value in an array
 * @array: The array to search
 * @size: Number of elements in the array
 *
 * Return: The maximum value
 */
static int get_max(int *array, size_t size)
{
	int max;
	size_t i;

	max = array[0];
	for (i = 1; i < size; i++)
		if (array[i] > max)
			max = array[i];
	return (max);
}

/**
 * radix_sort - Sorts an array of integers using LSD radix sort
 * @array: The array to sort
 * @size: Number of elements in the array
 */
void radix_sort(int *array, size_t size)
{
	int max, exp;

	if (!array || size < 2)
		return;

	max = get_max(array, size);

	for (exp = 1; max / exp > 0; exp *= 10)
	{
		if (counting_sort(array, size, exp) != 0)
			return;
		print_array(array, size);
	}
}
