#include "monty.h"

/**
 * tokenize_line - Converts a line into a 2d array with each argument sep
 * @line: THe line to tokenize
 *
 * Return: The 2d array of arguments/tokens
 */
char **tokenize_line(char *line)
{
	char *token = NULL, *tok_origin = NULL, **simple = NULL, *copy;
	int tok_count = 0, cmd_iter = 0;

	if (!line)
		return (simple);
	/* Find out how many seperate words/tokens exist for malloc */
	tok_origin = token;
	copy = malloc(strlen(line) * sizeof(char));
	strcpy(copy, line);
	token = strtok(copy, " ");
	while (token != NULL)
	{
		tok_count++;
		token = strtok(NULL, " ");
	}
	free(tok_origin);
	free(copy);

	simple = malloc(sizeof(char *) * tok_count);
	/* Tokenize by " " and insert it into its own slot */
	tok_origin = token;
	token = strtok(line, " ");
	while (token != NULL)
	{
		simple[cmd_iter] = malloc(strlen(token) * sizeof(char));
		strcpy(simple[cmd_iter], token);
		cmd_iter++;
		token = strtok(NULL, " ");
	}
	free(tok_origin);
	return (simple);
}
