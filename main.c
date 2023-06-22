#include "monty.h"

char *check_opcode(char *str, unsigned int n, stack_t *s);
var_t v;

/**
 * main - Entry Point
 * @ac: number of arguments
 * @av: arguments passed
 *
 * Return: 0 if success
 */

int main(int ac, char **av)
{
	char *token, *token2, *cmd, *arg;
	size_t n = 0;
	ssize_t c_read;
	unsigned int line_number = 1;
	int num;
	stack_t *stack = NULL;
	const char *delim = " \n";
	void (*f)(stack_t **stack, unsigned int line_number);

	if (ac != 2)
		error_msg1();
	v.mfile = fopen(av[1], "r");
	if (!v.mfile)
		error_msg2(av);
	v.lineptr = NULL;
	while ((c_read = getline(&v.lineptr, &n, v.mfile)) != -1)
	{
		token = strtok(v.lineptr, delim);
		if (token == NULL)
			continue;
		cmd = check_opcode(token, line_number, stack);
		f = get_opcode(cmd);
		if (strcmp(cmd, "push") == 0)
		{
			token2 = strtok(NULL, delim);
			arg = test_int(token2, line_number, stack);
			num = atoi(arg);
			f(&stack, num);
		}
		else
			f(&stack, line_number);
		line_number++;
	}

	fclose(v.mfile);
	if (v.lineptr)
		free(v.lineptr);
	free_list(stack);
	return (0);
}


/**
 * check_opcode - checks if opcode is valid
 * @str: opcode to test
 * @n: line number from file
 * @s: pointer to head node
 *
 * Return: valid opcode
 */

char *check_opcode(char *str, unsigned int n, stack_t *s)
{
	if (get_opcode(str) == NULL)
	{
		fprintf(stderr, "L%u: unknown instruction %s\n", n, str);
		fclose(v.mfile);
		free(v.lineptr);
		free_list(s);
		exit(EXIT_FAILURE);
	}
	(void)n;
	return (str);
}