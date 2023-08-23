#include "monty.h"
/**
 *
 */

/* an array of instruction_t for the opcode handlers */
instruction_t opst[] = {

    {"push", m_push}, {"pall", m_pall},
    /* more added here */
};


void execute_opcode(const char *opcode, stack_t **stack, unsigned int line_number)
{
    int i;
    for(i = 0; i < sizeof(opst) / sizeof(opst[0]); i++){
        if(strcmp(opcode, opst[i].opcode) == 0){
            opst[i].f(stack, line_number);
            return;
        }
    }
    fprintf(stderr, "L%u: unknown instructio %s\n", line_number, opcode);
    exit(EXIT_FAILURE);
}
