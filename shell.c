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

int pasre(char **s, char ***argv, int *status, int *ORing);
/**
 * main - entry function
 * @ac: input
 * @argv: input
 * Return: int
 */
int main(int ac __attribute__((unused)), char **argv)
{
	char *s = NULL;
	size_t  n = 0;
	int isInteravtive = 0;
	int status = 0;
	int ORing = 0;

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
		pasre(&s, &argv, &status, &ORing);
		free(argv);
	} while (1);
	return (0);
}


/**
 * pasre - pasre function
 * @s: input
 * @argv: input
 * @status: input
 * @ORing: input
 * Return: int
 */
int pasre(char **s, char ***argv, int *status, int *ORing)
{
	int pid, j = 0;

	if (contain(*s, '&'))
		*ORing = 1;
	tokenize(&(*argv), &(*s), ";\n");
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
		if (built_in(ptr, *status, argv) != -1)
		{
			free(*ptr);
			free(ptr);
			j++;
			continue;
		}
		pid = fork();
		if (pid == -1)
		{
			free(*ptr);
			free(ptr);
			perror("Error:");
			return (1);
		}
		if (pid == 0)
		{
			exe_CMD(ptr, &(*ORing), *status);
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
	char chunk[1024];
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
