#include "main.h"

/**
 * exe_CMD - function
 * @cmd: input
 * @env: input
 * @ORing: input
 * @status: input
 * Return: int
 */
int exe_CMD(char **cmd, char **env, int *ORing, int status)
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
		exit_status = execve(cmd_name, cmd, env);
		if (exit_status == -1)
		{
			*ORing = 2;
			perror("Error:");
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
