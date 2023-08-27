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
}

/**
 * sub_instruction - subtracts the top two elements of the stack
 * @stack: the stack
 * @line_number: the line number
*/
void sub_instruction(stack_t **stack, unsigned int line_number)
{
	int diff = 0;
	stack_t *topGun = NULL;
	stack_t *secondGun = NULL;

	if (*stack && (*stack)->next)
	{
		topGun = *stack;
		secondGun = (*stack)->next;
		diff = topGun->n - secondGun->n;
		secondGun->n = diff;
		topGun->next->prev = NULL;
		free(topGun);
		*stack = secondGun;
	}
	else
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
}

/**
 * div_instruction - divides the top two elements of the stack
 * @stack: the stack
 * @line_number: the line number
 */
void div_instruction(stack_t **stack, unsigned int line_number)
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
		secondGun->n = secondGun->n / topGun->n;
		topGun->next->prev = NULL;
		free(topGun);
		*stack = secondGun;
	}
	else
	{
		fprintf(stderr, "L%d: can't div, stack too short\n", line_number);
	}
}

/**
 * mul_instruction - multiplies the top two elements of the stack
 * @stack: the stack
 * @line_number: the line number
 */
void mul_instruction(stack_t **stack, unsigned int line_number)
{
	stack_t *topGun = NULL;
	stack_t *secondGun = NULL;

	if (*stack && (*stack)->next)
	{
		topGun = *stack;
		secondGun = (*stack)->next;

		secondGun->n = secondGun->n * topGun->n;
		topGun->next->prev = NULL;
		free(topGun);
		*stack = secondGun;
	}
	else
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
}
