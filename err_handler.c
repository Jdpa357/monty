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

/**
 * openfile_error - Function in charge of printing an error in case it is not
 * possible to open a file
 *
 * Description: If for any reason, it's not possible to open the file, print
 * an error message to the standard output with the file name that failed to
 * open attached to it
 * Return: Void function (No return)
 */

void openfile_error(char **argv)
{
	char *name = argv[1];

	fprintf(stderr, "Error: Can't open file %s\n", name);
	exit(EXIT_FAILURE);
}

/**
 * instruction_error - Function that prints an error in case of a invalid
 * instruction passed to the program
 *
 * Description: If the file contains an invalid instruction, prints an error
 * message to the standard output with the line number and the instruction
 * attached to it
 * Return: No return (Void function)
 */

void instruction_error(char *invalidOp, unsigned int lineNum)
{
	fprintf(stderr, "L%u: unknown instruction %s\n", lineNum, invalidOp);
	exit(EXIT_FAILURE);
}
