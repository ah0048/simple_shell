#include "main.h"
/**
* _setenv - sets a new value for an environment variable.
* @name: name of env var
* @value: value of env var
* @overwrite: 0 or 1
* Return: void
*/
void _setenv(char *name, char *value, int overwrite)
{
	int i = 0, len = 0;

	char *new_var;

	len = strlen(name);
	while (environ[i])
	{
		if (strncmp(environ[i], name, len) == 0)
		{
			if (overwrite)
			{
				new_var = malloc(strlen(name) + strlen(value) + 2);
				strcpy(new_var, name);
				strcat(new_var, "=");
				strcat(new_var, value);
				free(environ[1]);
				environ[i] = new_var;
				return;
			}
			return;
		}
		i++;
	}
	new_var = malloc(strlen(name) + strlen(value) + 2);
	strcpy(new_var, name);
	strcat(new_var, "=");
	strcat(new_var, value);
	environ = realloc(environ, (i + 2) * sizeof(char *));
	environ[i] = new_var;
	environ[i + 1] = NULL;
	free(new_var);
}
