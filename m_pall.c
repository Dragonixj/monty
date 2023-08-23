#include "monty.h"
/**
 * pall: prints all the values on the stack
 * @stack: Pointer to the pointer of the stacks head
 * @line_number: line number in the file(not used in this function though)
 *
 * Return: no return value
 */

void pall(stack_t **stack, unsigned int line_number){

    stack_t *current;

    (void)line_number; /* introduced just to silence compile warning */

    current = *stack;

    if(current == NULL)
        return;
    while(current != NULL){
        printf("%d\n", current->n);
        current = current->next;
    }
}
