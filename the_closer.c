#include "monty.h"
/**
 * close_program - free all the elements in the buffer
 * Return: void
 */
void close_program(void)
{
	if (to_liberate.head)
	{
		liberation(&to_liberate.head);
	}
	if (to_liberate.line)
		free(to_liberate.line);
	fclose(to_liberate.mf);
}
