#include "sort.h"

/**
  * quick_swap - a function that swaps 2 integer
  * @x: first integer
  * @y: second integer
  * Return: nothing
  */
void quick_swap(int *x, int *y)
{
	int temp = *x;
	*x = *y;
	*y = temp;
}

/**
  * quick_sort_recursion - a function that recursively does a quick sort
  * @array: the array to sort
  * @min: first index of the array
  * @max: last index of the array
  * @size: size of the array
  * Return: nothing
  */
void quick_sort_recursion(int *array, int min, int max, size_t size)
{
	int pivot_idx;

	if (min < max)
	{
		pivot_idx = partition(array, min, max, size);
		quick_sort_recursion(array, min, pivot_idx - 1, size);
		quick_sort_recursion(array, pivot_idx + 1, max, size);
	}
}

/**
  * partition - a function that implements the Lomuto partitioning
  * @array: the array to partiton
  * @min: first index of the array
  * @max: last index of the array
  * @size: size of the array
  * Return: pivot index
  */
int partition(int *array, int min, int max, size_t size)
{
	int pivot_val = array[max], i = min, j;

	for (j = min; j < max; j++)
	{
		if (array[j] <= pivot_val)
		{
			quick_swap(&array[i], &array[j]);
			if (i != j)
				print_array(array, size);
			i++;
		}
	}
	quick_swap(&array[i], &array[max]);
	if (i != j)
		print_array(array, size);
	return (i);
}

/**
  * quick_sort - a function that sorts an array of integers in ascending order
  * using the Quick sort algorithm
  * @array: the array to be sorted
  * @size: size of the array
  * Return: nothing
  */
void quick_sort(int *array, size_t size)
{
	quick_sort_recursion(array, 0, size - 1, size);
}
