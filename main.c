#include "monty.h"

/**
 * main - Entry Point
 * @ac: number of arguments
 * @av: arguments passed
 *
 * Return: 0 if success
 */

int main(int ac, char **av)
{
	FILE *mfile;
	char *token, *token2, *cmd, *arg, *lineptr = NULL;
	size_t n = 0;
	ssize_t c_read;
	unsigned int line_number = 1;
	stack_t *stack = NULL;
	const char *delim = " \n";

	if (ac != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	mfile = fopen(av[1], "r");
	if (!mfile)
	{
		fprintf(stderr, "Error: Can't open file %s\n", av[1]);
		exit(EXIT_FAILURE);
	}

	while ((c_read = getline(&lineptr, &n, mfile)) != -1)
	{
		token = strtok(lineptr, delim);
		cmd = check_opcode(token, line_number, stack, lineptr, mfile);
		if (strcmp(cmd, "push") == 0)
			token2 = strtok(NULL, delim);
		arg = test_int(token2, line_number, stack, lineptr, mfile);
		opcode_path(&stack, cmd, arg, line_number);
		line_number++;
	}

	fclose(mfile);
	if (lineptr)
		free(lineptr);
	free_list(stack);
	return (0);
}
