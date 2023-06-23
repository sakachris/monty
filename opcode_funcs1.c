#include "monty.h"

/**
 * push_opcode - adds node to stack
 * @stack: pointer to head node;
 * @line_number: line number in the file
 *
 * Return: Nothing
 */

void push_opcode(stack_t **stack, unsigned int line_number)
{
	stack_t *add, *temp;

	add = malloc(sizeof(stack_t));
	if (!add)
	{
		fprintf(stderr, "Error: malloc failed\n");
		fclose(v.mfile);
		free(v.lineptr);
		free_list(*stack);
		exit(EXIT_FAILURE);
	}
	add->n = line_number;

	if (v.mode == 1 || !v.mode)
	{
		add->next = *stack;
		add->prev = NULL;
		if (*stack != NULL)
			(*stack)->prev = add;
		*stack = add;
	}
	else if (v.mode == 2)
	{
		if (*stack == NULL)
		{
			add->prev = NULL;
			add->next = NULL;
			*stack = add;
		}
		else
		{
			temp = *stack;
			while (temp->next != NULL)
				temp = temp->next;
			temp->next = add;
			add->prev = temp;
			add->next = NULL;
		}
	}
}

/**
 * pall_opcode - prints stack list
 * @stack: pointer to head node;
 * @line_number: line number in the file
 *
 * Return: Nothing
 */

void pall_opcode(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = NULL;

	if (stack != NULL)
	{
		temp = *stack;
		while (temp)
		{
			printf("%d\n", temp->n);
			temp = temp->next;
		}
	}

	(void)line_number;
}

/**
 * pint_opcode - prints data at the top of stack
 * @stack: pointer to head node
 * @line_number: line number in the file
 *
 * Return: Nothing
 */

void pint_opcode(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = *stack;

	if (temp != NULL)
		printf("%i\n", temp->n);
	else
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", line_number);
		fclose(v.mfile);
		free(v.lineptr);
		free_list(*stack);
		exit(EXIT_FAILURE);
	}
}

/**
 * pop_opcode - deletes the data at the top of a stack
 * @stack: pointer to head node
 * @line_number: line number in the file
 *
 * Return: Nothing
 */

void pop_opcode(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	if ((stack == NULL) || (*stack == NULL))
	{
		fprintf(stderr, "L%u: can't pop an empty stack\n", line_number);
		fclose(v.mfile);
		free(v.lineptr);
		exit(EXIT_FAILURE);
	}

	if ((*stack)->next != NULL)
	{
		temp = *stack;
		*stack = (*stack)->next;
		(*stack)->prev = NULL;
		free(temp);
		temp = NULL;
	}
	else
	{
		free(*stack);
		*stack = NULL;
	}
}

/**
 * swap_opcode - swap top two elements of a stack
 * @stack: pointer to head node
 * @line_number: line number in the file
 *
 * Return: Nothing
 */

void swap_opcode(stack_t **stack, unsigned int line_number)
{
	stack_t *temp, *temp2 = *stack;
	unsigned int n = 0;

	while (temp2)
	{
		temp2 = temp2->next;
		n++;
	}
	if (n >= 2)
	{
		temp = *stack;
		temp = (*stack)->next;
		(*stack)->next = temp->next;
		temp->prev = NULL;
		if (temp->next != NULL)
			temp->next->prev = *stack;
		temp->next = *stack;
		(*stack)->prev = temp;
		*stack = temp;
		temp = NULL;
	}
	else
	{
		fprintf(stderr, "L%u: can't swap, stack too short\n", line_number);
		fclose(v.mfile);
		free(v.lineptr);
		free_list(*stack);
		exit(EXIT_FAILURE);
	}
}

