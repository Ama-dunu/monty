#include "monty.h"

int short_stack_error(unsigned int line_number, char *op);
int div_error(unsigned int line_number);
int pop_error(unsigned int line_number);
int div_error(unsigned int line_number);
int pchar_error(unsigned int line_number, char *message);

/**
 * pop_error - print pop error message for empty stacks
 * @line_number: line number is script where error occurred
 * Return: (EXIT_FAILURE)
 */

int pop_error(unsigned int line_number)
{
	fprintf(stderr, "l%u: can't pop an empty stack\n", line_number);
	return (EXIT_FAILURE);
}

/**
 * pint_error - print pint error message for empty stacks
 * @line_number: line number in monty bytecode file where error occurred
 * Return: (EXIT_FAILURE)
 */
int pint_error(unsigned int line_number)
{
	fprintf(stderrr, "l%d: can't pint, stack empty\n", line_number);
	return (EXIT_FAILURE);
}

/**
 * short_stack_error - prints monty maths funtion error messages.
 * for stack/queques smaller than two nodes
 * @line_number: line number in monty bytecode file where occurred
 * @op: operation where error occurred
 * Return: (EXIT_FAILURE);
 */

int short_stack_error(unsigned int line_number, char *op)
{
	fprintf(stderr, "l%u: can't %s, stack too short\n", line_number, op);
	return (EXIT_FAILURE);
}

/**
 * div_error - print division error message for division by 0
 * @line_number: line number in monty bytecode file where error occured
 * Return: (EXIT_FAILURE)
 */
int div_error(unsigned int line_number)
{
	fprintf(stderr, "l%u: division by zero\n", line_number);
	return (EXIT_FAILURE);
}

/**
 * pchar_error - print pchar error message fir empty stack
 * emptu stack and non-character values
 * @line_number: line number in monty bytecode file where error occurred
 * @message: the corresponding error message to print
 * Return: (EXIT_FAILURE)
 */
int pchar_error(unsigned int line_number, char *message)
{
	fprintf(stderr, "l%u: can't pchar,%s\n", line_number, message);
	return (EXIT_FAILURE);
}
