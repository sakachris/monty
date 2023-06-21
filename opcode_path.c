#include "monty.h"

/**
 * opcode_path - determines how opcode should be handled
 * @stack: pointer to head node
 * @cmd: opcode
 * @arg: opcode argument
 * @n: line number from file
 *
 * Return: Nothing
 */

void opcode_path(stack_t **stack, char *cmd, char *arg, unsigned int n)
{
	void (*f)(stack_t **stack, unsigned int line_number);
	unsigned int num = atoi(arg);

	(void)n;

	f = get_opcode(cmd);

	f(stack, num);
}
