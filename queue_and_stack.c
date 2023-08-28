#include "monty.h"

/**
 * stack_instruction - set the format of the data to a stack
 * @stack: the stack
 * @line_number: the line number
 */
void stack_instruction(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
	data_structure = 0;
}

/**
 * queue_instruction - set the format of the data to a queue
 * @stack: the stack
 * @line_number: the line number
 */
void queue_instruction(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;

	data_structure = 1;
}
