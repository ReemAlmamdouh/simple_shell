#include "main.h"

void bulitin_exit(char ***cmd, char ****argv);

/**
 * built_in - function
 * @cmd: input
 * @status: input
 * @argv: input
 * Return: int
 */
int built_in(char **cmd, int status, char ****argv)
{
	char *str =  NULL;

	if (cmd[0] == NULL)
		return (-1);
	if (_strcmp(cmd[0], "exit") == 0)
	{
		bulitin_exit(&cmd, argv);
	}
	str = malloc(sizeof(char) * (_strlen(*cmd) + 1));
	if (_strcmp(cmd[0], "$?") == 0)
	{
		int_to_str(&(*str), status);
		printf("%ld\n", _strlen(str));
		printf("%s\n", str);
		write(1, str, _strlen(str) - 1);
		write(1, "\n", 1);
	}
	else if (_strcmp(cmd[0], "$$") == 0)
	{
		int_to_str(&(*str), getpid());
		printf("%ld\n", _strlen(str));
		write(1, str, _strlen(str) - 1);
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


/**
 * bulitin_exit - function
 * @cmd: input
 * @argv: input
 */
void bulitin_exit(char ***cmd, char ****argv)
{
	int i = 0;

	if ((*cmd)[1] != NULL)
	{
		int exit_number = _atoi((*cmd)[1]);

		while (cmd[i])
		{
			free(cmd[i]);
			i++;
		}
		free(cmd);
		exit(exit_number);
	}
	while ((*cmd)[i])
	{
		free((*cmd)[i]);
		i++;
	}
	free(*cmd);
	free(**argv);
	exit(0);
}
