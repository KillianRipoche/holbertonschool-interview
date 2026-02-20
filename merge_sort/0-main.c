#include <stdlib.h>
#include <stdio.h>
#include "sort.h"

/**
 * merge - merges two sorted sub-arrays into one
 * @array: the original array
 * @tmp: temporary buffer
 * @left: start index of left sub-array
 * @mid: start index of right sub-array
 * @right: end index (exclusive)
 */
static void merge(int *array, int *tmp, size_t left, size_t mid, size_t right)
{
	size_t i;
	size_t j;
	size_t k;

	printf("Merging...\n[left]: ");
	print_array(array + left, mid - left);
	printf("[right]: ");
	print_array(array + mid, right - mid);

	i = left;
	j = mid;
	k = left;

	while (i < mid && j < right)
	{
		if (array[i] <= array[j])
			tmp[k++] = array[i++];
		else
			tmp[k++] = array[j++];
	}
	while (i < mid)
		tmp[k++] = array[i++];
	while (j < right)
		tmp[k++] = array[j++];

	i = left;
	while (i < right)
	{
		array[i] = tmp[i];
		i++;
	}

	printf("[Done]: ");
	print_array(array + left, right - left);
}

/**
 * merge_rec - recursive top-down merge sort
 * @array: the array to sort
 * @tmp: temporary buffer
 * @left: start index
 * @right: end index (exclusive)
 */
static void merge_rec(int *array, int *tmp, size_t left, size_t right)
{
	size_t mid;

	if (right - left < 2)
		return;

	mid = left + (right - left) / 2;

	merge_rec(array, tmp, left, mid);
	merge_rec(array, tmp, mid, right);
	merge(array, tmp, left, mid, right);
}

/**
 * merge_sort - sorts an array using top-down merge sort
 * @array: array of integers to sort
 * @size: size of the array
 */
void merge_sort(int *array, size_t size)
{
	int *tmp;

	if (!array || size < 2)
		return;

	tmp = malloc(sizeof(int) * size);
	if (!tmp)
		return;

	merge_rec(array, tmp, 0, size);

	free(tmp);
}
