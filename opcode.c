#include "monty.h"

/**
 * push - Pushes an element to the top of the stack
 * @stack: Double pointer to the beginning of the stack
 * @value: Value to be pushed onto the stack
 */
void push(stack_t **stack, unsigned int value)
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

/**
 * pall - Prints all the values on the stack
 * @stack: Double pointer to the beginning of the stack
 * @line_number: Line number in the Monty bytecode file
 */
void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *current = *stack;

	(void)line_number; /* Unused parameter, suppress compiler warning */

	while (current != NULL)
	{
		printf("%d\n", current->n);
		current = current->next;
	}
}
/**
 * pint -  prints the value at the top of the stack
 * @stack: Double pointer to the beginning of the stack
 * @line_number: Line number in the Monty bytecode file
 */
void pint(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL)
    {
        fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
        exit(EXIT_FAILURE);
    }

    printf("%d\n", (*stack)->n);
}
/**
 * pop - Removes the top element of the stack
 * @stack: Double pointer to the beginning of the stack
 * @line_number: Line number in the Monty bytecode file
 */
void pop(stack_t **stack, unsigned int line_number)
{
    stack_t *temp;

    if (*stack == NULL)
    {
        fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
        exit(EXIT_FAILURE);
    }

    temp = *stack;

    if ((*stack)->next != NULL)
    {
        *stack = (*stack)->next;
        (*stack)->prev = NULL;
    }
    else
    {
        *stack = NULL;
    }

    free(temp);
}
