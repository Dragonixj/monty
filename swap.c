#include "monty.h"

/**
 * swap - Swaps the top two elements of the stack.
 * @stack: A pointer to the top of the stack.
 * @line_number: The line number in the script where the swap operation is called.
 *
 * Description: This function swaps the 2 values of the top.
 */
void swap(stack_t **stack, unsigned int line_number)
{
    stack_t *current;
    int new_stack;

    current = *stack;

    if (!current || !(current->next))
    {
        fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
        exit(EXIT_FAILURE);
    }

    new_stack = current->n;
    current->n = current->next->n;
    current->next->n = new_stack;
}

