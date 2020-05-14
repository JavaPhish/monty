#include "monty.h"

/**
 * free_stack - Frees the stack
 * @head: the list to free from its digital prison
 *
 * Return: None, noob.
 */
void free_stack(stack_t *head)
{
	stack_t *tail;

	if (!head)
		exit(1);

	while (head->prev)
		head = head->prev;

	while (head)
	{
		tail = head;
		head = head->next;
		free(tail);
	}
	free(head);
}

/**
 * verify_malloc - Verify integrity of a malloc
 * @mal: The memory allocated
 * 
 * Return: 1 if it was successful, 0 otherwise (Also it just exists so)
 */
int verify_malloc(void *mal)
{
	/* I made this to save lines and to make code cleaner. I didnt wanna have
	to manually write this after each malloc so i made a function to make it
	a lot smoother. */
	if (!mal)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	return (1);
}

/**
 * free2d_str - Frees a 2d array of strings
 * @arr: String to free
 * 
 * Return: Nothing. Nerd.
 */
void free2d_str(char **arr)
{
	int freeme = 0;

	while (arr[freeme])
	{
		free(arr[freeme]);
		freeme++;
	}
	free(arr);
}

/**
 * _contains - Checks if a string contains a given set of chars
 * @str: The string to check through
 * @keyword: The key word to check for
 *
 * Return: 1 if the keyword is in the string, 0 if not (Or edge case)
 */
int _contains(char *str, char *keyword)
{
	int loop = 0;
	int check_loop = 0;

	check_loop = 0;

	if (str[0] == '\0')
		return (0);

	if (keyword[0] == '\0')
		return (0);

	if (!str)
		return (0);
	if (!keyword)
		return (0);

	for (loop = 0; str[loop] != '\0'; loop++)
	{
		if (keyword[check_loop] == '\0')
			return (1);

		if (str[loop] == keyword[check_loop])
			check_loop++;
		else
			check_loop = 0;

		if (str[loop + 1] == '\0' && keyword[check_loop] == '\0')
			return (1);
	}
	return (0);
}