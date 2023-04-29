#include "main.h"

/**
 * _mhistory - history list
 * @info:maintain
 *  return: 0
 */
int _mhistory(info_t *info)
{
	print_list(info->history);
	return (0);
}

