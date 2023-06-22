#include "monty.h"

/**
 * _add - This is a function that adds the top elements of a stack
 * @stack: This is the pointer to the stack
 * @line_number: This is the line_number
 * Return: Void
 */

void _add(stack_t **stack, unsigned int line_number)
{
	stack_t *t_stack;
	stack_t *s_stack;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	t_stack = *stack;
	s_stack = t_stack->next;

	s_stack->n += t_stack->n;
	s_stack->prev = NULL;
	*stack = s_stack;

	free(t_stack);
}

/**
 * _sub - This ia a function that subtracts top elements
 * from the second top
 * @stack: This is a pointer to the stack
 * @line_number: This is the number of the line
 * Return: void
 */

void _sub(stack_t **stack, unsigned int line_number)
{
	stack_t *to_stack;
	stack_t *se_stack;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't sub, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	to_stack = *stack;
	se_stack = to_stack->next;

	se_stack->n -= to_stack->n;
	se_stack->prev = NULL;
	*stack = se_stack;

	free(to_stack);
}

/**
 * _mul - This is a function that multiplies the second top element
 * of the stack with the top
 * @stack: This is the pointer to the stack
 * @line_number: This is the the line_number
 * Return: Nothing
 */

void _mul(stack_t **stack, unsigned int line_number)
{
	stack_t *top_stack;
	stack_t *sec_stack;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't mul, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	top_stack = *stack;
	sec_stack = top_stack->next;

	sec_stack->n *= top_stack->n;
	sec_stack->prev = NULL;

	*stack = sec_stack;
	free(top_stack);
}
