#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>


extern char **environ;

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
int exe_CMD(char **cmd, int *ORing, int status);
int built_in(char **cmd, int status);
int empty_cmd(char *str);

#endif
