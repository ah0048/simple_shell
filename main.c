#include "main.h"
/**
* main -  simple shell
* Return: 0 on EOF
*/
int main(void)
{
	int i, status;

	char *buf = NULL, *token, *full_path;

	size_t len, last_char;

	ssize_t read;

	pid_t child_pid;

	char **argv = malloc(MAX_WORDS * sizeof(char *));

	node *pathlist = makeList();

	while (1)
	{
		if (isatty(STDIN_FILENO))
		{
		printf("$ ");
		fflush(stdout);
		}
		read = getline(&buf, &len, stdin);
		if (read == -1)
		{
			break;
		}
		last_char = strlen(buf) - 1;
		if (buf[last_char] == '\n')
			buf[last_char] = '\0';
		token = strtok(buf, " ");
		i = 0;
		while (token != NULL)
		{
			argv[i] = strdup(token);
			if (argv[i] == NULL)
				printf("memory allocation failed for argv[i]\n");
			token = strtok(NULL, " ");
			i++;
		}
		argv[i] = NULL;
		if (strcmp(argv[0], "exit") == 0)
			break;
		if (access(argv[0], X_OK) != 0)
		while (pathlist)
		{
			full_path = malloc(strlen(argv[0] + strlen(pathlist->dir) + 2));
			sprintf(full_path, "%s/%s", pathlist->dir, argv[0]);
			if (access(full_path, X_OK) == 0)
			{
				free(argv[0]);
				argv[0] = strdup(full_path);
				free(full_path);
				break;
			}
			free(full_path);
			if (pathlist->next == NULL)
			{
				break;
			}
			pathlist = pathlist->next;
		}
		child_pid = fork();
		if (child_pid == 0)
		{
			if (execve(argv[0], argv, environ) == -1)
				printf("%s: No such file or directory\n", argv[0]);
			exit(EXIT_SUCCESS);
		}
		else
			wait(&status);
	}
	free(buf);
	i = 0;
	while (argv[i])
	{
		free(argv[i]);
		i++;
	}
	free(argv);
	freelist(pathlist);
	free(token);
	return (EXIT_SUCCESS);
}
