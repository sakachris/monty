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
	unsigned int num, line_number = 1;
	stack_t *stack = NULL;
	const char *delim = " \n";
	void (*f)(stack_t **stack, unsigned int line_number);

	if (ac != 2)
		error_msg1();
	mfile = fopen(av[1], "r");
	if (!mfile)
		error_msg2(av);

	while ((c_read = getline(&lineptr, &n, mfile)) != -1)
	{
		token = strtok(lineptr, delim);
		cmd = check_opcode(token, line_number, stack, lineptr, mfile);
		f = get_opcode(cmd);
		if (strcmp(cmd, "push") == 0)
		{
			token2 = strtok(NULL, delim);
			arg = test_int(token2, line_number, stack, lineptr, mfile);
			num = atoi(arg);
			f(&stack, num);
		}
		else
			f(&stack, line_number);
		/*opcode_path(&stack, cmd, arg, line_number);*/
		line_number++;
	}

	fclose(mfile);
	if (lineptr)
		free(lineptr);
	free_list(stack);
	return (0);
}
