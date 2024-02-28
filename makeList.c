#include "main.h"
/**
* makeList - makes linked list of PATH.
* Return: pointer to linked list
*/
node *makeList(void)
{
	node *pathlist = NULL;

	char *path = strdup(getenv("PATH"));

	char *token = strtok(path, ":");

	while (token != NULL)
	{
		addDir(&pathlist, token);
		token = strtok(NULL, ":");
	}
	free(path);
	return (pathlist);
}
