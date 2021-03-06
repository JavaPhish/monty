#include "monty.h"

/**
 * monty_driver - Main exeuction handler
 * @parsed_line: The line to executre
 *
 * Return: 1 on success or 0 depending on error code
 */
int monty_driver(char *parsed_line)
{
	char **token_line, *command, *value, *copy = malloc(sizeof(parsed_line));
	int status = 1;

	if (!copy)
		return (100);
	copy = strcpy(copy, parsed_line);
	token_line = tokenize_line(copy);

	command = token_line[0];

	if (token_line[1])
		value = token_line[1];

	status = call_function(command, value);


	free(token_line);
	free(copy);

	return (status);
}

/**
 * call_function - Calls the proper function
 * @opcode: the opcode called
 * @value: its value (if any)
 *
 * Return: The status returned
 */
int call_function(char *opcode, char *value)
{
	int status = 1;

	if (strcmp(opcode, "push") == 0)
		status = push(value);
	else if (strcmp(opcode, "pall") == 0 || strcmp(opcode, "pall\n") == 0)
		pall();
	else if (strcmp(opcode, "nop") == 0 || strcmp(opcode, "nop\n") == 0)
		status = (1);
	else if (strcmp(opcode, "pint") == 0 || strcmp(opcode, "pint\n") == 0)
		status = pint();
	else if (strcmp(opcode, "pop") == 0 || strcmp(opcode, "pop\n") == 0)
		status = pop();
	else if (strcmp(opcode, "swap") == 0 || strcmp(opcode, "swap\n") == 0)
		status = swap();
	else if (strcmp(opcode, "add") == 0 || strcmp(opcode, "add\n") == 0)
		status = add();
	else if ((strcmp(opcode, "sub") == 0 || strcmp(opcode, "sub\n") == 0))
		status = sub();
	else if ((strcmp(opcode, "div") == 0 || strcmp(opcode, "div\n") == 0))
		status = op_div();
	else if ((strcmp(opcode, "mul") == 0 || strcmp(opcode, "mul\n") == 0))
		status = mul();
	else if ((strcmp(opcode, "mod") == 0 || strcmp(opcode, "mod\n") == 0))
		status = mod();
	else if ((strcmp(opcode, "pchar") == 0 || strcmp(opcode, "pchar\n") == 0))
		status = pchar();
	else if ((strcmp(opcode, "pstr") == 0 || strcmp(opcode, "pstr\n") == 0))
		pstr();
	else
		status = 0;

	return (status);
}


/**
 * error_handler - Using the status value, it determines the error message
 * @status: The error to display
 * @line_n: The line the error occured at (Might be ignored)
 * @line: The line GUILTY
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
	else if (status == 14)
		fprintf(stderr, "L%d: can't pchar, stack empty\n", line_n);
	else if (status == 13)
		fprintf(stderr, "L%d: can't pchar, value out of range\n", line_n);
	else if (status == 11)
		fprintf(stderr, "L%d: can't mod, stack too short\n", line_n);
	else if (status == 12)
		fprintf(stderr, "L%d: division by zero\n", line_n);
	else if (status == 10)
		fprintf(stderr, "L%d: can't mul, stack too short\n", line_n);
	else if (status == 9)
		fprintf(stderr, "L%d: division by zero\n", line_n);
	else if (status == 8)
		fprintf(stderr, "L%d: can't div, stack too short\n", line_n);
	else if (status == 7)
		fprintf(stderr, "L%d: can't sub, stack too short\n", line_n);
	else if (status == 6)
		fprintf(stderr, "L%d: can't add, stack too short\n", line_n);
	else if (status == 5)
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_n);
	else if (status == 4)
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_n);
	else if (status == 2)
		fprintf(stderr, "L%d: usage: push integer\n", line_n);
	else if (status == 100)
		fprintf(stderr, "Error: malloc failed\n");
	else if (status == 3)
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_n);
}
