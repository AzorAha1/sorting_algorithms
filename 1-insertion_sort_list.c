#include "sort.h"

/**
* insertion_sort_list - function name
* @list: list to be sorted
* Description - this sorts doubly linked list of int in ascending order
*/
void insertion_sort_list(listint_t **list)
{
	listint_t *current, *previous;

	if (!list || !(*list) || !(*list)->next)
		return;
	current = (*list)->next;
	while (current != NULL)
	{
		while (previous != NULL && previous->n > current->n)
		{
			if (current->next)
				current->next->prev = previous;
			previous->next = current->next;
			current->prev = previous->prev;
			previous->prev = current;
			current->next = previous;
			if (current->prev != NULL)
			{
				current->prev->next = current;
			}
			else
			{
				*list = current;
			}
			print_list(*list);
			previous = current->prev;
		};
		previous = current->prev;
		current = current->next;
	}
}
