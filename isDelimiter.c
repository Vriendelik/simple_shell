#include "shell.h"

/**
 * isDelimiter - checks if a character is a delimiter
 * @c: the character to check
 * @delim: the delimiter string
 *
 * Return: 1 if true, 0 if false
 */
int isDelimiter(char c, char *delim)
{
	while (*delim)
	if (*delim++ == c)
	return (1);
	return (0);
}
