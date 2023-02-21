#include "sort.h"

/**
  * heap_swap - a function that swaps 2 integers
  * @x: first integer
  * @y: second integer
  * Return: nothing
  */
void heap_swap(int *x, int *y)
{
	int temp = *x;
	*x = *y;
	*y = temp;
}

/**
  * heapify - a function that makes the array a max heap
  * @array: array to heapify
  * @size: size of the array
  * @base: index of the base row of the tree
  * @i: root nodeof the binary tree
  * Return: void
  */
void heapify(int *array, size_t size, size_t base, size_t i)
{
	size_t largest = i;
	size_t left = 2 * i + 1;
	size_t right = 2 * i + 2;

	while (left < base && array[left] > array[largest])
	{
		largest = left;
	}

	while (right < base && array[right] > array[largest])
	{
		largest = right;
	}
	if (largest != i)
	{
		heap_swap(array + i, array + largest);
		print_array(array, size);
		heapify(array, size, base, largest);
	}
}

/**
  * heap_sort - a function that sorts an array of integers in ascending order
  * using the Heap sort algorithm
  * @array: array to sort
  * @size: size of the array
  * Return: nothing
  */
void heap_sort(int *array, size_t size)
{
	int i;

	if (array == NULL || size < 2)
		return;
	for (i = (size / 2) - 1; i >= 0; i--)
		heapify(array, size, size, i);
	for (i = size - 1; i > 0; i--)
	{
		heap_swap(array, array + i);
		print_array(array, size);
		heapify(array, size, i, 0);
	}

}
