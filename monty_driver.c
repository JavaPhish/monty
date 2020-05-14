#include "monty.h"

/**
 * monty_driver - Main exeuction handler
 * @parsed_line: The line to executre
 *
 * Return: 1 on success or 0 depending on error code
 */
int monty_driver(char *parsed_line)
{
	char **token_line;
	char *command, *value = NULL, *copy;
	int status = 1;

	copy = malloc(sizeof(parsed_line));
	if (!copy)
		return (100);
	copy = strcpy(copy, parsed_line);
	token_line = tokenize_line(copy);
	command = token_line[0];
	if (token_line[1])
		value = token_line[1];

	if (strcmp(command, "push") == 0)
		status = push(value);
	else if (strcmp(command, "pall") == 0 || strcmp(command, "pall\n") == 0)
		pall();
	else if (strcmp(command, "nop") == 0 || strcmp(command, "nop\n") == 0)
		status = (1);
	else if (strcmp(command, "pint") == 0 || strcmp(command, "pint\n") == 0)
		status = pint();
	else
	{
		status = 0;
	}

	free(command);
	if (value)
		free(value);

	return (status);
}

/**
 * error_handler - Using the status value, it determines the error message
 * @status: The error to display
 * @line_n: The line the error occured at (Might be ignored)
 *
 * Return: None
 */
void error_handler(int status, int line_n, char *line)
{
	char *opcode;

	if (status == 0)
	{
		opcode = tokenize_line(line)[0];
		fprintf(stderr, "L%d: unknown instruction %s\n", line_n, opcode);
	}

	else if (status == 2)
		fprintf(stderr, "L%d: usage: push integer\n", line_n);
	else if (status == 100)
		fprintf(stderr, "Error: malloc failed\n");
	else if (status == 3)
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_n);
}
