#include "monty.h"


/**
 * is_all_whtspc - Returns if a string is all whitespace
 * @string: THe string to check
 *
 * Return: 1 if a string is all wtspc, 0 otherwise
 */
int is_all_whtspc(char *string)
{
	int iter = 0;

	if (string == NULL)
		return (1);
	for (; string[iter] != '\0'; iter++)
		if (isspace(string[iter]) == 0)
			return (0);

	return (1);
}

/**
 * free_stack - Frees the stack
 * 
 * 
 * Return: nothing
 */
void free_stack(void)
{
	stack_t *tail;

	while (global_stack->prev != NULL)
		global_stack = global_stack->prev;

	while (global_stack->next != NULL)
	{
		tail = global_stack;
		global_stack = global_stack->next;
		free(tail);
	}

	free(global_stack);
}