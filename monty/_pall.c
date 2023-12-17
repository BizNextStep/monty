#include "monty.h"

/**
 * _pall - Print all values on the stack
 * @stack: Double pointer to the beginning of the stack
 * @line_number: Line number in Monty byte code file
 */
void _pall(stack_t **stack, unsigned int line_number)
{
	stack_t *current; /* Declare stack_t *current before the while loop */

	(void)line_number; /* Avoid unused parameter warning */

	current = *stack;

	while (current)
	{
		printf("%d\n", current->n);
		current = current->next;
	}
}
