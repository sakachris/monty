#include "monty.h"

/**
 * error_msg1 - prints error message
 *
 * Return: Nothing
 */

void error_msg1(void)
{
	fprintf(stderr, "USAGE: monty file\n");
	exit(EXIT_FAILURE);
}

/**
 * error_msg2 - prints error message
 * @av: arguments passed
 *
 * Return: Nothing
 */

void error_msg2(char **av)
{
	fprintf(stderr, "Error: Can't open file %s\n", av[1]);
	exit(EXIT_FAILURE);
}
