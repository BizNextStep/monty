#include "monty.h"

/**
 * _push - Push an element to the stack
 * @stack: Double pointer to the beginning of the stack
 * @line_number: Line number in Monty byte code file
 */
void _push(stack_t **stack, unsigned int line_number)
{
	char *arg = strtok(NULL, " \n");
	int num;
	stack_t *new_node;

	if (!arg || !isdigit(arg[0] == '-' ? arg + 1 : arg))

	{
		fprintf(stderr, "L%u: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}
	num = atoi(arg);

	/* Create a new stack node */
	new_node = malloc(sizeof(stack_t));
	if (!new_node)

	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	new_node->n = num;
	new_node->prev = NULL;
	new_node->next = *stack;
	if (*stack)
		(*stack)->prev = new_node;
	*stack = new_node;

	printf("Pushed %d to the stack\n", num);

}
