#include "main.h"

/**
 * write_error - function
 * @error: input
 * @av: input
 * Return: int
 */
int write_error(char *error, char **av)
{
	char *command = error;
	char *shell = (av)[0];
	char *error_message = _strdup(shell);
	int error_message_length = _strlen(shell);

	error_message = _realloc(error_message, _strlen(shell), 50);
	_memcpy(error_message + error_message_length, ": 1: ", 5);

	error_message_length += 5;
	_memcpy(error_message + error_message_length, command, _strlen(command));

	error_message_length += _strlen(command);
	_memcpy(error_message + error_message_length, ": not found\n", 12);

	error_message_length += 12;
	write(STDERR_FILENO, error_message, error_message_length);
	free(error_message);
	return (1);
}
/**
 * exe_CMD - function
 * @cmd: input
 * @ORing: input
 * @status: input
 * @av: input
 * Return: int
 */
int exe_CMD(char **cmd, int *ORing, int status, char **av)
{
	char *cmd_name = NULL;
	int exit_status;
	size_t i = 0;

	while (cmd[i])
	{
		if (cmd[i][0] == '$')
		{
			echo_dollor(&cmd[i], status);
		}
		i++;
	}

	if (cmd)
	{
		cmd_name = get_PATH(cmd[0]);
		exit_status = execve(cmd_name, cmd, environ);
		if (exit_status == -1)
		{
			*ORing = 2;
			write_error(cmd[0], av);
			free(cmd);
			exit(1);
		}
	}
	return (exit_status);
}


/**
 * echo_dollor - function
 * @cmd: input
 * @status: input
 */
void echo_dollor(char **cmd, int status)
{
	if (_strcmp(*cmd, "$?") == 0)
	{
		int_to_str(&(**cmd), status);
	}
	else if (_strcmp(*cmd, "$$") == 0)
	{
		int_to_str(&(**cmd), getpid());
	}
	else
	{
		char *PATH;
		char *tmp = _strdup(*cmd);

		remove_char(&(**cmd), '$');
		PATH = _getenv(*cmd);
		if (PATH)
		{
			*cmd = PATH;
		}
		else
		{
			*cmd = tmp;
			free(tmp);
		}
	}
}


/**
 * remove_char - function
 * @str: input
 * @c: input
 */
void remove_char(char *str, char c)
{
	int i, j;
	int len = _strlen(str);

	for (i = 0, j = 0; i < len; i++)
	{
		if (str[i] != c)
		{
			str[j++] = str[i];
		}
	}
	str[j] = '\0';
}
