#include "monty.h"

/**
 * push - Pushes an element onto the stack.
 * @stack: Pointer to the pointer of the stack's head
 * @line_number: Line number in the file
 */
void push(stack_t **stack, unsigned int line_number)
{
    int value;
    stack_t *new_node;
    char *arg = strtok(NULL, " \t\n");

    if (arg == NULL || !isdigit(arg[0]) || (arg[0] == '-' && !isdigit(arg[1])))
    {
        fprintf(stderr, "L%u: usage: push integer\n", line_number);
        exit(EXIT_FAILURE);
    }

    value = atoi(arg);
    new_node = malloc(sizeof(stack_t));
    if (new_node == NULL)
    {
        fprintf(stderr, "Error: Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }

    new_node->n = value;
    new_node->prev = NULL;

    if (*stack == NULL)
    {
        new_node->next = NULL;
    }
    else
    {
        new_node->next = *stack;
        (*stack)->prev = new_node;
    }

    *stack = new_node;
}

