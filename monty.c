#include "monty.h"

void free_stack(stack_t **stack);
void (*get_op_func(char *opcode))(stack_t **, unsigned int);
void (*op_func)(stack_t **, unsigned int);

/**
 * main - Entry point for the Monty interpreter
 * @argc: Number of command-line arguments
 * @argv: Array of command-line arguments
 * Return: EXIT_SUCCESS on success, EXIT_FAILURE on failure
 */
int main(int argc, char *argv[])
{
	FILE *file;
	stack_t *stack = NULL;
	char *line = NULL;
	size_t len = 0;
	unsigned int line_number = 0;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	file = fopen(argv[1], "r");
	if (file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	while (getline(&line, &len, file) != -1)
	{
		line_number++;
		op_func = get_op_func(line);
		if (op_func != NULL)
			op_func(&stack, line_number);
	}

	fclose(file);
	free(line);
	free_stack(&stack);
	return (EXIT_SUCCESS);
}
