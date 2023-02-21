#include "sort.h"

/**
  * find_max - a function that finds the largest integer in an array
  * @array: array to search
  * @size: size of the array
  * Return: largest integer
  */
int find_max(int *array, size_t size)
{
	int i, max = 0;

	for (i = 0; i < (int)size; i++)
	{
		if (array[i] > max)
			max = array[i];
	}
	return (max);
}

/**
  * counting_sort - a function that sorts an array of integers in ascending
  * order using the Counting sort algorithm
  * @array: array to sort
  * @size: size of the array
  * Return: nothing
  */
void counting_sort(int *array, size_t size)
{
	int i, k, *count_arr, *sorted_arr;

	if (array == NULL || size < 2)
		return;

	k = find_max(array, size);
	count_arr = malloc(sizeof(int) * (k + 1));
	if (count_arr == NULL)
		return;
	for (i = 0; i < (k + 1); i++)
		count_arr[i] = 0;
	for (i = 0; i < (int)size; i++)
		count_arr[array[i]] += 1;
	for (i = 0; i < (k + 1); i++)
		count_arr[i] += count_arr[i - 1];
	print_array(count_arr, k + 1);

	sorted_arr = malloc(sizeof(int) * size);
	if (sorted_arr == NULL)
	{
		free(count_arr);
		return;
	}

	for (i = 0; i < (int)size; i++)
	{
		sorted_arr[count_arr[array[i]] - 1] = array[i];
		count_arr[array[i]] -= 1;
	}

	for (i = 0; i < (int)size; i++)
		array[i] = sorted_arr[i];

	free(count_arr);
	free(sorted_arr);
}
