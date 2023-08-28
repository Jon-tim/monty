#include "monty.h"
int data_structure = 0;
/**
 * main - entry point for the monty interpreter program
 * @argc: argument counts fron the CLI
 * @argv: argument vector
 * Return: 0
 */
int main(int argc, char *argv[])
{
	FILE *file;
	char buffer[256];
	unsigned int line_number = 1;
	char *opcode;
	stack_t *stack = NULL;

	if (argv[1] == NULL || argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	file = fopen(argv[1], "r");
	if (file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	};

	while (fgets(buffer, sizeof(buffer), file) != NULL)
	{
		void (*op_fn)(stack_t **, unsigned int);
		char *op_arg;

		if (buffer[0] == '#')
			continue;
		opcode = strtok(buffer, " \n");
		if (strcmp(opcode, "push") == 0)
		{
			op_arg = strtok(NULL, " ");
		}
		op_fn = op_check(opcode, line_number);
		op_fn(&stack, line_number);
		line_number++;
	}
	fclose(file);
	return (0);
}
