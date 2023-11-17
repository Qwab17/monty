#include "monty.h"

/**
 * push - Pushes an element to the stack
 * @stack: A pointer to the stack
 * @line_number: The line number in the Monty file
 */
void push(stack_t **stack, unsigned int line_number)
{
	char *value_str;
	int value;

	if (stack == NULL)
	{
		fprintf(stderr, "L%u: stack not found\n", line_number);
		exit(EXIT_FAILURE);
	}

	value_str = strtok(NULL, " \t\n");
	if (value_str == NULL || !is_number(value_str))
	{
		fprintf(stderr, "L%u: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}

	value = atoi(value_str);
	push_stack(stack, value);
}

/**
 * pall - Prints all the values on the stack
 * @stack: A pointer to the stack
 * @line_number: The line number in the Monty file
 */
void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *current = *stack;

	(void)line_number;

	while (current != NULL)
	{
		printf("%d\n", current->n);
		current = current->next;
	}
}
