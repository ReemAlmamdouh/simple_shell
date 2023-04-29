#include "main.h"

/**
 * _maenv - to print current env
 * @info: maintains
 * return: 0
 */
int _maenv(info_t *info)
{
	print_list_str(info->env);
	return (0);
}

