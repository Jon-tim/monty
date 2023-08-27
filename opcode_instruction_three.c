#include "monty.h"
/**
 * mod_instruction - function that computes the rest of the division
 * @stack: the stack
 * @line_number: the line number
 */
void mod_instruction(stack_t **stack, unsigned int line_number)
{
	stack_t *topGun = NULL;
	stack_t *secondGun = NULL;

	if (*stack && (*stack)->next)
	{
		topGun = *stack;
		secondGun = (*stack)->next;

		if (topGun->n == 0)
		{
			fprintf(stderr, "L%d: division by zero\n", line_number);
			exit(EXIT_FAILURE);
		}

		secondGun->n = secondGun->n % topGun->n;
		topGun->next->prev = NULL;
		free(topGun);
		*stack = secondGun;
	}
	else
	{
		fprintf(stderr, "L%d: can't mod, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
}
