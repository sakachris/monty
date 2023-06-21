#include "monty.h"

/**
 * check_opcode - checks if opcode is valid
 * @str: opcode to test
 * @n: line number from file
 * @s: pointer to head node
 * @l: lineptr
 * @f: monty file passed
 *
 * Return: valid opcode
 */

char *check_opcode(char *str, unsigned int n, stack_t *s, char *l, FILE *f)
{
	if (get_opcode(str) == NULL)
	{
		fprintf(stderr, "L%d: unknown instruction %s\n", n, str);
		fclose(f);
		free(l);
		free_list(s);
		exit(EXIT_FAILURE);
	}
	(void)n;
	return (str);
}
