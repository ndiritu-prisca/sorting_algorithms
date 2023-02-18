#include "sort.h"

/**
  * nodes_swap - a function that swaps two nodes in a doubly linked list.
  * @head: A pointer to the head of the doubly-linked list.
  * @node1: A pointer to the first node to swap.
  * @node2: The second node to swap.
  */
void nodes_swap(listint_t **head, listint_t **node1, listint_t *node2)
{
	(*node1)->next = node2->next;
	if (node2->next != NULL)
		node2->next->prev = *node1;
	node2->prev = (*node1)->prev;
	node2->next = *node1;
	if ((*node1)->prev != NULL)
		(*node1)->prev->next = node2;
	else
		*head = node2;
	(*node1)->prev = node2;
	*node1 = node2->prev;
}

/**
  * insertion_sort_list - a function that sorts a doubly linked list of
  * integers in ascending order using the Insertion sort algorithm
  * @list: pointer to head pointer of linked list
  * Return: void
  */
void insertion_sort_list(listint_t **list)
{
	listint_t *iter, *temp1, *temp2;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
	return;

	for (iter = (*list)->next; iter != NULL; iter = temp2)
	{
		temp2 = iter->next;
		temp1 = iter->prev;
		while (temp1 != NULL && iter->n < temp1->n)
		{
			nodes_swap(list, &temp1, iter);
			print_list((const listint_t *)*list);
		}
	}
}
