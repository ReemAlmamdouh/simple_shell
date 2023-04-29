#include "main.h"

/**
 * this_chain - funtion to test if the current char is a chain
 * @info: parameter
 * @buf: buffer
 * @pt: position
 *
 * return: 1 if the chain delimeter & 0 otherwise
 */
int this_chain(info_t *info, char *buf, size_t *pt)
{
	size_t l = *pt;

	if (buf[l] == '|' && buf[l + 1] == '|')
	{
		buf[l] = 0;
		l++;
		info->cmd_buf_type = CMD_OR;
	}
	else if (buf[l] == '&' && buf[l + 1] == '&')
	{
		buf[l] = 0;
		l++;
		info->cmd_buf_type = CMD_AND;
	}
	else if (buf[l] == ';') /* end of command */
	{
		buf[l] = 0;
		info->cmd_buf_type = CMD_CHAIN;
	}
	else
		return (0);
	*pt = l;
	return (1);
}

