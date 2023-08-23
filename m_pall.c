#include "monty.h"
/**
 * m_pall: prints all the values on the stack
 * @stack: Pointer to the pointer of the stacks head
 * @line_number: line number in the file(not used in this function though)
 *
 * Return: no return value
 */

void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *count;

	count = *stack;

	while (count != NULL)
	{
		printf("%d\n", count->n);
		count = count->next;
	}
}
