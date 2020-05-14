#include "monty.h"

/**
 * pchar - Prints the char at the top of the stack
 *
 *
 * Return: 1 on success, 13 if out of ascii range, 14 if stack empty
 */
int pchar(void)
{
	if (global_stack != NULL)
	{
		while (global_stack->next != NULL)
			global_stack = global_stack->next;

		if (global_stack->n > 255 || global_stack->n < 0)
			return (13);

		printf("%c\n", global_stack->n);
		return (1);
	}
	return (14);
}

/**
 * pstr - prints the string of the stack
 *
 *
 * Return: can you READ its VOID
 */
void pstr(void)
{
	if (global_stack != NULL)
	{
		while (global_stack->next != NULL)
			global_stack = global_stack->next;


		while (global_stack->prev != NULL)
		{
			if (!(global_stack->n > 255 || global_stack->n < 0)
				&& global_stack->n != 0)
				printf("%c", global_stack->n);
			else
				break;
			global_stack = global_stack->prev;
		}
	}
	printf("\n");
}
