#include "main.h"


/**
 * _strncmp - function
 * @str1: input
 * @str2: input
 * @n: input
 * Return: n
 */
int _strncmp(const char *str1, const char *str2, size_t n)
{
	size_t i;

	for (i = 0; i < n; i++)
	{
		if (str1[i] < str2[i])
		{
			return (-1);
		}
		else if (str1[i] > str2[i])
		{
			return (1);
		}
		else if (str1[i] == '\0')
		{
			return (0);
		}
	}
	return (0);
}

/**
 * _strcpy - function
 * @dest: input
 * @src: input
 * Return: char *
 */
char *_strcpy(char *dest, const char *src)
{
	char *p = dest;

	while (*src != '\0')
	{
		*p++ = *src++;
	}
	*p = '\0';
	return (dest);
}


/**
 * _strdup - function
 * @str: input
 * Return: char *
 */
char *_strdup(char *str)
{
	unsigned int i;
	unsigned int len = 0;
	char *p;

	if (str == NULL)
		return (NULL);

	while (str[len] != '\0')
	{
		len++;
	}

	p = (char *)malloc((++len) * sizeof(*str));

	if (p == NULL)
		return (NULL);

	for (i = 0; i < len; i++)
	{
		p[i] = str[i];
	}
	return (p);
}


/**
 * _atoi - function
 * @s: input
 * Return: int
 */
int _atoi(char *s)
{
	int i, d, n, len, f, digit;

	i = 0;
	d = 0;
	n = 0;
	len = 0;
	f = 0;
	digit = 0;

	while (s[len] != '\0')
		len++;

	while (i < len && f == 0)
	{
		if (s[i] == '-')
			++d;

		if (s[i] >= '0' && s[i] <= '9')
		{
			digit = s[i] - '0';
			if (d % 2)
				digit = -digit;
			n = n * 10 + digit;
			f = 1;
			if (s[i + 1] < '0' || s[i + 1] > '9')
				break;
			f = 0;
		}
		i++;
	}

	if (f == 0)
		return (0);

	return (n);
}
