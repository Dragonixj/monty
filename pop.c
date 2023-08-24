#include "monty.h"

/**
 * pop - Removes the top element from the stack
 * @stack: A pointer to a pointer to the stack
 * @line_number: Line number for error reporting
 *
 * This function removes the top element from the stack.
 */

void pop(stack_t **stack, unsigned int line_number)
{
    stack_t *temp;
    
    if (*stack == NULL)
    {
        fprintf(stderr, "L%u: can't pop an empty stack\n", line_number);
        exit(EXIT_FAILURE);
    }

    temp = *stack;
    *stack = (*stack)->prev;
    if (*stack != NULL)
    {
        (*stack)->next = NULL;
    }

    free(temp);
}

