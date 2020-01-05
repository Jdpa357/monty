#include "holberton.h"

/**
 * nofile_error - Function that prints an error in case of less than two
 * arguments passed to the main program
 *
 * Description: Execute in case of the user not passing a file name or more
 * than one valid argument to the interpreter
 * Return: Void function (No return)
 */

void nofile_error(void)
{
	fprintf(stderr, "USAGE: monty file\n");
	exit(EXIT_FAILURE);
}
