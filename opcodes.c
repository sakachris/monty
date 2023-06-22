#include "monty.h"

/**
 * add_cmd - adds the top two elements of stack, deletes the top
 * @stack: pointer to head node
 * @line_number: line number from file
 *
 * Return: Nothing
 */

void add_cmd(stack_t **stack, unsigned int line_number)
{
	stack_t *temp, *temp2 = *stack;
	unsigned int n = 0;
	int add;

	while (temp2)
	{
		temp2 = temp2->next;
		n++;
	}
	if (n >= 2)
	{
		temp = *stack;
		*stack = (*stack)->next;
		add = temp->n + (*stack)->n;
		(*stack)->n = add;
		free(temp);
		temp = NULL;
	}
	else
	{
		fprintf(stderr, "L%u: can't add, stack too short\n", line_number);
		fclose(v.mfile);
		free(v.lineptr);
		free_list(*stack);
		exit(EXIT_FAILURE);
	}
}

