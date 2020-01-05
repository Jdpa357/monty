#include "monty.h"

/**
 * main - Main function for the monty interpreter.
 *
 * Description: Monty bytecodes files interpreter, function in charge of
 * executing other functions to carry on with execution processes
 * @argc: Argument counter
 - @argv: Argument vector
 * Return: Always 0 (Success)
 */

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		nofile_error();
	}
	else
		open_read(argv[1]);
	return (0);
}
