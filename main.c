#include "monty.h"
/**
 *
 * main: monty code interpretor
 * 
 * Return: returns 0 on sucess
 */

int main(int argc, char *argv[])
{
    /* had to declare here because of compilation problems */
    char buffer[1024];
    stack_t *stack;
    unsigned int line_number;
    char *opcode;
    FILE *file;

    if (argc != 2)
    {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        return EXIT_FAILURE;
    }

    file = fopen(argv[1], "r");
    if (file == NULL)
    {
        fprintf(stderr, "Error: Unable to open file %s\n", argv[1]);
        return EXIT_FAILURE;
    }

    stack = NULL;
    line_number = 0;

    while (fgets(buffer, sizeof(buffer), file) != NULL)
    {
        line_number++;
        opcode = strtok(buffer, " \t\n");

        if (opcode == NULL)
            continue;

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
            fclose(file);
            exit(EXIT_FAILURE);
        }
    }

    fclose(file);

    /* Free memory and perform cleanup */
    while (stack != NULL)
    {
        stack_t *temp = stack;
        stack = stack->next;
        free(temp);
    }

    return 0;
}
