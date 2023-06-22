#include "monty.h"

/**
 * add_opcode - adds the top two elements of stack
 * replaces sum with second top and deletes the top
 * @stack: pointer to head node
 * @line_number: line number from file
 *
 * Return: Nothing
 */

void add_opcode(stack_t **stack, unsigned int line_number)
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

/**
 * sub_opcode - subtractss the top two elements of stack
 * replaces difference with second top and deletes the top
 * @stack: pointer to head node
 * @line_number: line number from file
 *
 * Return: Nothing
 */

void sub_opcode(stack_t **stack, unsigned int line_number)
{
	stack_t *temp, *temp2 = *stack;
	unsigned int n = 0;
	int sub;

	while (temp2)
	{
		temp2 = temp2->next;
		n++;
	}
	if (n >= 2)
	{
		temp = *stack;
		*stack = (*stack)->next;
		sub = (*stack)->n - temp->n;
		(*stack)->n = sub;
		free(temp);
		temp = NULL;
	}
	else
	{
		fprintf(stderr, "L%u: can't sub, stack too short\n", line_number);
		fclose(v.mfile);
		free(v.lineptr);
		free_list(*stack);
		exit(EXIT_FAILURE);
	}
}

/**
 * div_opcode - divides the second top by tope element of stack
 * replaces quotient with second top and deletes the top
 * @stack: pointer to head node
 * @line_number: line number from file
 *
 * Return: Nothing
 */

void div_opcode(stack_t **stack, unsigned int line_number)
{
	stack_t *temp, *temp2 = *stack;
	unsigned int n = 0;
	int div;

	while (temp2)
	{
		temp2 = temp2->next;
		n++;
	}
	if (n >= 2)
	{
		if ((*stack)->n == 0)
		{
			fprintf(stderr, "L%u: division by zero\n", line_number);
			fclose(v.mfile);
			free(v.lineptr);
			free_list(*stack);
			exit(EXIT_FAILURE);
		}
		temp = *stack;
		*stack = (*stack)->next;
		div = (*stack)->n / temp->n;
		(*stack)->n = div;
		free(temp);
		temp = NULL;
	}
	else
	{
		fprintf(stderr, "L%u: can't div, stack too short\n", line_number);
		fclose(v.mfile);
		free(v.lineptr);
		free_list(*stack);
		exit(EXIT_FAILURE);
	}
}

/**
 * mul_opcode - multiplies the second top by tope element of stack
 * replaces product with second top and deletes the top
 * @stack: pointer to head node
 * @line_number: line number from file
 *
 * Return: Nothing
 */

void mul_opcode(stack_t **stack, unsigned int line_number)
{
	stack_t *temp, *temp2 = *stack;
	unsigned int n = 0;
	int mul;

	while (temp2)
	{
		temp2 = temp2->next;
		n++;
	}
	if (n >= 2)
	{
		temp = *stack;
		*stack = (*stack)->next;
		mul = (*stack)->n * temp->n;
		(*stack)->n = mul;
		free(temp);
		temp = NULL;
	}
	else
	{
		fprintf(stderr, "L%u: can't mul, stack too short\n", line_number);
		fclose(v.mfile);
		free(v.lineptr);
		free_list(*stack);
		exit(EXIT_FAILURE);
	}
}

