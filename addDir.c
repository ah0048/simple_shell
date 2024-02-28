#include "main.h"
/**
* addDir -  adds a directory to a linked list
* @head: represents the head point of the linked list
* @dir: string for directory
* Return: 0 on EOF
*/
void addDir(node **head, const char *dir)
{
	node *newnode = malloc(sizeof(node));

	if (newnode == NULL)
	{
		printf("failed to allocate memory");
		exit(EXIT_FAILURE);
	}
	newnode->dir = strdup(dir);
	newnode->next = *head;
	*head = newnode;
}
