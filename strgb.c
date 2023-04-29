#include "main.h"

/**
 * _strcpy -function that copies one string to another
 * @post: destination
 * @src: source
 *
 * return: the pointer to  the destination
 */
char *_strcpy(char *pos, char *src)
{
	int f = 0;

	if (pos == src || src == 0)
		return (pos);
	while (src[f])
	{
		post[f] = src[f];
		f++;
	}
	pos[f] = 0;
	return (pos);
}

