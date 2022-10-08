#include "sort.h"

/**
 * insertion_sort_list - Sorts a doubly linked list of integers
 * in ascending order using the Insertion sort algorithm
 *
 * @list: Doble pointer to the head of the list
 *
 */

void insertion_sort_list(listint_t **list)
{
	listint_t *transv = NULL, *prevnode = NULL;

	if (*list == NULL)
	{
		return;
	}

	transv = *list;
	prevnode = *list;

	while (transv->next)
	{
		if (transv->n > transv->next->n)
		{
			transv = prevnode->next;
			if (transv->next == NULL)
			{
				transv->prev = prevnode->prev;
				prevnode->prev = transv;
				transv->prev->next = transv;
				prevnode->next = transv->next;
				transv->next = prevnode;
				print_list(*list);
			}

			else{

				transv->prev = prevnode->prev;
				prevnode->next = transv->next;
				transv->next = prevnode;
				prevnode->prev = transv;
				prevnode->next->prev = prevnode;
				if (transv->prev == NULL)
				{
					*list = transv;
					continue;
				}
				transv->prev->next = transv;
				print_list(*list);
			}

			while (transv->prev->n > transv->n)
			{
				prevnode = transv->prev;
				sleep(1);
				if (prevnode->prev == NULL)
				{
					transv->prev = prevnode->prev;
					prevnode->next = transv->next;
					transv->next = prevnode;
					prevnode->prev = transv;
					prevnode->next->prev = prevnode;
					prevnode = prevnode->next->next;
					*list = transv;
					print_list(*list);
					break;
				}
				prevnode->prev->next = transv;
				transv->prev = prevnode->prev;
				prevnode->next = transv->next;
				transv->next = prevnode;
				prevnode->prev = transv;
				prevnode->next->prev = prevnode;
				prevnode = transv->next->next;
				print_list(*list);
			}
		}
		else
		{
			transv = transv->next;
			prevnode = transv;
		}
	}
}
