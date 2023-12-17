#define _GNU_SOURCE
#include "monty.h"
#include <stdio.h>

bus_t bus = {NULL, NULL, NULL, 0}; /* Initialization of the bus variable */

/* Prototype for the execute function */
void execute(char *content, stack_t **stack, unsigned int counter, FILE *file);

int main(int argc, char *argv[])
{
	FILE *file;
	char *line = NULL;
	size_t size; /* Declare the size variable */
	ssize_t read_line = 1;
	stack_t *stack = NULL;
	unsigned int counter = 0; /* Declare the counter variable */

		if (argc != 2)
		{
			fprintf(stderr, "USAGE: monty file\n");
			exit(EXIT_FAILURE);
		}

		file = fopen(argv[1], "r");
		bus.file = file;

		if (!file)
		{
			fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
			exit(EXIT_FAILURE);
		}

		while (read_line > 0)
		{
			char *content = NULL; 
			read_line = getline(&content, &size, file);
			bus.content = content;
			counter++;

			if (read_line > 0)
				execute(content, &stack, counter, file);
			free(content);

		}
		free(line);
		fclose(file);
		exit(EXIT_SUCCESS);
}
