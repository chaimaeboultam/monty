#include "monty.h"

/*
 * main: monty bytcode interpreter
 * @argc: argument vector
 * @argv: argument count
 *
 * Return: EXIT_SUCCESS on success , EXIT_FAILURE on failure
 */
int main(int *argc, ichar *argv[])
{
	FILE *file;
	char line[MAX_LENGTH];
	size_t len =0;
	stack_t *stack = NULL;
	unsigned int line-number=0;
	size_t nread;
	file = fopen(arg[1],"r");
	fgets(line , MAX_LENGTH, file);


	
	char *token = strtok(line, '\t\n');

}
