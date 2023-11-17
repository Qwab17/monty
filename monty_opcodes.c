#include "monty.h"

/**
 * get_op_func - Selects the correct function to perform an operation
 * @opcode: The operation to perform
 * Return: A pointer to the function that corresponds to the opcode
 */
void (*get_op_func(char *opcode))(stack_t **, unsigned int)
{
	int i = 0;

	instruction_t opcodes[] = {
		{"pint", pint},
		{"push", push},
		{"pall", pall},
		{NULL, NULL}
	};

	while (opcodes[i].opcode != NULL)
	{
		if (strcmp(opcodes[i].opcode, opcode) == 0)
			return (opcodes[i].f);
		i++;
	}

	return (NULL);
}
