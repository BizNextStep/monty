#define _POSIX_C_SOURCE 200809L
#include <stdio.h>
#include <stdlib.h>
#include "monty.h"

int main(int argc, char *argv[])
{
	FILE *file;
	char *line = NULL;
	size_t len = 0;
	stack_t *stack = NULL;
	unsigned int line_number = 0;
		char *opcode;

		if (argc != 2)
		{
			fprintf(stderr, "USAGE: monty file\n");
			exit(EXIT_FAILURE);
		}

		file = fopen(argv[1], "r");
		if (!file)
		{
			fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
			exit(EXIT_FAILURE);
		}

		while (getline(&line, &len, file) != -1)
		{
			line_number++;
			opcode = strtok(line, " \n");

			if (opcode)
			{
				if (strcmp(opcode, "nop") == 0)
				{
					_nop(&stack, line_number);
				}
				else
				{
					fprintf(stderr, "L%u: unknown instruction %s\n", line_number, opcode);
					free(line);
					fclose(file);
					exit(EXIT_FAILURE);
				}
			}
		}
		free(line);
		fclose(file);
		exit(EXIT_SUCCESS);
}
