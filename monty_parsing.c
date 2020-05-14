#include "monty.h"

/**
 * read_file - Reads and outputs the contents of a file
 * @filename: The file to read
 *
 * Return: The files contents
 */
char *read_file(char *filename)
{
	int file_stat, char_count;
	char *raw_text_buffer;
	struct stat st;

	file_stat = open(filename, O_RDONLY);

	/* if file failed to open, exit*/
	if (file_stat == -1)
	{
		fprintf(stderr, "Error: Can't open file %s\n", filename);
		exit(EXIT_FAILURE);
	}
	/* Get the file size and character count. Needed for read */
	stat(filename, &st);
	char_count = st.st_size;
	raw_text_buffer = malloc(char_count);
	read(file_stat, raw_text_buffer, char_count);

	return (raw_text_buffer);
}

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
	copy = malloc(sizeof(line));
	verify_malloc(copy);
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
	verify_malloc(simple);

	/* Tokenize by " " and insert it into its own slot */
	tok_origin = token;
	token = strtok(line, " ");
	while (token != NULL)
	{
		simple[cmd_iter] = malloc(sizeof(token));
		verify_malloc(simple[cmd_iter]);
		strcpy(simple[cmd_iter], token);
		cmd_iter++;
		token = strtok(NULL, " ");
	}

	free(tok_origin);

	return (simple);
}

/**
 * sep_lines - Separates each line to its own string
 * @raw: THe raw text to tokenize
 *
 * Return: a 2d array based on /n
 */
char **sep_lines(char *raw)
{
	char **tok_out = NULL;
	char *line_tok = NULL, *ptr_origin;
	int line_count = 0, loop = 0;

	/* Find out how many lines so we can allocated the X of the 2d array */
	while (raw[loop] != '\0')
	{
		if (raw[loop] == '\n')
			line_count++;
		loop++;
	}
	line_count++;
	tok_out = malloc(line_count * sizeof(char *));
	verify_malloc(tok_out);

	/**
	 * Copy each line into the Y of the 2d array by
	 * using strtok with the /n as the delimiter
	 */
	loop = 0;
	ptr_origin = line_tok;
	line_tok = strtok(raw, "\n");
	while (line_tok != NULL)
	{
		tok_out[loop] = malloc((strlen(line_tok) + 1) * sizeof(char));
		verify_malloc(tok_out[loop]);
		strcpy(tok_out[loop], line_tok);
	
		line_tok = strtok(NULL, "\n");
		loop++;
	}


	/* free the garbage and return the finished 2d array */
	free(ptr_origin);
	free(line_tok);

	return (tok_out);
}
