#include "monty.h"

/**
 * free_list - frees a malloc'ed linked list
 * @head: pointer to the first node
 *
 * Return: Nothing
 */

void free_list(stack_t *head)
{
	stack_t *temp;

	while (head != NULL)
	{
		temp = head;
		head = head->next;
		free(temp);
	}
}
