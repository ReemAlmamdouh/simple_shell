#ifndef _SHELL_H_
#define _SHELL_H_

#include <errno.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/wait.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <limits.h>



/* prototypes for buffer */
#define READ_BUF_SIZE 1024
#define WRITE_BUF_SIZE 1024
#define BUF_FLUSH -1

/* chaining prototypes */
#define CMD_NORM	0
#define CMD_OR		1
#define CMD_AND		2
#define CMD_CHAIN	3

/* convert a string to an integer */
#define CONVERT_LOWERCASE	1
#define CONVERT_UNSIGNED	2

/* read lines from a file or stream */
#define USE_GETLINE 0
#define USE_STRTOK 0

#define HIST_FILE	".simple_shell_history"
#define HIST_MAX	4096

extern char **environ;


<<<<<<< HEAD
/**
 * struct lister - single liked lists
 * @f: the number field
 * @str: string
 * @next: the next node
 */
typedef struct lister
{
	int f;
	char *str;
	struct lister *next;
} list_t;

/**
 *struct passer - pseudo-arguements 
 *@path: string path 
 *@arg: argument string
 *@argv:  array of strings from arg
 *@argc: argument count
 *@error_m: exit() error code
 *@flag_count: counts line of input
 *@fname: filename
 *@line_count: the error count
 *@env: copy of environ
 *@environ:  modified copy of environ 
 *@alias: the alias node
 *@change_env: if environ changes
 *@history: the history node
 *@note:  return status of executed command
 *@cmd_buf: the address of pointer to cmd_buf
 *@fd_read:  to read line input with fd
 *@count_h: count of history line
 *@cmd_buf_type: &&m, CMD_type ||;
 */
typedef struct passer
{
	char *arg;
	char **argv;
	char *path;
	int argc;
	unsigned int line_count;
	int error_m;
	int flag_count;
	char *fname;
	list_t *env;
	list_t *history;
	list_t *alias;
	char **environ;
	int change_env;
	int note;

	char **cmd_buf; 
	int cmd_buf_type; 
	int fd_read;
	int count_h;
} info_t;

#define INFO_INIT \
{NULL, NULL, NULL, 0, 0, 0, 0, NULL, NULL, NULL, NULL, NULL, 0, 0, NULL, \
	0, 0, 0}

/**
 *struct built_in -  built_in strings & functions
 *@type:  built_in command flag
 *@func: function
 */
typedef struct built_in
{
	char *type;
	int (*func)(info_t *);
} builtin_table;


/* loop.c */
int hsh(info_t *, char **);
int find_builtin(info_t *);
void find_cmd(info_t *);
void fork_cmd(info_t *);

/* path.c */
int is_cmd(info_t *, char *);
char *dup_chars(char *, int, int);
char *find_path(info_t *, char *, char *);

/* loop_sh.c */
int loophsh(char **);

/* error.c */
void _eputs(char *);
int _eputchar(char);
int _putfd(char c, int fd);
int _putsfd(char *str, int fd);

/* string.c */
int _strlen(char *);
int _strcmp(char *, char *);
char *starts_with(const char *, const char *);
char *_strcat(char *, char *);

/* stringa.c */
char *_strcpy(char *, char *);
char *_strdup(const char *);
void _puts(char *);
int _putchar(char);

/* exit.c */
char *_strncpy(char *, char *, int);
char *_strncat(char *, char *, int);
char *_strchr(char *, char);

/* token.c */
char **strtow(char *, char *);
char **strtow2(char *, char);

/* redist.c*/
char *_memset(char *, char, unsigned int);
void ffree(char **);
void *_realloc(void *, unsigned int, unsigned int);

/* memory.c */
int bfree(void **);

/* info.c */
int interactive(info_t *);
int is_delim(char, char *);
int _isalpha(int);
int _atoi(char *);

/* errora.c */
int _erratoi(char *);
void print_error(info_t *, char *);
int print_d(int, int);
char *convert_number(long int, int, int);
void remove_comments(char *);

/* built.c */
int _myexit(info_t *);
int _mycd(info_t *);
int _myhelp(info_t *);

/* builta.c */
int _myhistory(info_t *);
int _myalias(info_t *);

/*get_line.c */
ssize_t get_input(info_t *);
int _getline(info_t *, char **, size_t *);
void sigintHandler(int);

/* get_info.c */
void clear_info(info_t *);
void set_info(info_t *, char **);
void free_info(info_t *, int);

/* get_env.c*/
char *_getenv(info_t *, const char *);
int _myenv(info_t *);
int _mysetenv(info_t *);
int _myunsetenv(info_t *);
int populate_env_list(info_t *);

/* env.c */
char **get_environ(info_t *);
int _unsetenv(info_t *, char *);
int _setenv(info_t *, char *, char *);

/* hist.c */
char *get_history_file(info_t *info);
int write_history(info_t *info);
int read_history(info_t *info);
int build_history_list(info_t *info, char *buf, int linecount);
int renumber_history(info_t *info);

/*list.c */
list_t *add_node(list_t **, const char *, int);
list_t *add_node_end(list_t **, const char *, int);
size_t print_list_str(const list_t *);
int delete_node_at_index(list_t **, unsigned int);
void free_list(list_t **);

/* lista.c */
size_t list_len(const list_t *);
char **list_to_strings(list_t *);
size_t print_list(const list_t *);
list_t *node_starts_with(list_t *, char *, char);
ssize_t get_node_index(list_t *, list_t *);

/* chain.c*/
int is_chain(info_t *, char *, size_t *);
void check_chain(info_t *, char *, size_t *, size_t, size_t);
int replace_alias(info_t *);
int replace_vars(info_t *);
int replace_string(char **, char *);
=======
int _atoi(char *s);
char *_strdup(char *str);
char *_strcpy(char *dest, const char *src);
int _strncmp(const char *str1, const char *str2, size_t n);
int _strcmp(const char *str1, const char *str2);
char *_strcat(char *dest, const char *src);
size_t _strlen(const char *str);
char *_strncat(char *dest, const char *src, size_t n);
char *_memcpy(char *dest, char *src, unsigned int n);
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);
size_t _strcspn(const char *str, const char *reject);
unsigned int _strspn(char *s, const char *accept);
char *_strtok(char *str, const char *delim);
int64_t _getline(char **line, size_t *len, FILE *fp);
char *_getenv(const char *str);
char *get_PATH(char *cmd);
char *_strchr(const char *s, int c);
int _unsetenv(const char *name);
int contain(char *portion, char character);
void int_to_str(char *str, int num);
void tokenize(char ***argv, char **s, char d[]);
void remove_char(char *str, char c);
void echo_dollor(char **cmd, int status);
int exe_CMD(char **cmd, int *ORing, int status, char **av);
int built_in(char **cmd, int status, char ****argv);
int write_error(char *error, char **av);
int empty_cmd(char *str);
>>>>>>> 9c4bc60bd4f45d61b399f4953bb9601faff14a41

#endif

