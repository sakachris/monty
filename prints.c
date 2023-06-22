#include "monty.h"

/**
 * pchar_opcode - prints the char at the top of the stack
 * @stack: pointer to head node;
 * @line_number: line number in the file
 *
 * Return: Nothing
 */

void pchar_opcode(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL)
	{
		fprintf(stderr, "L%u: can't pchar, stack empty\n", line_number);
		fclose(v.mfile);
		free(v.lineptr);
		/* free_list(*stack); */
		exit(EXIT_FAILURE);
	}
	
	if ((*stack)->n >= 0 && (*stack)->n <= 127)
	{
		printf("%c\n", (*stack)->n);
	}
	else
	{
		fprintf(stderr, "L%u: can't pchar, value out of range\n", line_number);
		fclose(v.mfile);
		free(v.lineptr);
		free_list(*stack);
		exit(EXIT_FAILURE);
	}
}

/**
 * pstr_opcode - prints the string starting at the top of the stack
 * @stack: pointer to head node;
 * @line_number: line number in the file
 *
 * Return: Nothing
 */

void pstr_opcode(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = *stack;

	/*if (*stack == NULL)
		printf("\n");*/
	
	while (temp != NULL)
	{
		if (temp->n <= 0 || temp->n > 127)
			break;
		printf("%c", temp->n);
		temp = temp->next;
	}
	printf("\n");

	(void)line_number;
}
