#include "monty.h"

/**
 * add_node_begin - add node at the beginning of a linked list
 * @head: pointer to the first node
 * @n: data to be added
 *
 * Return: address of added node
 */

stack_t *add_node_begin(stack_t **head, const int n)
{
	stack_t *add;

	add = malloc(sizeof(stack_t));
	/*add = NULL;*/
	if (!add)
	{
		fprintf(stderr, "Error: malloc failed\n");
		fclose(v.mfile);
		free(v.lineptr);
		free_list(*head);
		exit(EXIT_FAILURE);
	}

	add->n = n;
	add->next = *head;
	add->prev = NULL;
	if (*head != NULL)
	{
		(*head)->prev = add;
	}
	*head = add;

	return (*head);
}

/**
 * print_list - prints linked list
 * @h: pointer to head node
 *
 * Return: number of nodes
 */

size_t print_list(stack_t **h)
{
	int count = 0;
	stack_t *temp = NULL;

	if (h != NULL)
	{
		temp = *h;
		while (temp)
		{
			printf("%d\n", temp->n);
			temp = temp->next;
			count++;
		}
	}
	return (count);
}

/**
 * print_head - prints the first node of a linked list
 * @h: pointer to head node
 * @line_number: line number from file
 *
 * Return: Nothing
 */

void print_head(stack_t **h, unsigned int line_number)
{
	stack_t *temp = *h;

	if (temp != NULL)
		printf("%i\n", temp->n);
	else
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", line_number);
		fclose(v.mfile);
		free(v.lineptr);
		free_list(*h);
		exit(EXIT_FAILURE);
	}
}