#include "monty.h"
/**
 *
 * main: monty code interpretor
 * 
 * Return: returns 0 on sucess
 */

int main(void)
{
    char *opcode;

    char buffer[1024];
    stack_t *stack = NULL;
    unsigned int line_number = 0;
    
    /* Read input lines until end of file */
    while (fgets(buffer, sizeof(buffer), stdin) != NULL)
    {
        line_number++;
        opcode = strtok(buffer, " \t\n");
        
        if (opcode == NULL)
            continue;
        
        /* Compare the opcode and call the corresponding function */
        if (strcmp(opcode, "m_push") == 0)
        {
            m_push(&stack, line_number);
        }
        else if (strcmp(opcode, "m_pall") == 0)
        {
            m_pall(&stack, line_number);
        }
        /* Add more opcode handlers as needed */
        else
        {
            fprintf(stderr, "L%u: unknown instruction %s\n", line_number, opcode);
            exit(EXIT_FAILURE);
        }
    }
    
    /* Free memory and perform cleanup */
    while (stack != NULL)
    {
        stack_t *temp = stack;
        stack = stack->next;
        free(temp);
    }
    
    return 0;
}
