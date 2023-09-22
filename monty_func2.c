#include "monty.h"
void monty_nop(stack_t **stack, unsigned int line_number);
void monty_pchar(stack_t **stack, unsigned int line_number);
void monty_pstr(stack_t **stack, unsigned int line_number);

/**
 * monty_nop - doesn't do anything for the monty opcode 'op'
 * @stack: pointer to the top mode node of a stack_t linked list
 * @line_number: the current working line number of a monty bytecode file
 */

void monty_nop(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
}

/**
 * monty_pchar - prints the character in the top value
 * node of a stack_t linked list
 * @stack: pointer to the top mode node of a stack_t linked list
 * @line_number: the current working line number of a monty bytecode file
 */

void monty_pchar(stack_t **stack, unsigned int line_number)
{
	if ((*stack)->next == NULL)
	{
		set_op_tok_error(pchar_error(line_number, "stack empty"))
			return;
	}
	if ((*stack)->next->n < 0 || (*stack)->n > 127)
	{
		set_op_tok_error(pchar_error(line_number, "value but of range"));
		return;
	}
	printf("%c\n", (*stack)->next->n);
}

/**
 * monty_pstr - prints the string contained in a stack_t linked lists
 * @stack: pointer to the top mode node of a stack_t linked list
 * @line_number: the current working line number of a monty bytecode file
 */

void monty_pstr(stack_t **stack, unsigned int line_number)
{
	stack_t *top = (*stack)->next;

	while (top && tmp->n != 0 && (tmp->n > 0 && tmp->n <= 127))
	{
		printf("%c", tmp->n);
		tmp - tmp->next;
	}
	printf("\n");
	(void)line_number;
}
