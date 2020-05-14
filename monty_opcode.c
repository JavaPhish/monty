#include "monty.h"

/**
 * push - Pushes a value to the stack
 * @stack: THe stack to push to
 * @value: THe value to push to the stack
 * 
 * Return: 1 on success, 0 on failure
 */
void push(int value)
{
	stack_t *new_node;
	new_node = malloc(sizeof(stack_t));
	verify_malloc(new_node);
	new_node->n = value;

	if (global_stack == NULL)
	{
		new_node->n = value;
		global_stack = new_node;
	}
	else
	{	
		new_node->prev = global_stack;
		global_stack->next = new_node;
		global_stack = new_node;
	}
	
}

/**
 * pall -  Prints all values on a stack
 * @stack: The stack to print
 * 
 * Return: 1 on success, 0 otherwise
 */
void pall()
{

	while (global_stack->prev != NULL)
		global_stack = global_stack->prev;

	while (global_stack->next != NULL)
	{
		printf("%d\n", global_stack->n);
		global_stack = global_stack->next;
	}
	printf("%d\n", global_stack->n);
}