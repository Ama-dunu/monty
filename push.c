#include "monty.h"

/**
 * f_push - Pushes an integer onto the stack or queue.
 * @head: A pointer to a pointer to the stack's head.
 * @counter: The line number where the push operation occurs.
 * Return: No return value.
 */
void f_push(stack_t **head, unsigned int counter)
{
	int n, j = 0, flag = 0;

	if (bus.arg)
	{
		if (bus.arg[0] == '-')
			j++;

		while (bus.arg[j] != '\0')
		{
			if (bus.arg[j] > '9' || bus.arg[j] < '0')
				flag = 1;
			j++;
		}

		if (flag == 1)
		{
			fprintf(stderr, "L%d: usage: push integer\n", counter);
			fclose(bus.file);
			free(bus.content);
			free_stack(*head);
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		fprintf(stderr, "L%d: usage: push integer\n", counter);
		fclose(bus.file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}

	n = atoi(bus.arg);

	if (bus.lifi == 0)
		addnode(head, n);
	else
		addqueue(head, n);
}
