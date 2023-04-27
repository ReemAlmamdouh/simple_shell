#include "main.h"

/**
 * int_to_str - function
 * @str: input
 * @num: input
 */
void int_to_str(char *str, int num)
{
	char buffer[12];
	char *p = buffer;
	int is_negative = 0;

	if (num == 0)
	{
		*str++ = '0';
		*str = '\0';
		return;
	}
	if (num < 0)
	{
		is_negative = 1;
		num = -num;
	}

	while (num > 0)
	{
		*p++ = num % 10 + '0';
		num /= 10;
	}
	if (is_negative)
	{
		*p++ = '-';
	}
	*p-- = '\0';

	while (p >= buffer)
		*str++ = *p--;
}

/**
 * contain - function
 * @portion: input
 * @character: input
 * Return: int
 */
int contain(char *portion, char character)
{
	int i;

	for (i = 0; portion[i]; i++)
	{
		if (portion[i] == character)
			return (1);
	}
	return (0);
}



/**
 * _strchr - function
 * @s: input
 * @c: input
 * Return: char *
 */
char *_strchr(const char *s, int c)
{
	while (*s != '\0')
	{
		if (*s == c)
		{
			return ((char *)s);
		}
		s++;
	}

	if (c == '\0')
	{
		return ((char *)s);
	}
	return (NULL);
}


/**
 * _strspn - function
 * @s: input
 * @accept: input
 * Return: int
 */
unsigned int _strspn(char *s, const char *accept)
{
	unsigned int i, j;

	for (i = 0; s[i] != '\0'; i++)
	{
		for (j = 0; accept[j] != '\0'; j++)
		{
			if (s[i] == accept[j])
				break;
		}
		if (accept[j] == '\0')
			return (i);
	}
	return (i);
}

/**
 * _strcspn - function
 * @str: input
 * @reject: input
 * Return: size_t
 */
size_t _strcspn(const char *str, const char *reject)
{
	const char *p, *q;

	for (p = str; *p != '\0'; p++)
	{
		for (q = reject; *q != '\0'; q++)
		{
			if (*p == *q)
			{
				return (p - str);
			}
		}
	}
	return (p - str);
}
