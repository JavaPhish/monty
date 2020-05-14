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

/**
 * sub - Subracts the item at the top with the one below it
 *
 *
 * Return: 1 on success, 7 othwerwise
 */
int sub(void)
{
	int node1, node2;
	stack_t *freed;

	if (global_stack)
	{
		if (global_stack->next == NULL && global_stack->prev == NULL)
		{
			return (7);
		}

		while (global_stack->next != NULL)
			global_stack = global_stack->next;

		node1 = global_stack->n;
		node2 = global_stack->prev->n;

		freed = global_stack;
		global_stack = global_stack->prev;
		free(freed);
		global_stack->next = NULL;
		global_stack->n = node2 - node1;

		return (1);
	}

	return (7);
}

/**
 * op_div - Divides the top two elements
 *
 *
 * Return: 1 on success, 8 otherwise, 9 when top is zero
 */
int op_div(void)
{
	int node1, node2;
	stack_t *freed;

	if (global_stack)
	{
		if (global_stack->next == NULL && global_stack->prev == NULL)
		{
			return (8);
		}

		while (global_stack->next != NULL)
			global_stack = global_stack->next;

		node1 = global_stack->n;
		node2 = global_stack->prev->n;

		if (node1 == 0)
			return (9);

		freed = global_stack;
		global_stack = global_stack->prev;
		free(freed);
		global_stack->next = NULL;
		global_stack->n = node2 / node1;

		return (1);
	}

	return (8);
}

/**
 * mul - Multiplies top two elements in stack
 *
 *
 * Return: 1 on success, 10 otherwise
 */
int mul(void)
{
	int node1, node2;
	stack_t *freed;

	if (global_stack)
	{
		if (global_stack->next == NULL && global_stack->prev == NULL)
		{
			return (10);
		}

		while (global_stack->next != NULL)
			global_stack = global_stack->next;

		node1 = global_stack->n;
		node2 = global_stack->prev->n;

		freed = global_stack;
		global_stack = global_stack->prev;
		free(freed);
		global_stack->next = NULL;
		global_stack->n = node2 * node1;

		return (1);
	}

	return (10);
}

/**
 * mod - remainder of 2 elements
 *
 *
 * Return: 1 on success, 11 otherwise, 12 when top is zero
 */
int mod(void)
{
	int node1, node2;
	stack_t *freed;

	if (global_stack)
	{
		if (global_stack->next == NULL && global_stack->prev == NULL)
		{
			return (11);
		}

		while (global_stack->next != NULL)
			global_stack = global_stack->next;

		node1 = global_stack->n;
		node2 = global_stack->prev->n;

		if (node1 == 0)
			return (12);

		freed = global_stack;
		global_stack = global_stack->prev;
		free(freed);
		global_stack->next = NULL;
		global_stack->n = node2 % node1;

		return (1);
	}

	return (11);
}
