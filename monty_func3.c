#include "monty.h"

void monty_rotl(stack_t **stack, unsigned int line_number);
void monty_rotr(stack_t **stack, unsigned int line_number);
void monty_stack(stack_t **stack, unsigned int line_number);
void monty_queque(stack_t **stack, unsigned int line_number);

/**
 * monty_rotl - rotates the top values of a stack_t linked list to the bottom
 * @stack: pointer to the top mode node of a stack_t linked list
 * @line_number: current working line number of a monty bytecode files
 */

void monty_rotl(stack_t **stack, unsigned int line_number)
{
	stack_t *top, *bottom;

	if ((*stack)->next == NULL || (*stack)->next == NULL)
		return;

	top = (*stack)->next;
	bottom = (*stack)->next;
	while (bottom->next != NULL)
		bottom = bottom->next;

	top->next->prev = *stack;
	(*stack)->next = top->next;
	bottom->next = top;
	top->next = NULL;
	top->prev = bottom;

	(void)line_number;
}
/**
 * monty_rotr - rotates the bottom values of a stack_t linked list to the top
 * @stack: pointer to the top mode node of a stack_t linked list
 * @line_number: current working line number of a monty bytecode files
 */

void monty_rotr(stack_t **stack, unsigned int line_number)
{
	stack_t *top, *bottom;

	if ((*stack)->next == NULL || (*stack)->next == NULL)
		return;

	top = (*stack)->next;
	bottom = (*stack)->next;
	while (bottom->next != NULL)
		bottom = bottom->next;

	bottom->prev->next = NULL;
	(*stack)->next = bottom;
	bottom->prev = *stack;
	bottom->next = top;
	top->prev = bottom;

	(void)line_number;
}

/**
 * monty_stack - converts queque to stack
 * @stack: pointer to the top mode node of a stack_t linked list
 * @line_number: current working line number of a monty bytecode files
 */

void monty_stack(stack_t **stack, unsigned int line_number)
{
	(*stack)->n = STACK;
	(void)line_number;
}

/**
 * monty_stack - converts stack to queque
 * @stack: pointer to the top mode node of a stack_t linked list
 * @line_number: current working line number of a monty bytecode files
 */

void monty_queque(stack_t **stack, unsigned int line_number)
{
	(*stack)->n = queque;
	(void)line_number;
}
