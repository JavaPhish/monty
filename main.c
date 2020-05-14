#include "monty.h"

stack_t *global_stack = NULL;

/**
 * main - runs the monty script
 * @argc: num of arguments
 * @argv: arguments
 *
 * Return: Always 0
 */
int main(int argc, char *argv[])
{
	char *raw_text_buffer;
	char **lexed;


	/* If monty is used with no input file, exit*/
	if (argc == 1)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	/* Read and separate the file into separate lines based on the newline */
	raw_text_buffer = read_file(argv[1]);
	lexed = sep_lines(raw_text_buffer);

	/* Call the driver which uses the tokenized lines to call each function */
	monty_driver(lexed);

	/* Free all mallocs and return :) */
	free_stack(global_stack);
	free2d_str(lexed);
	free(raw_text_buffer);
	return (0);
}
