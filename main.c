#include "main.h"
/**
* main -  simple shell
* Return: 0 on EOF
*/
int main(void)
{
	int i, char *buf = NULL, size_t len, ssize_t read, size_t last_char;

	pid_t child_pid, int status, char *token;

	char **argv = malloc(MAX_WORDS * sizeof(char *));

	while (1)
	{
		printf("$ "); fflush(stdout);
		read = getline(&buf, &len, stdin);
		if (read == -1)
		{
			printf("\n"); break;
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
		child_pid = fork();
		if (child_pid == 0)
		{
			if (execve(argv[0], argv, environ) == -1)
				printf("hsh: No such file or directory\n");
			exit(EXIT_SUCCESS);
		}
		else
			wait(&status);
	}
	free(buf);
	i = 0;
	while (argv[i])
	{free(argv[i]);
		i++;}
	free(argv);
       	return (EXIT_SUCCESS);
}
