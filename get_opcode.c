#include "monty.h"

/**
 * get_opcode - matches opcode to corresponding function
 * @str: opcode to match
 *
 * Return: matched function
 */

void (*get_opcode(char *str))(stack_t **, unsigned int)
{
	instruction_t op[] = {
		{"push", push_cmd},
		{"pall", pall_cmd},
		{"pint", pint_cmd},
		{"pop", pop_cmd},
		{NULL, NULL}
	};

	int i = 0;

	while (i < 4)
	{
		if (strcmp(op[i].opcode, str) == 0)
			return (op[i].f);
		i++;
	}

	return (NULL);
}
