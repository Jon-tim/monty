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

/**
 * pchar_instruction - function that prints the char at the top of the stack
 * @stack: the stack
 * @line_number: the line number
 */
void pchar_instruction(stack_t **stack, unsigned int line_number)
{
	if (*stack && (*stack)->n)
	{
		if ((*stack)->n >= 0 && (*stack)->n <= 127)
		{
			printf("%c\n", (char)(*stack)->n);
		}
		else
		{
			fprintf(stderr, "L%d: can't pchar, value out of range\n", line_number);
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
}

/**
 * pstr_instruction - function that prints the string
 * starting at the top of the stack
 * @stack: the stack
 * @line_number: the line number
 */
void pstr_instruction(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp = NULL;
	char holder[30];
	int i = 0;

	(void)line_number;

	if (*stack)
	{
		tmp = *stack;
		while (tmp && tmp->n >= 0 && tmp->n <= 127)
		{
			if (tmp->n != 0)
			{
				holder[i] = (char)tmp->n;
				i++;
			}
			else
			{
				break;
			}
			tmp = tmp->next;
		}
		holder[i] = '\0';
		printf("%s\n", holder);
	}
	else
	{
		printf("\n");
	}
}
