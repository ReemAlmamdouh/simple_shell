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

		free(*cmd);
		exit(exit_number);
	}
	while ((*cmd)[i])
	{
		free((*cmd)[i]);
		i++;
	}
	free(*cmd);
	free(**argv);
	/*printf("%s --> %ld\n",**cmd, sizeof(**cmd));
	printf("%s --> %ld\n",(*cmd)[0], sizeof((*cmd)[0]));
	printf("%s --> %ld\n",***argv, sizeof(***argv));
	printf("%s --> %ld\n",(**argv)[1], sizeof((**argv[1])));*/
	exit(0);
}
