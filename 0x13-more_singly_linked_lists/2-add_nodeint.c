#include "lists.h"

/**
 * add_nodeint - Add a new node at the beginning of a linked list
 * @head: A pointer to the first node in the list
 * @n: The data to insert into the new node
 *
 * Return: A pointer to the new node, or NULL if it fails
 */
listint_t *add_nodeint(listint_t **head, const int n)
{
	listint_t *new_node = malloc(sizeof(listint_t));

	if (new_node == NULL)
		return (NULL);

	new_node->n = n;
	new_node->next = *head;
	*head = new_node;

	return (new_node);
}

