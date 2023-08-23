#include "monty.h"


/**
 * pop - Removes the top element from the stack
 * @stack: A pointer to a pointer to the stack
 * @line_number: Line number for error reporting
 *
 * This function removes the top element from the stack.
 * If the stack is empty, an error message is printed.
 */

void pop(stack_t **stack, unsigned int line_number)
{
    stack_t *temp;	
    if (*stack == NULL)
    {
        printf("Error at line %u: Stack is empty\n", line_number);
        return;
    }

    temp = *stack;
    *stack = (*stack)->prev;
    if (*stack != NULL)
    {
        (*stack)->next = NULL;
    }

    free(temp);
}

