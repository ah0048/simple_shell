#include "main.h"
/**
* freelist -  free the linked list
* @head : head pointer to the linked list
* Return: void
*/
void freelist(node *head)
{
	node *tmp;

	while (head != NULL)
	{
		tmp = head;
		head = head->next;
		free(tmp->dir);
		free(tmp);
	}
}
