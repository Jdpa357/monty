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

/**
 * exe_pint - Function that prints the value at the top of the stack
 *
 * @stack: Pointer to stack
 * @ln: Line number
 * Return: No return (Void function)
 */
void exe_pint(stack_t **stack, unsigned int ln)
{
	stack_t *tail = *stack;

	if (!tail)
	{
		dprintf(STDERR_FILENO, "L%d: can't pint, stack empty\n", ln);
		close_program();
		exit(EXIT_FAILURE);
	}
	else
	{
		while (tail->next)
			tail = tail->next;
		dprintf(STDOUT_FILENO, "%d\n", tail->n);
	}
}

/**
 * exe_pop - Function that removes the top element of the stack
 *
 * @stack: Pointer to stack
 * @ln: line number
 * Return: No return (Void function)
 */
void exe_pop(stack_t **stack, unsigned int ln)
{
	stack_t *tail = *stack;

	if (!tail)
	{
		dprintf(STDERR_FILENO, "L%d: can't pop an empty stack\n", ln);
		close_program();
		exit(EXIT_FAILURE);
	}
	else
	{
		while (tail->next)
			tail = tail->next;
		if (!tail->prev)
		{
			free(tail);
			*stack = NULL;
		}
		else
		{
			tail = tail->prev;
			free(tail->next);
			tail->next = NULL;
		}
	}
}

/**
 * exe_swap - Function that swaps the top two elements
 *
 * @stack: Pointer to stack
 * @ln: Line number
 * Return: No return (Void function)
 */
void exe_swap(stack_t **stack, unsigned int ln)
{
	stack_t *tail = *stack;
	int tmp;

	if (!tail || !tail->next)
	{
		dprintf(STDERR_FILENO, "L%d: can't swap, stack too short\n", ln);
		close_program();
		exit(EXIT_FAILURE);
	}
	else
	{
		while (tail->next)
			tail = tail->next;
		tmp = tail->n;
		tail->n = tail->prev->n;
		tail->prev->n = tmp;
	}
}
