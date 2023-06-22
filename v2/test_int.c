#include "monty.h"

/**
 * test_int - tests whether the argument passed to push is an integer
 * @str: argument to push
 * @n: line number
 * @h: pointer to head node
 * @l: lineptr
 * @f: file passed
 *
 * Return: string if integer
 */

char *test_int(char *str, unsigned int n, stack_t *h, char *l, FILE *f)
{
	int i;

	if (str == NULL)
	{
		fprintf(stderr, "L%d: usage: push integer\n", n);
		fclose(f);
		free(l);
		free_list(h);
		exit(EXIT_FAILURE);
	}
	for (i = 0; str[i] != '\0'; i++)
	{
		if (str[0] == '-')
			continue;
		if (isdigit(str[i]) == 0)
		{
			fprintf(stderr, "L%d: usage: push integer\n", n);
			fclose(f);
			free(l);
			free_list(h);
			exit(EXIT_FAILURE);
		}
	}
	return (str);
}
