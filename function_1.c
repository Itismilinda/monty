#include "monty.h"

/**
 * _push - The function that adds to the stack
 * @stack: This the stack
 * @line_number: This the line
 * Return: void
 */

void _push(stack_t **stack, unsigned int line_number)
{
	int integer;
	stack_t *new_node;
	char *value;

	value = strtok(NULL, " \t\n");
	if (value == NULL)
	{
		fprintf(stderr, "L%u: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}

	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	integer = atoi(value);
	if (integer == 0 && strcmp(value, "0") != 0)
	{
		fprintf(stderr, "L%u: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}

	new_node->n = integer;
	new_node->prev = NULL;
	new_node->next = *stack;

	if (*stack != NULL)
		(*stack)->prev = new_node;

	*stack = new_node;
}

/**
 * _pall - This function is for printing all values stores in the stack
 * @stack: This is the stack
 * @line_number: This is the line
 * Return: void
 */

void _pall(stack_t **stack, unsigned int line_number)
{
	stack_t *curt = *stack;
	(void)line_number;

	if (curt == NULL)
		return;

	while (curt != NULL)
	{
		printf("%d\n", curt->n);
		curt = curt->next;
	}
}

/**
 * _pop - This is a function that removes from the stack
 * @stack: This is the stack
 * @line_number: This is the line
 * Return: void
 */

void _pop(stack_t **stack, unsigned int line_number)
{

	if (!*stack)
	{
		fprintf(stderr, "L%u: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}

	if ((*stack)->next != NULL)
	{
		*stack = (*stack)->next;
		free((*stack)->prev);
		(*stack)->prev = NULL;
	}
	else
	{
		free(*stack);
		*stack = NULL;
	}
}

/**
 * _pint - prints the first value of a stack followed by new line
 * @stack: double pointer to the stack
 * @line_number: the line
 * Return: void
 */

void _pint(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	else
		printf("%d\n", (*stack)->n);
}

/**
 * _swap - swaps the top two elements of the stack
 * @stack: double pointer to the stack
 * @line_number: the line
 * Return: void
 */

void _swap(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;
	int value;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	else
	{
		temp = *stack;
		value = temp->n;
		temp->n = temp->next->n;
		temp->next->n = value;
	}
}
