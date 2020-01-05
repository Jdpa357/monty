#include "monty.h"
/**
 * commands - Function that executes the commands given by the monty file
 *
 * @stack: Pointer to the stack
 * @op: Operation code
 * @ln: line number
 * Return: No return (Void function)
 */
void commands(stack_t **stack, char *op, unsigned int ln)
{
	int i = 0;
	instruction_t instructs[] = {
		{"pall", exe_pall},
		{"pint", exe_pint},
		{NULL, NULL}
	};
	if (!stack && ln == 400)
		return;
	op = strtok(op, " \n");
	while (instructs[i].opcode)
	{
		if (strcmp(op, "nop") == 0)
			break;
		else if (strcmp(instructs[i].opcode, op) == 0)
		{
			instructs[i].f(stack, ln);
			break;
		}
		i++;
	}

	if (!instructs[i].opcode)
	{
		dprintf(STDERR_FILENO, "L%d: unknown instruction %s\n", ln, op);
		close_program();
		exit(EXIT_FAILURE);
	}
}
