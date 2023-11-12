#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

/**
 * main - A simple shell program
 *
 * Return: Always 0.
 */
int main(void)
{
	char *input_line = NULL;
	size_t input_length = 0;
	ssize_t input_read;

	while (1)
	{
	printf("($) ");
	input_read = getline(&input_line, &input_length, stdin);

	if (input_read == -1)
	{
	break;
	}

	if (input_read > 1)
		input_line[input_read - 1] = '\0';

		pid_t child_process_id = fork();

		if (child_process_id == -1)
		{
		perror("fork");
		exit(EXIT_FAILURE);
		}
		else if (child_process_id == 0)
		{
		if (execve(input_line, NULL, NULL) == -1)
		{
			perror("execve");
			exit(EXIT_FAILURE);
		}
		}

		else
		{
			int child_status;

			wait(&child_status);
		}
	}
}

	free(input_line);

	return (0);
}
