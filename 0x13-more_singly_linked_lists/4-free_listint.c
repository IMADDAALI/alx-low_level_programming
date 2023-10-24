#include "lists.h"

/**
 * free_listint - Frees a linked list
 * @head: A pointer to the head of the list
 *
 * Description: Frees a listint_t linked list.
 */
void free_listint(listint_t *head)
{
	listint_t *temp;

	while (head != NULL)
	{
		temp = head->next;
		free(head);
		head = temp;
	}
}

