#include "main.h"
/**
* main -  simple shell
* Return: 0 on EOF
*/
int main(void)
{
	int i;

	char *buf = malloc(MAX_SIZE * sizeof(char));

	int j;

	pid_t child_pid;

	int status;

	char *token;

	char **argv = malloc(MAX_WORDS * sizeof(char *));

	while (1)
	{
		printf("$ ");
		fflush(stdout);
		if (fgets(buf, sizeof(buf), stdin) == NULL)
				break;
		token = strtok(buf, " ");
		j = 0;
		while (token[j])
		{
			if (token[j] == '\n')
			token[j] = '\0';
			j++;
		}
		free
		if (argv == NULL)
		{
			printf("memory allocation failed for argv\n");
		}
		i = 0;
		while (token != NULL)
		{
			argv[i] = strdup(token);
			if (argv[i] == NULL)
				printf("memory allocation failed for argv[i]\n");
			token = strtok(NULL, " ");
			i++;
		}
		child_pid = fork();
		if (child_pid == 0)
		{
			if (execve(argv[0], argv, environ) == -1)
			{
				printf("%s: No such file or directory\n", argv[0]);
			}
		}
		else
		{
			wait(&status);
		}
		free(buf);
		free(token);
		i = 0;
		while (argv[i])
		{
			free(argv[i]);
			i++;
		}
		free(argv);
	}
	return (EXIT_SUCCESS);
}
