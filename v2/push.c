#include "monty.h"

/**
 * push_cmd - adds node to stack
 * @stack: pointer to head node;
 * @line_number: line number in the file
 *
 * Return: Nothing
 */

void push_cmd(stack_t **stack, unsigned int line_number)
{
	add_node_begin(stack, line_number);
}

/**
 * pall_cmd - prints stack list
 * @stack: pointer to head node;
 * @line_number: line number in the file
 *
 * Return: Nothing
 */

void pall_cmd(stack_t **stack, unsigned int line_number)
{
	(void)line_number;

	print_list(stack);
}

void pint_cmd(stack_t **stack, unsigned int line_number)
{
	(void)line_number;

	print_head(stack);
}
