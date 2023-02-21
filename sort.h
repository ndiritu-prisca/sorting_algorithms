#ifndef SORT_H
#define SORT_H

#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
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

/*0-bubble_sort.c*/
void bubble_sort(int *array, size_t size);

/*1-insertion_sort_list.c*/
void insertion_sort_list(listint_t **list);
void swap_nodes(listint_t **h, listint_t **n1, listint_t *n2);

/*2-selection_sort.c*/
void selection_sort(int *array, size_t size);

/*3-quick_sort.c*/
void quick_sort(int *array, size_t size);
void quick_swap(int *x, int *y);
void quick_sort_recursion(int *array, int min, int max, size_t size);
int partition(int *array, int min, int max, size_t size);

/*100-shell_sort.c*/
void shell_sort(int *array, size_t size);
void shell_swap(int *x, int *y);

/*101-cocktail_sort_list.c*/
void cocktail_sort_list(listint_t **list);
void forward_swap(listint_t **list, listint_t **node);
void backward_swap(listint_t **list, listint_t **node);

/*102-counting_sort.c*/
void counting_sort(int *array, size_t size);
int find_max(int *array, size_t size);

/*103-merge_sort.c*/
void merge_sort(int *array, size_t size);
void merge_compare(int *array, size_t start, size_t stop, int *new);
void merge_sort_recursive(int *array, size_t start, size_t stop, int *new);
/*104-heap_sort.c*/
void heap_sort(int *array, size_t size);
void heapify(int *array, size_t size, size_t base, size_t i);
void heap_swap(int *x, int *y);

#endif /*SORT_H*/
