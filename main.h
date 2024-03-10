#ifndef SH
#define SH
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/wait.h>
#define MAX_SIZE 1024
#define MAX_WORDS 100
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
extern char **environ;
void addDir(node **head, const char *dir);
void freelist(node *head);
node *makeList(void);
void _env(void);
int isExit(char *value_str);
#endif
