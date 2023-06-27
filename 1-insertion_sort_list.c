#include "sort.h"

/**
 * insertion_sort_list- sorts a doubly linked list via insertion sort
 * @list: is the head of the list
 * Return: void
 */

void insertion_sort_list(listint_t **list)
{
	listint_t *ptr, *curr, *prev;

	if (!list || !(*list))
		return;

	ptr = *list;

	while (ptr)
	{
		curr = ptr;

		while (ptr->prev)
		{
			if (ptr->n < ptr->prev->n)
			{
				prev = ptr->prev;
				prev->next = ptr->next;
				ptr->next = prev;
				ptr->prev = prev->prev;
				prev->prev = ptr;
				print_list(*list);
			}
			else
			{
				break;
			}
		}
		ptr = curr->next;
	}
}
