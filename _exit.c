#include "main.h"
/**
* isExit -  exit built-in
* @value_str: string status
* Return: exit status
*/
int isExit(char *value_str)
{
	int tmp = 0;

	if (!value_str)
	{
		return (0);
	}
	tmp = atoi(value_str);
	if (tmp)
	{
		if (tmp >= 0)
			return (tmp);
		fprintf(stderr, "./hsh: 1: exit: Illegal number: %s\n", value_str);
		return (2);
	}
	return (2);
}
