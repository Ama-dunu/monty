#include "monty.h"

void monty_add(stack_t **stack, unsigned int line_number);
void monty_sub(stack_t **stack, unsigned int line_number);
void monty_div(stack_t **stack, unsigned int line_number);
void monty_mul(stack_t **stack, unsigned int line_number);
void monty_mod(stack_t **stack, unsigned int line_number);

/**
 * monty_add - adds the top two valus of a stack_t linked list
 * @stack: pointer to the top mode node of a stack_t linked list
 * @line_number: the current working line number of a monty bytecodes files
 * Description: the result is stored in the second value node.
 * from the top and the top value is removed
 */

void monty_add(stack_t **stack, unsigned int line_number)
{
	if ((*stack)->next, == NULL || (*stack)->next->next == NULL)
	{
		set_op_tok_error(short_stack_error(line_number, "add"));
		return;
	}

	(*stack)->next->next->n += (*stack)->next->n;
	monty_pop(stack, line_number);
}

/**
 * monty_sub - subtracts the second values from the top
 * of a stack_t linked list by the top values
 * @stack: pointer to the mode node of a stack_t linked list
 * @line_number: the current working line number of a monty bytecode file
 * Description: the result is stored in the second value node
 * from the top value is removed.
 */
void monty_sub(stack_t **stack, unsigned int line_number)
{
	if ((*stack)->next == NULL || (*stack)->next->next == NULL)
	{
		set_op_tok_error(short_stack_error(line_number, "sub"));
		return;
	}

	(*stack)->next->next->n -= (*stack)->next->n;
	monty_pop(stack, line_number);
}

/**
 * monty_div - divides the second values from the top
 * of a stack_t linked list by the top values
 * @stack: pointer to the mode node of a stack_t linked list
 * @line_number: the current working line number of a monty bytecode file
 * Description: the result is stored in the second value node
 * from the top value is removed.
 */
void monty_div(stack_t **stack, unsigned int line_number)
{
	if ((*stack)->next == NULL || (*stack)->next->next == NULL)
	{
		set_op_tok_error(short_stack_error(line_number, "div"));
		return;
	}

	if ((*stack)->next->n == 0)
	{
		set_op_tok_error(div_error(line_number));
		return;
	}

	(*stack)->next->next->n /= (*stack)->next->n;
	monty_pop(stack, line_number);
}

/**
 * monty_mul - multiplies the second values from the top
 * of a stack_t linked list by the top values
 * @stack: pointer to the mode node of a stack_t linked list
 * @line_number: the current working line number of a monty bytecode file
 * Description: the result is stored in the second value node
 * from the top value is removed.
 */
void monty_mul(stack_t **stack, unsigned int line_number)
{
	if ((*stack)->next == NULL || (*stack)->next->next == NULL)
	{
		set_op_tok_error(short_stack_error(line_number, "mul"));
		return;
	}

	(*stack)->next->next->n *= (*stack)->next->n;
	monty_pop(stack, line_number);
}

/**
 * monty_mod - computes the modules the second values from the top
 * of a stack_t linked list by the top values
 * @stack: pointer to the mode node of a stack_t linked list
 * @line_number: the current working line number of a monty bytecode file
 * Description: the result is stored in the second value node
 * from the top value is removed.
 */
void monty_mod(stack_t **stack, unsigned int line_number)
{
	if ((*stack)->next == NULL || (*stack)->next->next == NULL)
	{
		set_op_tok_error(short_stack_error(line_number, "mod"));
		return;
	}

	if ((*stack)->next->n == 0)
	{
		set_op_tok_error(div_error(line_number));
		return;
	}

	(*stack)->next->next->n %= (*stack)->next->n;
	monty_pop(stack, line_number);
}
