#include "main.h"
/**
* _env - print current environment
* Return: void
*/
void _env(void)
{
	extern char **environ;
	char **env;
	int i = 0;
	if (!environ)
		return;
	env = environ;
	while (env[i])
	{
		printf("%s\n", env[i]);
		i++;
	}
}
