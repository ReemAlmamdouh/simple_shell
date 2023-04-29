#include "main.h"

/**
 **_memset - fill the memory with byte
 *@s:  pointer
 *@y: byte
 *@z:  bytes amount
 *return: pointer
 */
char *_memset(char *s, char y, unsigned int z)
{
	unsigned int i;

	for (i = 0; i < z; i++)
		s[i] = y;
	return (s);
}

