#include "monty.h"

/**
 * _pop - Remove the top element of the stack
 * @stack: Double pointer to the beginning of the stack
 * @line_number: Line number in Monty byte code file
 */
void _pop(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;
	if (!stack || !*stack)

	{
		fprintf(stderr, "L%u: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}
	temp = *stack;
	*stack = (*stack)->next;
	free(temp);
	if (*stack)
		(*stack)->prev = NULL;
}
