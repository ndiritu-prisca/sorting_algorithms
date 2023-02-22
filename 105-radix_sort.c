#include "sort.h"

/**
  * get_max - a function that gets the largest value in an array
  * @array: array to sort
  * @size: size of the array
  * Return: the largest number
  */
int get_max(int *array, size_t size)
{
	size_t i;
	int max = 0;

	for (i = 0; i < size; i++)
	{
		if (array[i] > max)
			max = array[i];
	}
	return (max);
}

/**
  * radix_count - a function that sorts the significant digits of an array of
  * integers in ascending order using the counting sort algorithm
  * @array: array to sort
  * @size: size of the array
  * @exp: variable that helps get the place value of a digit in a number
  * Return: nothing
  */
void radix_count(int *array, size_t size, int exp)
{
	int *new;
	int i, temp[10] = {0};

	/* Store count of occurrences in count[]*/
	for (i = 0; i < (int)size; i++)
		temp[(array[i] / exp) % 10]++;

	for (i = 1; i < 10; i++)
		temp[i] += temp[i - 1];

	/* Build the new array*/
	new = malloc(sizeof(int) * size);
	if (new == NULL)
		return;
	for (i = (int)size - 1; i >= 0; i--)
	{
		new[temp[(array[i] / exp) % 10] - 1] = array[i];
		temp[(array[i] / exp) % 10]--;
	}

	for (i = 0; i < (int)size; i++)
		array[i] = new[i];
	print_array(array, size);

	free(new);
}

/**
  * radix_sort - a function that sorts an array of integers in ascending order
  * using the Radix sort algorithm
  * @array: array to sort
  * @size: size of the array
  * Return: nothing
  */
void radix_sort(int *array, size_t size)
{
	int max = get_max(array, size);
	int exp;

	for (exp = 1; max / exp > 0; exp *= 10)
		radix_count(array, size, exp);
}
