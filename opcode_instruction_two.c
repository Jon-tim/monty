#include "monty.h"

/**
 * add_instruction - adds the top two elements of the stack
 * @stack: the stack
 * @line_number: the line number
 */
void add_instruction(stack_t **stack, unsigned int line_number)
{
	int sum = 0;
	stack_t *topGun = NULL;
	stack_t *secondGun = NULL;

	if (*stack && (*stack)->next)
	{
		topGun = *stack;
		secondGun = (*stack)->next;
		sum = topGun->n + secondGun->n;
		secondGun->n = sum;
		secondGun->prev = NULL;
		free(topGun);
		*stack = secondGun;
	}
	else
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
}

/**
 * nop_instruction - does nothing
 * @stack: the stack
 * @line_number: the line number
 */
void nop_instruction(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
	return;
}