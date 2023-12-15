#include "monty.h"

/**
 * _swap - Swap the top two elements of the stack
 * @stack: Double pointer to the beginning of the stack
 * @line_number: Line number in Monty byte code file
 */
void _swap(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	if (*stack == NULL || !*stack || !(*stack)->next)
	{
		fprintf(stderr, "L%u: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	temp = *stack;
	*stack = temp->next;
	temp->next = (*stack)->next;
	temp->prev = *stack;
	(*stack)->next = temp;
	if (temp->next)
		temp->next->prev = temp;
}
