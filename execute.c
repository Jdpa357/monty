#include "monty.h"

/**
 * open_read - Function in charge of opening and rading the given file
 *
 * @file: Name of the file to open and read
 * Return: Void function (No return)
 */

void open_read(char *file)
{

	ssize_t reader;
	ssize_t len = 0;
	char *op = NULL, *argVal = NULL;
	int value;
	unsigned int line = 1;

	to_liberate.mf = fopen(file, "r");
	if (!to_liberate.mf)
	{
		dprintf(STDERR_FILENO, "Error: Can't open file %s\n", file);
		exit(EXIT_FAILURE);
	}
	else
	{
		r = getline(&to_liberate.line, &len, to_free.mf);
		while (r != -1)
		{
			op = strtok(to_liberate.line, " \n");
			if (op)
			{
				if (strcmp(op, "push") == 0)
				{
					strval = strtok(NULL, " \n");
					value = verify(strval, ln);
					exe_push(&to_liberate.head, value);
				}
				else if (op[0] != '#')
					monty_commands(&to_liberate.head, op, ln);
			}
			ln++;
			r = getline(&to_liberate.line, &len, to_liberate.mf);
		}
	}
	close_program();
}
