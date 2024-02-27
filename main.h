#ifndef SH
#define SH
#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/wait.h>
extern char **environ;
#define MAX_SIZE 1024
/**
 * struct node - linked list for directories
 * @dir: directory
 * @next: point to next node
 *
 * Description: node
 */
typedef struct node
{
	char *dir;
	struct node *next;
} node;
#endif
