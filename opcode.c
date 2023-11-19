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
/**
 * swap - Swaps the top two elements of the stack
 * @stack: Double pointer to the beginning of the stack
 * @line_number: Line number in the Monty bytecode file
 */
void swap(stack_t **stack, unsigned int line_number)
{
    stack_t *temp;

    if (*stack == NULL || (*stack)->next == NULL)
    {
        fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
        exit(EXIT_FAILURE);
    }

    temp = (*stack)->next;
    (*stack)->next = temp->next;
    temp->prev = NULL;
    temp->next = *stack;
    (*stack)->prev = temp;

    *stack = temp;
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
