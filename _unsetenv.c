#include "main.h"
/**
* _unsetenv - removes an environment variable.
* @name: name of env var
* Return: void
*/
void _unsetenv(char *name)
{
	int i = 0, len = 0;

	len = strlen(name);
	while (environ[i])
	{
		if (strncmp(environ[i], name, len) == 0)
		{
				free(environ[1]);
				return;
		}
		i++;
	}
}
