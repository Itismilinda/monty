#include "monty.h"

/**
 * get_opcode - This a function that reads the line
 * @opcode: This is the opcode
 * @line_number: This is the number of lines
 * @stack: This is a the stack
 * Return: Void
 */

void get_opcode(stack_t **stack, char *opcode, unsigned int line_number)
{
	int lo, opc_valid = 0;

	instruction_t instruction[] = {
		{ "push", _push },
		{ "pall", _pall },
		{ "pop", _pop },
		{ "pint", _pint },
		{ "swap", _swap },
		{ "nop", _nop },
		{ "add", _add },
		{ "sub", _sub },
		{ "mul", _mul },
		{ "div", _div },
		{ "mod", _mod },
		{ NULL, NULL }
	};

	for (lo = 0; instruction[lo].opcode != NULL; lo++)
	{
		if (strcmp(opcode, instruction[lo].opcode) == 0)
		{
			opc_valid = 1;
			instruction[lo].f(stack, line_number);
			break;
		}
	}

	if (opc_valid == 0)
	{
		fprintf(stderr, "L%u: unknown instruction %s\n", line_number, opcode);
		exit(EXIT_FAILURE);
	}
}
