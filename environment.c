#include "main.h"

/**
 * _unsetenv - function
 * @name: input
 * Return: int
 */
int _unsetenv(const char *name)
{
	size_t name_len = _strlen(name);
	char **p = environ;

	if (name == NULL || name[0] == '\0' || _strchr(name, '=') != NULL)
	{
		return (-1);
	}

	while (*p != NULL)
	{
		if (_strncmp(*p, name, name_len) == 0 && (*p)[name_len] == '=')
		{
			char **next = p + 1;

			while (*next != NULL)
			{
				*(next - 1) = *next;
				next++;
			}
			*(next - 1) = NULL;
			return (0);
		}
		p++;
	}
	return (0);
}

/**
 * get_PATH - function
 * @cmd: input
 * Return: char *
 */
char *get_PATH(char *cmd)
{
	char *PATH, *path_tmp, *tokenize, *fpath;
	int len = 0, dir_len;
	struct stat buf;

	if (contain(cmd, '/'))
		return (cmd);
	PATH = _getenv("PATH");
	if (PATH != NULL)
	{
		if (cmd)
			len = _strlen(cmd);
		path_tmp = _strdup(PATH);
		tokenize = _strtok(path_tmp, ":");
		while (tokenize != NULL)
		{
			dir_len = _strlen(tokenize);
			fpath = malloc(len + dir_len + 2);
			_strcpy(fpath, tokenize);
			_strcat(fpath, "/");
			_strcat(fpath, cmd);
			_strcat(fpath, "\0");
			if (stat(fpath, &buf) != 0)
			{
				free(fpath);
				tokenize = _strtok(NULL, ":");
			}
			else
			{
				free(path_tmp);
				return (fpath);
			}
		}
		free(path_tmp);
		if (stat(cmd, &buf) != 0)
			return (NULL);
		return (cmd);
	}
	return (NULL);
}


/**
 * _getenv - function
 * @str: input
 * Return: char *
 */
char *_getenv(const char *str)
{
	char **env = NULL;
	size_t str_len = _strlen(str);

	for (env = environ; *env != NULL; env++)
	{
		if (_strncmp(*env, str, str_len) == 0 && (*env)[str_len] == '=')
		{
			return (&(*env)[str_len + 1]);
		}
	}
	return (NULL);
}
