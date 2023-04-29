#include "main.h"



/**
 * handel_sigint - function
 * @sig: input
 */
void handel_sigint(int sig __attribute__((unused)))
{
	write(1, "\n", 2);
	write(1, "$ ", _strlen("$ "));
}

int pasre(char **s, char ***argv, int *status, int *ORing, char **av);

/**
 * main - entry function
 * @ac: input
 * @av: input
 * Return: int
 */
int main(int ac __attribute__((unused)), char **av)
{
	char *s = NULL;
	size_t  n = 0;
	int isInteravtive = 0;
	int status = 0;
	int ORing = 0;
	int x_status = 0;
	char **argv = NULL;

	signal(SIGINT, handel_sigint);

	do {
		if (isatty(STDIN_FILENO))
		{
			isInteravtive = 1;
			write(1, "$ ", _strlen("$ "));
		}
		if (_getline(&s, &n, stdin) == -1)
		{
			if (isInteravtive)
				write(1, "\n", 1);
			exit(0);
		}
		pasre(&s, &argv, &status, &ORing, av);
		free(argv);
	} while (1);
	return (x_status);
}

/**
 * get_access - function
 * @ptr: input
 * @av: input
 * Return: int
 */
int get_access(char **ptr, char **av)
{
	char *tmp = NULL, *tmp2 = NULL;
	int i = 0;

	tmp = malloc(sizeof(char) * (_strlen(ptr[0]) + 1));
	_strcpy(tmp, ptr[0]);
	tmp2 = get_PATH(tmp);
	if (tmp2 == NULL)
	{
		free(tmp);
		free(tmp2);
		write_error(ptr[0], av);
		i = 0;
		while (ptr[i])
		{
			free(ptr[i]);
			i++;
		}
		free(ptr);
		return (1);
	}
	if (contain(ptr[0], '/'))
	{
		free(tmp);
	}
	else
	{
		free(tmp);
		free(tmp2);
	}
	return (0);
}



/**
 * pasre - pasre function
 * @s: input
 * @argv: input
 * @status: input
 * @ORing: input
 * @av: input
 * Return: int
 */
int pasre(char **s, char ***argv, int *status, int *ORing, char **av)
{
	int pid, j = 0;

	tokenize(&(*argv), &(*s), "|&;\n");
	while ((*argv)[j])
	{
		char **ptr = NULL;
		int i = 0;

		if (empty_cmd((*argv)[j]))
		{
			free((*argv)[j]);
			j++;
			continue;
		}
		tokenize(&ptr, &(*argv)[j], " \n");
		free((*argv)[j]);
		if (built_in(ptr, *status, &argv) != -1)
		{
			free(*ptr);
			free(ptr);
			j++;
			continue;
		}
		if (get_access(ptr, av))
		{
			j++;
			continue;
		}
		pid = fork();
		if (pid == -1)
		{
			perror("Error:");
			return (1);
		}
		if (pid == 0)
		{
			exe_CMD(ptr, &(*ORing), *status, av);
		}
		else
		{
			wait(&(*status));
		}
		while (ptr[i])
		{
			free(ptr[i]);
			i++;
		}
		free(ptr);
		j++;
	}
	return (0);
}

/**
 * _getline - function
 * @line: input
 * @len: input
 * @fp: input
 * Return: int
 */
int64_t _getline(char **line, size_t *len, FILE *fp)
{
	char chunk[44024];
	ssize_t bytes_read;
	size_t total_bytes_read = 0;

	if (line == NULL || len == NULL)
	{
		perror("Error! Bad arguments.");
		return (-1);
	}
	if (fp == NULL)
	{
		perror("Error! Bad file pointer.");
		return (-1);
	}
	if (*line == NULL)
	{
		*len = sizeof(chunk);
		*line = malloc(*len);
		if (*line == NULL)
		{
			perror("Unable to allocate memory for the line buffer.");
			return (-1);
		}
	}
	(*line)[0] = '\0';
	bytes_read = read(STDIN_FILENO, chunk, sizeof(chunk));
	while (bytes_read > 0)
	{
		total_bytes_read += bytes_read;
		if (total_bytes_read >= *len)
		{
			char *new_line = _realloc(*line, *len, total_bytes_read);
			*len *= 2;
			if (new_line == NULL)
			{
				perror("Unable to reallocate memory for the line buffer.");
				free(*line);
				return (-1);
			}
			*line = new_line;
			free(new_line);
		}
		_strncat(*line, chunk, bytes_read);
		if ((*line)[_strlen(*line) - 1] == '\n')
			return (_strlen(*line));
	}
	if (bytes_read == -1)
	{
		perror("Error reading from file.");
		free(*line);
		return (-1);
	}
	free(*line);
	return (-1);
}
