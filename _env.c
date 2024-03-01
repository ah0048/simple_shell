#include "main.h"
/**
* _env - print current environment
* Return: void
*/
void _env(void)
{
	char **env;
	int i = 0;
	env = environ;
	if (!environ)
		return;
	while (env[i])
	{
		printf("%s\n", env[i]);
		i++;
	}
}
