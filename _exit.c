#include "main.h"
/**
* isExit -  exit built-in
* @value_str: string status
* Return: exit status
*/
int isExit(char *value_str)
{
	int tmp = 0;

	char *ptr;

	if (!value_str)
	{
		return (0);
	}
	tmp = strtol(value_str, &ptr, 10);
	if (*ptr != '\0')
	{
		fprintf(stderr, "./hsh: 1: exit: Illegal number: %s\n", value_str);
		return (2);
	}
	if (tmp)
	{
		if (tmp >= 0)
			return (tmp);
		fprintf(stderr, "./hsh: 1: exit: Illegal number: %s\n", value_str);
		return (2);
	}
	return (2);
}
