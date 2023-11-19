#include "monty.h"

/**
 * push - Pushes an element to the top of the stack
 * @stack: Double pointer to the beginning of the stack
 * @value: Value to be pushed onto the stack
 */
void push(stack_t **stack, int value)
{
    stack_t *new_node;

    /* Allocate memory for the new node */
    new_node = malloc(sizeof(stack_t));
    if (new_node == NULL)
    {
        fprintf(stderr, "Error: malloc failed\n");
        exit(EXIT_FAILURE);
    }

    /* Initialize the new node */
    new_node->n = value;
    new_node->prev = NULL;

    /* Update links to make the new node the top of the stack */
    if (*stack != NULL)
    {
        new_node->next = *stack;
        (*stack)->prev = new_node;
    }
    else
    {
        new_node->next = NULL;
    }

    *stack = new_node;
}
