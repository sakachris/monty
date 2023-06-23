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
		{"rotl", rotl_opcode},
		{"rotr", rotr_opcode},
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

/**
 * test_int - tests whether the argument passed to push is an integer
 * @str: argument to push
 * @n: line number
 * @h: pointer to head node
 *
 * Return: string if integer
 */

char *test_int(char *str, unsigned int n, stack_t *h)
{
	int i;

	if (str == NULL)
	{
		fprintf(stderr, "L%u: usage: push integer\n", n);
		fclose(v.mfile);
		free(v.lineptr);
		free_list(h);
		exit(EXIT_FAILURE);
	}
	for (i = 0; str[i] != '\0'; i++)
	{
		if (str[0] == '-')
			continue;
		if (isdigit(str[i]) == 0)
		{
			fprintf(stderr, "L%u: usage: push integer\n", n);
			fclose(v.mfile);
			free(v.lineptr);
			free_list(h);
			exit(EXIT_FAILURE);
		}
	}
	return (str);
}

/**
 * free_list - frees a malloc'ed linked list
 * @head: pointer to the first node
 *
 * Return: Nothing
 */

void free_list(stack_t *head)
{
	stack_t *temp;

	while (head != NULL)
	{
		temp = head;
		head = head->next;
		free(temp);
	}
}
