#include "monty.h"

/**
 * liberation - Function in charge of freeing the stack
 *
 * @stack: Pointer to the stack to free
 * Return: Void function (No return)
 */

void liberation(stack_t **stack)
{

	stack_t *tail = *stack;

	if (!tail)
		return;
	while (tail->next)
		tail = tail->next;
	while (tail->prev)
	{
		tail = tail->prev;
		free(tail->next);
		tail->next = NULL;
	}
	free(tail);
	*stack = NULL;

}
