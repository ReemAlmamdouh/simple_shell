#include "main.h"

/**
 * get_environ - returns string array copy
 * @info:  maintain
 * return: 0
 */
char **get_environ(info_t *info)
{
	if (!info->environ || info->chang_env)
	{
		info->environ = list_to_strings(info->env);
		info->chang_env = 0;
	}

	return (info->environ);
}

