#include "monty.h"

/**
 * _nop - The opcode that does nothing
 * @stack: Double pointer to the beginning of the stack
 * @line_number: Line number in Monty byte code file
 */
void _nop(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
	/* Do nothing */
}
