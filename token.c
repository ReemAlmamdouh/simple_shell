#include "main.h"

/**
 * **spl - function that splits the string
 * @rst: string
 * @f: input
 * return: pointer or 0
 */

char **spl(char *rst, char *f)
{
	int q, w, k, m, numwords = 0;
	char **s;

	if (rst == NULL || rst[0] == 0)
		return (NULL);
	if (!f)
		f = " ";
	for (q = 0; rst[q] != '\0'; q++)
		if (!this_dem(rst[q], f) && (this_dem(rst) || !rst[q + 1]))
			numwords++;

	if (numwords == 0)
		return (NULL);
	s = malloc((1 + numwords) * sizeof(char *));
	if (!s)
		return (NULL);
	for (q = 0, w = 0; w < numwords; w++)
	{
		while (this_dem(rst[q], f))
			q++;
		k = 0;
		while (!this_dem(rst[q + k], f) && rst[q + k])
			k++;
		s[w] = malloc((k + 1) * sizeof(char));
		if (!s[w])
		{
			for (k = 0; k < w; k++)
				free(s[k]);
			free(s);
			return (NULL);
		}
		for (m = 0; m < k; m++)
			s[w][m] = rst[i++];
		s[w][m] = 0;
	}
	s[w] = NULL;
	return (s);
}

