#include "sort.h"

/**
  * shell_swap - a function that swaps 2 integers
  * @x: pointer to first int
  * @y: pointer to second int
  * Return: nothing
  */
void shell_swap(int *x, int *y)
{
	int temp = *x;
	*x = *y;
	*y = temp;
}

/**
  * shell_sort - a function that sorts an array of integers in ascending order
  * using the Shell sort algorithm, using the Knuth sequence
  * @array: array to be sorted
  * @size: size of the array
  * Return: nothing
  */
void shell_sort(int *array, size_t size)
{
	size_t gap, x, y;

	if (array == NULL || size < 2)
		return;

	for (gap = 1; gap < (size / 3); gap = gap * 3 + 1)
		;

	for (; gap >= 1; gap /= 3)
	{
		for (x = gap; x < size; x++)
		{
			y = x;
			while (y >= gap && array[y - gap] > array[y])
			{
				shell_swap(array + y, array + (y - gap));
				y = y - gap;
			}
		}
		print_array(array, size);
	}
}
