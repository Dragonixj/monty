#include "monty.h"



/**
 *pint - function that prints the value at the top of the stack
 *@stack: pointer to linked list 
 *@line_number: line number opcode occurs
 *
 */

void pint(stack_t **stack, unsigned int line_number)
{
	stack_t *current;
	current = *stack;

	if (current == NULL)
	{
		fprintf(stderr, "L%d: stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", current->n);
}
