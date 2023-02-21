#include "sort.h"

/**
  * forward_swap - a function that moves a larger value further to the right
  * @list: pointer to the head of a doubly linked list
  * @node: node to swap forward
  * Return: nothing
  */
void forward_swap(listint_t **list, listint_t **node) 
{
	listint_t *temp = (*node)->next;

	if ((*node)->prev != NULL)
		(*node)->prev->next = temp;
	else
		*list = temp;
	temp->prev = (*node)->prev;
	(*node)->next = temp->next;
	if (temp->next != NULL)
		temp->next->prev = *node;
	(*node)->prev = temp;
	temp->next = *node;
	*node = temp;
}

/**
  * backward_swap - a function that moves a smaller value further to the left
  * @list: pointer to the head of a doubly linked list
  * @node: node to be swapped backward
  * Return: nothing
  */
void backward_swap(listint_t **list, listint_t **node) 
{
	listint_t *temp = (*node)->prev;

	if ((*node)->prev != NULL)
		(*node)->next->prev = temp;
	temp->next = (*node)->next;
	(*node)->prev = temp->prev;
	if (temp->prev != NULL)
		temp->prev->next = *node;
	else
		*list = *node;
	(*node)->next = temp;
	temp->prev = *node;
	*node = temp;
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
				forward_swap(list, &next_p);
				print_list((const listint_t *)*list);
				k = 0;
			}
		}
		for (prev_p = next_p->prev; prev_p != *list;)
			prev_p = prev_p->prev;
		{
			if (prev_p->n < prev_p->prev->n)
			{
				backward_swap(list, &prev_p);
				print_list((const listint_t *)*list);
				k = 0;
			}
		}
	}
}
