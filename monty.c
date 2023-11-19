#include "monty.h"

/**
 * main - Monty Bytecode Interpreter
 * @argc: argument count
 * @argv: argument vector
 * Return: EXIT_SUCCESS on success, EXIT_FAILURE on failure
 */
int main(int argc, char *argv[])
{
    FILE *file;
    char *line = NULL;
    stack_t *stack = NULL;
    unsigned int line_number = 0;
    char *token;

    if (argc != 2)
    {
        fprintf(stderr, "USAGE: monty file\n");
        exit(EXIT_FAILURE);
    }

    file = fopen(argv[1], "r");
    if (file == NULL)
    {
        fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
        exit(EXIT_FAILURE);
    }

    while (fgets(line, MAX_LINE_LENGTH, file) != NULL)
    {
        line_number++;

        token = strtok(line, " \t\n");

        if (token != NULL && strcmp(token, "push") == 0)
        {
            token = strtok(NULL, " \t\n");
            if (token != NULL)
            {
               unsigned int value = atoi(token);
                if (value != 0)
                    push(&stack, value);
                else
                {
            	    fprintf(stderr, "L%d: usage: push integer\n", line_number);
                    exit(EXIT_FAILURE);
                }
            }
        }
        else if (strcmp(token, "pall") == 0)
        {
            pall(&stack, line_number);
        }
	else if (strcmp(token, "pint") == 0)
        {
            pint(&stack, line_number);
        }
        else
        {
            fprintf(stderr, "L%d: unknown instruction %s\n", line_number, token);
            exit(EXIT_FAILURE);
        }
    }

    fclose(file);
    if (line)
        free(line);
    /* Free the stack and any other dynamically allocated memory */

    return (EXIT_SUCCESS);
}
