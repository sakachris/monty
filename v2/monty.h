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

void opcode_path(stack_t **stack, char *cmd, char *arg, unsigned int n);
void (*get_opcode(char *str))(stack_t **, unsigned int);
void push_cmd(stack_t **stack, unsigned int line_number);
void pall_cmd(stack_t **stack, unsigned int line_number);
stack_t *add_node_begin(stack_t **head, const int n);
size_t print_list(stack_t **h);
void free_list(stack_t *head);
char *check_opcode(char *str, unsigned int n, stack_t *s, char *l, FILE *f);
char *test_int(char *str, unsigned int n, stack_t *h, char *l, FILE *f);
void error_msg1(void);
void error_msg2(char **av);
void pint_cmd(stack_t **stack, unsigned int line_number);
void print_head(stack_t **h);
#endif /* __MONTY_H__ */
