#ifndef __MONTY_H__
#define __MONTY_H__
#define _GNU_SOURCE
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <ctype.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/**
 * struct var_s - variables used for stack (or queue)
 * @mfile: monty file
 * @lineptr: lineptr in getline
 * @mode: selects mode for stack or queue
 *
 * Description: variables to use as global
 * for stack, queues, LIFO, FIFO
 */
typedef struct var_s
{
	FILE *mfile;
	char *lineptr;
	int mode;
} var_t;
extern var_t v;

void opcode_path(stack_t **stack, char *cmd, char *arg, unsigned int n);
void (*get_opcode(char *str))(stack_t **, unsigned int);
void push_opcode(stack_t **stack, unsigned int line_number);
void pall_opcode(stack_t **stack, unsigned int line_number);
void pint_opcode(stack_t **stack, unsigned int line_number);
void pop_opcode(stack_t **stack, unsigned int line_number);
void swap_opcode(stack_t **stack, unsigned int line_number);
void add_opcode(stack_t **stack, unsigned int line_number);
void sub_opcode(stack_t **stack, unsigned int line_number);
void div_opcode(stack_t **stack, unsigned int line_number);
void mul_opcode(stack_t **stack, unsigned int line_number);
void mod_opcode(stack_t **stack, unsigned int line_number);
void pchar_opcode(stack_t **stack, unsigned int line_number);
void pstr_opcode(stack_t **stack, unsigned int line_number);
void rotl_opcode(stack_t **stack, unsigned int line_number);
void rotr_opcode(stack_t **stack, unsigned int line_number);
void free_list(stack_t *head);
char *check_opcode(char *str, unsigned int n, stack_t *s);
char *test_int(char *str, unsigned int n, stack_t *h);
void error_msg1(void);
void error_msg2(char **av);
int select_mode(char *str);
#endif /* __MONTY_H__ */
