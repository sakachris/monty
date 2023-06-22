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
		{"push", push_opcode},
		{"pall", pall_opcode},
		{"pint", pint_opcode},
		{"pop", pop_opcode},
		{"swap", swap_opcode},
		{"add", add_opcode},
		{"sub", sub_opcode},
		{"div", div_opcode},
		{"mul", mul_opcode},
		{"mod", mod_opcode},
		{"pchar", pchar_opcode},
		{"pstr", pstr_opcode},
		{NULL, NULL}
	};

	int i = 0;

	while (op[i].opcode != NULL)
	{
		if (strcmp(op[i].opcode, str) == 0)
			return (op[i].f);
		i++;
	}

	return (NULL);
}
