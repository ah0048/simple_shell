#include "main.h"
/**
* _env - print current environment
* Return: void
*/
void _env(void)
{
	char **env = environ;
	while (*env)
	{
		printf("%s\n", *env);
		env++;
	}
}
