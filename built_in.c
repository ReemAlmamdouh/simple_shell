#include "main.h"


/**
 * built_in - function
 * @cmd: input
 * @status: input
 * Return: int
 */
int built_in(char **cmd, int status)
{
	char *str =  NULL;

	if (_strcmp(cmd[0], "exit") == 0)
	{
		if (cmd[1] != NULL)
		{
			int exit_number = _atoi(cmd[1]);

			free(cmd);
			exit(exit_number);
		}
		free(cmd);
		exit(1);
	}
	str = malloc(sizeof(char) * (_strlen(*cmd) + 1));
	if (_strcmp(cmd[0], "$?") == 0)
	{
		int_to_str(&(*str), status);
		write(1, str, _strlen(str));
		write(1, "\n", 1);
	}
	else if (_strcmp(cmd[0], "$$") == 0)
	{
		int_to_str(&(*str), getpid());
		write(1, str, _strlen(str));
		write(1, "\n", 1);
	}
	else if (_strcmp(cmd[0], "unsetenv") == 0)
	{
		if (cmd[1] != NULL)
			_unsetenv(cmd[1]);
	}
	else
	{
		free(str);
		return (-1);
	}
	free(str);
	return (1);
}
