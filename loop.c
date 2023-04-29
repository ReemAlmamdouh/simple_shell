#include "main.h"

/**
 * hsh - shell
 * @info: parameter input
 * @av: argument vector
 *
 * return: 0 on success, 1 on failure
 */
Int hsh(info_t *info, char **av)
{
	ssize_t a = 0;
	int c = 0;

	while (a != -1 && blt_r != -2)
	{
		clear_info(info);
		if (reactive(info))
			_puts("$ ");
		_iputchar(BUF_FLUSH);
		a = get_input(info);
		if (a != -1)
		{
			set_info(info, av);
			blt_r = search_bltn(info);
			if (blt_r == -1)
				search_cmd(info);
		}
		else if (reactive(info))
			_putchar('\n');
		free_info(info, 0);
	}
	write_history(info);
	free_info(info, 1);
	if (!reactive(info) && info->note)
		exit(info->note);
	if (blt_r == -2)
	{
		if (info->error_m == -1)
			exit(info->note);
		exit(info->error_m);
	}
	return (blt_r);
}

