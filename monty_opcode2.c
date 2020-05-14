#include "monty.h"

/**
 * add - Adds the top two opcodes
 *
 * Return: 1 on success, 6 otherwise
 */
int add(void)
{
	int node1, node2;
	stack_t *freed;

	if (global_stack)
	{
		if (global_stack->next == NULL && global_stack->prev == NULL)
		{
			return (6);
		}

		while (global_stack->next != NULL)
			global_stack = global_stack->next;

		node1 = global_stack->n;
		node2 = global_stack->prev->n;

		freed = global_stack;
		global_stack = global_stack->prev;
		free(freed);
		global_stack->next = NULL;
		global_stack->n = node1 + node2;

		return (1);
	}

	return (6);
}
