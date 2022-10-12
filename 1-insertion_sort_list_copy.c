#include "sort.h"

void reverse_sort(listint_t **list, listint_t *node);

/**
 *
 */

void insertion_sort_list(listint_t **list)
{
	int highest;
	listint_t *head = *list, *nextptr, *tmp, *prevptr;

	highest = head->n;
	nextptr = head;
	while (nextptr)
	{
		if (nextptr->n > highest)
			highest = nextptr->n;
		if (nextptr->n < highest)
		{
			prevptr = nextptr->prev;
			tmp = nextptr;
			nextptr = nextptr->next;
			/*reconnectiong the previous location*/
			prevptr->next = nextptr;
			if (nextptr != NULL)
				nextptr->prev = prevptr;
			/*sort the node*/
			reverse_sort(list, tmp);
			print_list(head);
			continue;
		}
		nextptr = nextptr->next;
	}
}


void reverse_sort(listint_t **list, listint_t *node)
{
	listint_t *previous = node, *head = *list;

	while(1)
	{
		previous = previous->prev;
		if (previous == NULL)
		{
			node->next = head;
			head->prev = node;
			*list = node;
			break;
		}
		else if (previous->n < node->n)
		{
			node->next = previous->next;
			node->prev = previous;
			previous->next->prev = node;
			previous->next = node;
			break;
		}
	}
}
