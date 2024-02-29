#include "main.h"
/**
* main -  simple shell
* Return: 0 on EOF
*/
int main(void)
{
	int i, status;

	char *buf = NULL, *inner_buf, *token, *full_path;

	size_t len, last_char;

	ssize_t read;

	pid_t child_pid;

	char **argv = malloc(MAX_WORDS * sizeof(char *));

	node *pathlist = makeList();

	node *current;

	argv[0] = NULL;

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
		inner_buf = strtok(buf, "\n");
		while (inner_buf)
		{
		token = strtok(inner_buf, " ");
		i = 0;
		while (token != NULL)
		{
			argv[i] = strdup(token);
			if (argv[i] == NULL)
				printf("memory allocation failed for argv[i]\n");
			token = strtok(NULL, " ");
			i++;
		}
		inner_buf = strtok(NULL, "\n");
		}
		argv[i] = NULL;
		if (argv[0] == NULL || strlen(argv[0]) == 0)
			continue;
		if (strcmp(argv[0], "exit") == 0)
			break;
		current = pathlist;
		if (access(argv[0], X_OK) != 0)
		while (current)
		{
			full_path = malloc(strlen(argv[0] + strlen(current->dir) + 2));
			sprintf(full_path, "%s/%s", current->dir, argv[0]);
			if (access(full_path, X_OK) == 0)
			{
				free(argv[0]);
				argv[0] = strdup(full_path);
				free(full_path);
				break;
			}
			free(full_path);
			if (current->next == NULL)
			{
				break;
			}
			current = current->next;
		}
		current = NULL;
		child_pid = fork();
		if (child_pid == 0)
		{
			if (execve(argv[0], argv, environ) == -1)
				printf("%s: No such file or directory\n", argv[0]);
			exit(0);
		}
		else
			wait(&status);
	}
	free(buf);
	free(inner_buf);
	i = 0;
	while (argv[i])
	{
		free(argv[i]);
		i++;
	}
	free(argv);
	freelist(pathlist);
	return (0);
}
