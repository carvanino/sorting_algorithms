#include "sort.h"

void swap_node(listint_t **list, listint_t *node, listint_t *previous);


/**
 * insertion_sort_list - A function that sorts
 * a doubly linked list of integers in ascending
 * order using the insertion sort algorithm
 *
 * @list: pointer to the head pointer
 */

void insertion_sort_list(listint_t **list)
{
	listint_t *head = *list, *previous, *node;

	for (node = head; node != NULL; node = node->next)
	{
		while (node->prev != NULL) /*ensure its not the head node*/
		{
			previous = node->prev;
			if (node->n < previous->n)
			{
				swap_node(list, node, previous);
				print_list(*list);
			}
			else
				break;
		}
	}
}


/**
 * swap_node - a function that swaps two node
 * that are side by side, i.e it swaps the node
 * with the node before it
 *
 * @list: pointer to the head pointer of the list
 * @node: the node to be swapped
 * @previous: the previous node
 */

void swap_node(listint_t **list, listint_t *node, listint_t *previous)
{
	listint_t *next_node;

	/**
	 * Make the node before and after the
	 * two nodes point to the correct node
	 * after they've been swapped.
	 * (we are doing this before swapping
	 * to avoid complexity)
	 */
	if (previous->prev != NULL)
		previous->prev->next = node;
	if (node->next != NULL)
		node->next->prev = previous;
	/**
	 * swap the pointers of the two nodes
	 * so they point to the new proper node
	 * in the list, i.e the `next` & `prev` pointer
	 */
	next_node = node->next;
	node->next = previous;
	node->prev = previous->prev;
	previous->next = next_node;
	previous->prev = node;

	/**
	 * if the node was swapped with the head node,
	 * make the node the new head
	 */
	if (node->prev == NULL)
	{
		*list = node;
	}
}
