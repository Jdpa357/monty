#ifndef _MONTY_H_
#define _MONTY_H_

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <errno.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <ctype.h>

extern int data;

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO Holberton project
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
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/**
 * struct buff - Structure for buffed to free the stack
 *
 * @mf: File
 * @head: Pointer to the head of the stack
 * @line: Line number
 */

typedef struct buff
{
	FILE *mf;
	stack_t *head;
	char *line;
} buffers;

extern buffers to_liberate;
void close_program(void);

/** Operations */
void open_read(char *file);
stack_t *exe_push(stack_t **stack, int value);
void exe_pall(stack_t **stack, unsigned int ln);
void exe_pint(stack_t **stack, unsigned int ln);
void exe_pop(stack_t **stack, unsigned int ln);
void exe_swap(stack_t **stack, unsigned int ln);
void exe_add(stack_t **stack, unsigned int ln);
void exe_nop(stack_t **stack, unsigned int ln);
void nofile_error(void);
void instruction_error(char *invalidOp, unsigned int lineNum);
void liberation(stack_t **stack);
int verify(char *str, unsigned int ln);
int isnum(char *str, unsigned int ln);
void commands(stack_t **stack, char *op, unsigned int ln);

#endif
