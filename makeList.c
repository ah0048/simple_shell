#include "main.h"
/**
* makeList - makes linked list of PATH.
* Return: pointer to linked list
*/
node *makeList(void)
{
	node *pathlist = NULL;

	char *path, *token;

	if (getenv("PATH") == NULL)
		return (NULL);
	path = strdup(getenv("PATH"));
	token = strtok(path, ":");
	while (token != NULL)
	{
		addDir(&pathlist, token);
		token = strtok(NULL, ":");
	}
	free(path);
	return (pathlist);
}
