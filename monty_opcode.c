#include "monty.h"

/**
 * push - Pushes a value to the stack
 * @value: THe value to push to the stack
 *
 * Return: 1 on success, 0 on failure
 */
int push(char *value)
{
	stack_t *new_node;

	if (value == NULL)
		return (2);
	if (value[0] != '0' && atoi(value) == 0)
		return (2);

	new_node = malloc(sizeof(stack_t));
	if (!new_node)
		return (100);
	new_node->n = atoi(value);
	new_node->next = NULL;
	new_node->prev = NULL;

	if (global_stack == NULL)
	{
		global_stack = new_node;
	}
	else
	{
		while (global_stack->next != NULL)
			global_stack = global_stack->next;

		new_node->prev = global_stack;
		global_stack->next = new_node;
	}

	return (1);
}

/**
 * pall -  Prints all values on a stack
 *
 * Return: 1 on success, 0 otherwise
 */
void pall(void)
{
	if (global_stack)
	{
		while (global_stack->next != NULL)
			global_stack = global_stack->next;

		while (global_stack->prev != NULL)
		{
			printf("%d\n", global_stack->n);
			global_stack = global_stack->prev;
		}
		printf("%d\n", global_stack->n);
	}
}

/**
 * pint - Prints the top of the stack
 *
 * Return: 1 on success, 3 otherwise
 */
int pint(void)
{
	if (global_stack != NULL)
	{
		while (global_stack->next != NULL)
			global_stack = global_stack->next;

		printf("%d\n", global_stack->n);
		return (1);
	}
	return (3);
}
