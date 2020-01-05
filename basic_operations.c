#include "monty.h"

/**
 * exe_push - Function to insert a new node in the stack
 *
 * @stack: Pointer to stack
 * @value: Value that will be inserted in the new node of the stack
 * Return: A pointer to new node
 */
stack_t *exe_push(stack_t **stack, int value)
{
	stack_t *new, *tail = *stack;

	new = malloc(sizeof(stack_t));
	if (!new)
	{
		dprintf(STDERR_FILENO, "Error: malloc failed");
		close_program();
		exit(EXIT_FAILURE);
	}
	new->n = value;
	if (!tail)
	{
		new->prev = NULL;
		new->next = NULL;
		*stack = new;
	}
	else
	{
		while (tail->next)
			tail = tail->next;
		new->prev = tail;
		new->next = NULL;
		tail->next = new;
	}
	return (new);
}

/**
 * exe_pall - Print all the stack values
 *
 * @stack: Pointer to the stack
 * @ln: Line number
 * Return: No return (Void function)
 */
void exe_pall(stack_t **stack, unsigned int ln)
{
	stack_t *tmp = *stack;

	if (!tmp)
		return;
	if (tmp)
	{
		while (tmp->next)
			tmp = tmp->next;
		while (tmp->prev)
		{
			dprintf(STDOUT_FILENO, "%d\n", tmp->n);
			tmp = tmp->prev;
		}
	}
	dprintf(STDOUT_FILENO, "%d\n", tmp->n);
	if (ln > 1)
		return;
}
