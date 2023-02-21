#include "sort.h"

/**
  * forward_swap - a function that moves a larger value further to the right
  * @list: pointer to the head of a doubly linked list
  * @n1: node 1
  * @n2: node 2
  * Return: nothing
  */
void forward_swap(listint_t **list, listint_t *n1, listint_t *n2) 
{
	listint_t *temp = n2->next;

	if (n2->prev != NULL)
		n2->prev->next = temp;
	else
		*list = temp;
	temp->prev = n2->prev;
	n2->next = temp->next;
	if (temp->next != NULL)
		temp->next->prev = n2;
	else
		n1 = n2;
	n2->prev = temp;
	temp->next = n2;
	n2 = temp;
}

/**
  * backward_swap - a function that moves a smaller value further to the left
  * @list: pointer to the head of a doubly linked list
  * @n1: node 1
  * @n2: node 2
  * Return: nothing
  */
void backward_swap(listint_t **list, listint_t *n1, listint_t *n2) 
{
	listint_t *temp = n2->prev;

	if (n2->prev != NULL)
		n2->next->prev = temp;
	else
		n1 = temp;
	temp->next = n2->next;
	n2->prev = temp->prev;
	if (temp->prev != NULL)
		temp->prev->next = n2;
	else
		*list = n2;
	n2->next = temp;
	temp->prev = n2;
	n2 = temp;
}

/**
  * cocktail_sort_list - a function that sorts a doubly linked list of integers
  * in ascending order using the Cocktail shaker sort algorithm
  * @list: pointer to the head of a doubly linked list
  * Return: nothing
  */
void cocktail_sort_list(listint_t **list)
{
	size_t k = 0;
	listint_t *next_p, *prev_p;
	listint_t *iter;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;
	for (iter = *list; iter != NULL ; iter = iter->next)
		;
	while(k == 0)
	{
		k = 1;
		prev_p = iter->prev;
		for (next_p = *list; next_p != iter; next_p = next_p->next)
		{
			if (next_p->n > next_p->next->n)
			{
				forward_swap(list, iter, next_p);
				print_list((const listint_t *)*list);
				k = 0;
			}
		}
		for (prev_p = next_p->prev; prev_p != *list;)
			prev_p = prev_p->prev;
		{
			if (prev_p->n < prev_p->prev->n)
			{
				backward_swap(list, iter, prev_p);
				print_list((const listint_t *)*list);
				k = 0;
			}
		}
	}
}
