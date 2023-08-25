#include "monty.h"
/**
 *
 * sub: subtracts the top element of the stack from the second top element
 * @stack: A pointer to the top of the stack
 * @line: number: the line number in the script where the sub operation is called
 */
void sub(stack_t **stack, unsigned int line_number){
    
    stack_t *current = *stack;
    int result;

    if(!current || !current->next){
        fprintf(stderr, "L%d: can't sub, stack too short\n", line_number);
        exit(EXIT_FAILURE);
    }

    result = current->next->n - current->n;

    /* Pop the element on top from from the stack */
    *stack = current->next;
    if(current->next)
        current->next->prev = NULL;
    free(current);

    /* Update the new top element with the result */
    (*stack)->n = result;
}

