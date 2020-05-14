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
}

/**
 * verify_malloc - Verify integrity of a malloc
 * @mal: The memory allocated
 *
 * Return: 1 if it was successful, 0 otherwise (Also it just exists so)
 */
int verify_malloc(void *mal)
{

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
