#include "monty.h"
/**
 * op_check - function that checks it a command
 * is an op-code
 * @str: string to check
 * @line_number: line number
 * Return: function pointer or Void
 */

void (*op_check(char *str, unsigned int line_number))(stack_t **, unsigned int)
{

	int i;

	instruction_t instructions[] = {
		{"push", push_instruction},
		{"pall", pall_instruction},
		{"pint", pint_instruction},
		{"pop", pop_instruction},
		{"swap", swap_instruction},
		{"add", add_instruction},
		{"nop", nop_instruction},
		{"sub", sub_instruction},
		{"div", div_instruction},
		{"mul", mul_instruction},
		{"mod", mod_instruction},
		{"pchar", pchar_instruction},
		{"pstr", pstr_instruction},
		{"rotl", rotl_instruction},
		{"rotr", rotr_instruction},
		{"stack", stack_instruction},
		{"queue", queue_instruction},
		{NULL, NULL}};

	for (i = 0; instructions[i].opcode != NULL; i++)
	{
		if (strcmp(str, instructions[i].opcode) == 0)
		{
			return (instructions[i].f);
		}
	}

	fprintf(stderr, "L%u: unknown instruction %s\n", line_number, str);
	exit(EXIT_FAILURE);
	return (NULL);
}
