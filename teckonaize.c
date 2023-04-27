#include "main.h"

/**
 * tokenize - function
 * @argv: input
 * @s: input
 * @d: input
 */
void tokenize(char ***argv, char **s, char d[])
{
	char *token_tmp = _strdup(*s), *portion = _strtok(*s, d);
	int argc = 0, i = 0;

	while (portion != NULL)
	{
		argc++;
		portion = _strtok(NULL, d);
	}
	*argv = malloc(sizeof(char *) * (argc + 1));
	if (*argv == NULL)
	{
		free(*argv);
		free(token_tmp);
		perror("tsh: memory allocation error");
		exit(98);
	}
	for (i = 0; i < argc; i++)
	{
		(*argv)[i] = malloc(sizeof(char) * (_strlen(token_tmp) + 1));
		if ((*argv)[i] == NULL)
		{
			free(*argv);
			free(token_tmp);
			perror("tsh: memory allocation error");
			exit(98);
		}
	}
	portion = _strtok(token_tmp, d);
	i = 0;
	while (portion != NULL)
	{
		if (portion[0] == '#')
			break;
		_strcpy((*argv)[i], portion);
		portion = _strtok(NULL, d);
		i++;
	}
	(*argv)[i] = NULL;
	free(token_tmp);
}

/**
 * _strtok - function
 * @str: input
 * @delim: input
 * Return: char *
 */
char *_strtok(char *str, const char *delim)
{
	static char *l_str;
	char *token;

	if (str != NULL)
		l_str = str;

	if (l_str == NULL || *l_str == '\0')
		return (NULL);

	token = l_str + _strspn(l_str, delim);
	if (*token == '\0')
	{
		l_str = NULL;
		return (NULL);
	}
	l_str = token + _strcspn(token, delim);

	if (*l_str != '\0')
		*l_str++ = '\0';

	return (token);
}
