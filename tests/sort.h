#ifndef SORT_H
#define SORT_H

#include <stddef.h>
#include <stdio.h>

/**
 * struct listint_s - Doubly linked list node
 *
 * @n: Integer stored in the node
 * @prev: Pointer to the previous element of the list
 * @next: Pointer to the next element of the list
 */
typedef struct listint_s
{
	const int n;
	struct listint_s *prev;
	struct listint_s *next;
} listint_t;

/*PRINT FUNCTIONS*/
void print_array(const int *array, size_t size);
void print_list(const listint_t *list);

void bubble_sort(int *array, size_t size);

void insertion_sort_list(listint_t **list);
void swap_nodes(listint_t **h, listint_t **n1, listint_t *n2);

void selection_sort(int *array, size_t size);

void quick_sort(int *array, size_t size);
void quick_swap(int *x, int *y);
void quick_sort_recursion(int *array, int min, int max, size_t size);
int partition(int *array, int min, int max, size_t size);

void shell_sort(int *array, size_t size);
void shell_swap(int *x, int *y);

void cocktail_sort_list(listint_t **list);
void forward_swap(listint_t **list, listint_t *n1, listint_t *n2);
void backward_swap(listint_t **list, listint_t *n1, listint_t *n2);

#endif /*SORT_H*/
