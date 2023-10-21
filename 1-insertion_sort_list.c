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
		previous = current->prev;
		while (previous != NULL && previous->n > current->n)
		{
			/**
			 * setting previous node of current->next to address of previous
			 * because if current->next is null then no need to reconnect nodes well
			 * next set the next part of previous to current->next
			 * because we are rearranging the nodes
			 * next set current->prev to previous->prev
			 * set current next address which will be previous
			 * check if current->prev is not NULL
			 * this check if current is the last node or not if it is:
			 * then set current->prev->next to current else set it to list(head)
			*/
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
		current = current->next;
	}
}
