#include "main.h"

/**
 * _strlen - string length
 * @t: string
 *
 * return: leng of string
 */
int _strlen(char *t)
{
	int j = 0;

	if (!t)
		return (0);

	while (*t++)
		j++;
	return (j);
}

