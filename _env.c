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
		write(STDOUT_FILENO, env[i], strlen(env[i]));
		write(STDOUT_FILENO, "\n", 1);
		i++;
	}
}
