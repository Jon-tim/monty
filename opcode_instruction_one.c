#include "monty.h"
/**
 * push_instruction - push an element to the stack
 * @stack: stack
 * @line_number: line number
 */
void push_instruction(stack_t **stack, unsigned int line_number)
{
	stack_t *newNode;

	(void)line_number;

	newNode = malloc(sizeof(stack_t));

	if (newNode == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	newNode->n = value;
	newNode->prev = NULL;
	if (*stack == NULL)
	{
		newNode->next = NULL;
		*stack = newNode;
	}
	else
	{
		newNode->next = *stack;
		(*stack)->prev = newNode;
		*stack = newNode;
	}
}

/**
 * pall_instruction - print all elements of the stack
 * @stack: stack
 * @line_number: line number
 */
void pall_instruction(stack_t **stack, unsigned int line_number)
{
	stack_t *new;

	(void)line_number;

	new = *stack;
	while (new != NULL)
	{
		printf("%d\n", new->n);
		new = new->next;
	}
}

/**
 * pint_instruction - print the top element of the stack
 * @stack: stack
 * @line_number: line number
 */
void pint_instruction(stack_t **stack, unsigned int line_number)
{
	stack_t *new = *stack;

	if (new != NULL)
		printf("%d\n", new->n);
	else
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
}

/**
 * pop_instruction - pop an element from the stack
 * @stack: stack
 * @line_number: line number
 */
void pop_instruction(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp = NULL;

	if (*stack != NULL)
	{
		tmp = (*stack)->next;
		if (tmp != NULL)
			tmp->prev = NULL;
		free(*stack);
		(*stack) = tmp;
	}
	else
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}
}

/**
 * swap_instruction - swap the top two elements of the stack
 * @stack: stack
 * @line_number: line number
 */
void swap_instruction(stack_t **stack, unsigned int line_number)
{
	stack_t *topGun = NULL;
	stack_t *secondGun = NULL;

	if (*stack != NULL && (*stack)->next != NULL)
	{
		topGun = *stack;
		secondGun = topGun->next;

		topGun->next = secondGun->next;
		secondGun->prev = NULL;

		if (topGun->next != NULL)
		{
			topGun->next->prev = topGun;
		}

		secondGun->next = topGun;
		topGun->prev = secondGun;

		(*stack) = secondGun;
	}
	else
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
}
