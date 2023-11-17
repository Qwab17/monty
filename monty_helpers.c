#include "monty.h"

/**
 * push_stack - Pushes a value onto the stack
 * @stack: A pointer to the stack
 * @value: The value to push onto the stack
 */
void push_stack(stack_t **stack, int value)
{
	stack_t *new_node = malloc(sizeof(stack_t));

	if (new_node == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	new_node->n = value;
	new_node->prev = NULL;
	new_node->next = *stack;

	if (*stack != NULL)
		(*stack)->prev = new_node;

	*stack = new_node;
}

/**
 * free_stack - Frees a stack
 * @stack: A pointer to the stack
 */
void free_stack(stack_t **stack)
{
	stack_t *current = *stack;
	stack_t *next;

	while (current != NULL)
	{
		next = current->next;
		free(current);
		current = next;
	}

	*stack = NULL;
}

/**
 * is_number - Check if a string represents a number.
 * @str: The string to check.
 * Return: 1 if the string is a number, 0 otherwise.
 */

int is_number(const char *str)
{
	if (str == NULL || *str == '\0')
		return (0);

	while (*str)
	{
		if (!isdigit(*str) && *str != '-')
			return (0);
		str++;
	}

	return (1);
}
