#include "sort.h"

/**
 * insertion_sort_list- sorts a doubly linked list via insertion sort
 * @list: is the head of the list
 * Return: void
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *ptr = NULL, *tmp = NULL;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	ptr = *list;
	ptr = ptr->next;
	while (ptr)
	{
		while (ptr->prev && ptr->n < (ptr->prev)->n)
		{
			tmp = ptr;
			if (ptr->next)
				(ptr->next)->prev = tmp->prev;
			(ptr->prev)->next = tmp->next;
			ptr = ptr->prev;
			tmp->prev = ptr->prev;
			tmp->next = ptr;
			if (ptr->prev)
				(ptr->prev)->next = tmp;
			ptr->prev = tmp;
			if (tmp->prev == NULL)
				*list = tmp;
			print_list(*list);
			ptr = ptr->prev;
		}
		ptr = ptr->next;
	}

}
