#include "monty.h"

int usage_error(void);
int malloc_error(void);
int f_open_error(char *filename);
int unknown_op_error(char *opcode, unsigned int line_number);
int no_int_error(unsigned int line_number);

/**
 * usage _error - prints usage error message
 * Return: (EXIT_FAILURE)
 */
int usage_error(void);
{
	fprintf(stderr, "usage: monty file\n");
	return (EXIT_FAILURE);
}

/**
 * malloc_error - prints message with malloc error
 * Return: (EXIT_FAILURE)
 */

int malloc_error(void);
{
	fprintf(stderr, "Error: malloc failed\n");
	return (EXIT_FAILURE);
}

/**
 * f_open_error - prints file opening error message with file name
 * @filename: name of file failed to open.
 * Return: (EXIT_FAILURE)
 */

int f_open_error(char *filename);
{
	fprintf(stderr, "Error: Can't open file %s\n", filename);
}

/**
 * unknown_op_error - prints unknown instructions error message
 * @opcode: opcode where error occurred
 * line_number: line number in monty bytecode file where error has occurred
 * Return:(EXIT_FAILURE)
 */

int unknown_op_error(char *opcode, unsigned int line_number)
{
	fprintf(stderr, "l%u: unknown insstruction %s\n", line_number, opcode);
	return (EXIT_FAILURE);
}

/**
 * no_int_error - prints invalid monty_push argument error message
 * @line_number: line number in monty bytecode file where error occurred
 * Return: (EXIT_FAILURE)
 */

int no_int_error(unsigned int line_number)
{
	fprintf(stderr, "l%u: usage: push integer\n", line_number);
	return (EXIT_FAILURE);
