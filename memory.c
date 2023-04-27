#include "main.h"


/**
 * _realloc - function
 * @ptr: input
 * @old_size: input
 * @new_size: input
 * Return: void *
 */
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	char *p, *old_ptr;

	old_ptr = ptr;

	if (new_size == old_size)
		return (ptr);

	if (ptr == NULL)
		return (malloc(new_size));

	if (ptr != NULL && new_size == 0)
	{
		free(ptr);
		return (NULL);
	}
	p = malloc(new_size);
	if (p == NULL)
	{
		return (NULL);
	}

	if (new_size > old_size)
	{
		_memcpy(p, old_ptr, old_size);
	}
	else
	{
	    _memcpy(p, old_ptr, new_size);
	}

	free(ptr);
	return (p);
}
