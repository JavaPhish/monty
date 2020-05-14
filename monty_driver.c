#include "monty.h"

/**
 * monty_driver - Runs through all commands and executes them
 * @parsed_lines: THe lines to execute
 *
 * Return: It says void.
 */
void monty_driver(char **parsed_lines)
{
	int line_n;
	char *command, **tok_l, *value = NULL;

	for (line_n = 0; parsed_lines[line_n] != NULL; line_n++)
	{
		tok_l = tokenize_line(parsed_lines[line_n]);

		if (tok_l[0])
			command = tok_l[0];
		else
			command = "nop";
		if (tok_l[1])
			value = tok_l[1];

		if (strcmp(command, "push") == 0)
			push(atoi(value));
		else if (strcmp(command, "pall") == 0)
			pall();
		else if (strcmp(command, "nop") == 0)
			continue;
		else
		{
			fprintf(stderr, "L%d: unknown instruction %s\n", line_n + 1, command);
			exit(EXIT_FAILURE);
		}
	}
	free(command);
	free(value);
	free2d_str(tok_l);
}
