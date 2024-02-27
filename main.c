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

	printf("$ ");
	fflush(stdout);
	while (1)
	{
		char *token;

		char **argv = malloc(MAX_WORDS * sizeof(char *));

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

	if (execve(argv[0], argv, environ) == -1)
		printf("%s: No such file or directory\n", argv[0]);
	printf("$ ");
	fflush(stdout);
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
	return (0);
}
