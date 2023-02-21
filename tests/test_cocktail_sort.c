#include "sort.h"

void backward_sort(int *array, size_t i, size_t size)
{
	size_t k;
	int temp = 0;
	for (k = size - 2; k > i ; k--)
	{
		if (array[k] < array[k - 1])
		{
			temp = array[k];
			array[k] = array[k - 1];
			array[k - 1] = temp;
			print_array(array, size);
		}
	}
}

/**
  * bubble_sort -  a function that sorts an array of integers in ascending
  * order using the Bubble sort algorithm
  * @array: an array of integers
  * @size: size of the array
  * Return: nothing
  */
void test_cocktail_sort(int *array, size_t size)
{
	size_t i, j;
	int temp = 0;

	if (array == NULL || size < 2)
		return;

	for (i = 0; i < size - 1; i++)
	{
		for (j = 0; j < size - i - 1; j++)
		{
			if (array[j] > array[j + 1])
			{
				temp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = temp;
				print_array(array, size);
			}
		}
		backward_sort(array, i, size);
	}
}
