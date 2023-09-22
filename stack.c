#include "monty.h"
#include <string.h>

void free_stack(stack_t **stack);
int init_stack(stack_t **stack);
int check_mode(stack_t *stack);

/**
 * free_stack - fress stack_t stack
 * @stack: pointer to the top (stack)
 * or bottom (queque) of stack_t
 */

void free_stack(stack_t **stack)
{
	stack_t *top = *stack;

	while (*stack)
	{
		top = (*stack)->next;
		free(*stack);
		*stack = top;
	}
}

/**
 * init_stack - initializes stack_t stack with beginning stack
 * and ending queque nodes
 * @stack: pointer to an uninitialized stack_t stack
 * Return: when an error happens - EXIT_FAILURE
 * otherwise - EXIT_SUCCESS
 */

int init_stack(stack_t **stack)
{
	stack_t *s;

	s = malloc(sizeof(stack_t));
	if (s == NULL)
		return (malloc_error());

	s->n = stack;
	s->prev = NULL;
	s->next = NULL;

	*stack = s;

	return (EXIT_SUCCESS);
}

/**
 * check_mode - checks if stack_t linked list is in queque or stack mode
 * @stack: pointer to the bottom (queque) or to the top (stack)
 * Return: if the stack_t is in queque mode - QUEQUE (1)
 * if the stack_t is in stack mode - STACK (0)
 * otherwise - 2
 */

int check_mode(stack_t *stack)
{
	if (stack->n == STACK)
		return (STACK);
	else if (stack->n == QUEQUE)
		return (QUEQUE);
	return (2);
}
