#include "main.h"

/**
 * _memcpy - function
 * @dest: input
 * @src: input
 * @n: input
 * Return: void *
 */
char *_memcpy(char *dest, char *src, unsigned int n)
{
	unsigned int i;

	for (i = 0; i < n; i++)
		dest[i] = src[i];
	return (dest);
}


/**
 * _strncat - function
 * @dest: input
 * @src: input
 * @n: input
 * Return: void *
 */
char *_strncat(char *dest, const char *src, size_t n)
{
	size_t dest_len = _strlen(dest);
	size_t i;

	for (i = 0; i < n && src[i] != '\0'; i++)
		dest[dest_len + i] = src[i];

	dest[dest_len + i] = '\0';
	return (dest);
}

/**
 * _strlen - function
 * @str: input
 * Return: size
 */
size_t _strlen(const char *str)
{
	size_t length = 0;

	while (*str != '\0')
	{
		length++;
		str++;
	}
	return (length);
}

/**
 * _strcat - function
 * @dest: input
 * @src: input
 * Return: char *
 */
char *_strcat(char *dest, const char *src)
{
	char *ptr = dest + _strlen(dest);

	while (*src != '\0')
	{
		*ptr++ = *src++;
	}
	*ptr = '\0';
	return (dest);
}


/**
 * _strcmp - function
 * @str1: input
 * @str2: input
 * Return: int
 */
int _strcmp(const char *str1, const char *str2)
{
	while (*str1 != '\0' || *str2 != '\0')
	{
		if (*str1 < *str2)
		{
			return (-1);
		}
		else if (*str1 > *str2)
		{
			return (1);
		}
		str1++;
		str2++;
	}
	return (0);
}
