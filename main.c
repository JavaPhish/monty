#include "monty.h"

stack_t *global_stack = NULL;
char *opcode = NULL;

/**
 * main - runs the monty script
 * @argc: num of arguments
 * @argv: arguments
 *
 * Return: Always 0
 */
int main(int argc, char *argv[])
{
	char raw_text_buffer[256];
	FILE *file_desc;
	int line_n = 0, status = 1;

	/* If monty is used with no input file, exit*/
	if (argc == 1)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	/* Check if the file exists and open it if it does */
	file_desc = fopen(argv[1], "r");
	if (file_desc == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	/* Loop through each line and execute it individually */
	while (fgets(raw_text_buffer, sizeof(raw_text_buffer), file_desc))
	{
		line_n++;
		if (is_all_whtspc(raw_text_buffer) == 0)
		{
			status = monty_driver(raw_text_buffer);
			if (status != 1)
				break;
		}
	}


	if (status != 1)
	{
		error_handler(status, line_n);
		exit(EXIT_FAILURE);
	}

	return (0);
}
