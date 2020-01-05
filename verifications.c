#include "holberton.h"

/**
 * verify - Function to verify if a string is an integer
 *
 * @str: String to process
 * @ln: Line number
 * Return: The integer if success or print an error if otherwise
 */

int verify(char *str, unsigned int ln)
{
	if (!str)
	{
		dprintf(STDERR_FILENO, "L%d: usage: push integer\n", ln);
		close_program();
		exit(EXIT_FAILURE);
	}
	else
	{
		return (isnum(str, ln));
	}
	return (0);
}

/**
 * isnum - Function to verify if a string is a number
 *
 * @str: String to process
 * @ln: Line number
 * Return: The string processed as an integer or print an error if otherwise
 */

int isnum(char *str, unsigned int ln)
{
	int i = 0, error = 0;

	if (!str)
		error = 1;

	if (str[i] == '-' || isdigit(str[i]))
		i++;
	while (str[i])
	{
		if (!isdigit(str[i++]))
		{
			error = 1;
			break;
		}
	}

	if (error)
	{
		dprintf(STDERR_FILENO, "L%d: usage: push integer\n", ln);
		close_program();
		exit(EXIT_FAILURE);
	}
	return (atoi(str));
}
