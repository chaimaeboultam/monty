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

    (*stack)->next->n += (*stack)->n;  // Add the top two elements
    temp = *stack;  // Save the current top element
    *stack = (*stack)->next;  // Move the stack pointer to the second element
    (*stack)->prev = NULL;  // Update the prev pointer of the new top element
    free(temp);  // Free the old top element
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
