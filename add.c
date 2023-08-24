#include "monty.h"

/**
 * add - Adds the top two elements of the stack.
 * @stack: A pointer to top of the stack.
 * @line_number: The line number where the add operation is called.
 *
 * Description: This function adds the two values of the top .
 */
void add(stack_t **stack, unsigned int line_number)
{
    
    if (*stack == NULL || (*stack)->next == NULL)
    {
        fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
        exit(EXIT_FAILURE);
    }
    
    (*stack)->next->n += (*stack)->n; 
    pop(stack, line_number); 
}
