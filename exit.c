#include "main.h"

/**
 **_strncpy - copy string
 *@des: destination
 *@src: source
 *@o: characters amount
 *return: string
 */
char *_strncpy(char *des, char *src, int o)
{
	int r, j;
	char *s = des;

	r = 0;
	while (src[r] != '\0' && r < o - 1)
	{
		des[r] = src[r];
		r++;
	}
	if (r < o)
	{
		j = r;
		while (j < o)
		{
			des[j] = '\0';
			j++;
		}
	}
	return (s);
}

