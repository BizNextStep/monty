#include "monty.h"
/**
 * _add - Add the top two elements of the stack
 * @stack: Double pointer to the beginning of the stack
 * @line_number: Line number in Monty byte code file
 */
void _add(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;
	if (!stack || !*stack || !(*stack)->next)
	{
		fprintf(stderr, "L%u: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	(*stack)->next->n += (*stack)->n;
	temp = *stack;
	*stack = (*stack)->next;
	free(temp);
	if (*stack)
		(*stack)->prev = NULL;
}
