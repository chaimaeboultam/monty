#include "monty.h"

/**
 * add - Adds the top two elements of the stack
 * @stack: Double pointer to the beginning of the stack
 * @line_number: Line number in the Monty bytecode file
 */
void add(stack_t **stack, unsigned int line_number)
{
    stack_t *temp;

    if (*stack == NULL || (*stack)->next == NULL)
    {
        fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
        exit(EXIT_FAILURE);
    }

    (*stack)->next->n += (*stack)->n;  
    temp = *stack;  
    *stack = (*stack)->next;  
    (*stack)->prev = NULL;  
   free(temp);  
}
/**
 * nop - Does nothing
 * @stack: Double pointer to the beginning of the stack
 * @line_number: Line number in the Monty bytecode file
 */
void nop(stack_t **stack, unsigned int line_number)
{
    (void)stack;
    (void)line_number;
    /* This opcode does nothing */
}
