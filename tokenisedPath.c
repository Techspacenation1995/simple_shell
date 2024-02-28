#include "shell.h"

/**
 * tokenised - a function that returns a linked list of paths
 * tokenized from path enviroment variable (PEV).
 *
 * Return: a linked list, which contains the paths extracted
 * from the "PATH" environment variable.
*/
list_paths *tokenised()
{
	list_paths *paths_linkedlists;
	char *copied_variable, *path_variable, *token;

	paths_linkedlists = NULL;

	path_variable = _getenv("PATH");
	if (path_variable == NULL)
		return (NULL);
	copied_variable = _strdup(path_variable);
	if (copied_variable == NULL)
		return (NULL);
	token = strtok(copied_variable, ":");
	while (token != NULL)
	{
		node(&paths_linkedlists, token);
		token = strtok(NULL, ":");
	}
	free(copied_variable);
	return (paths_linkedlists);
}

/**
 * node - a function that adds a new node at the beginning of a list_t list
 * @head: pointer to the head of list with the type list_paths
 * @path: pointer to path.
 * Return: the address of the new element, or NULL if it failed
*/
list_paths *node(list_paths **head, char *path)
{
	list_paths *new;
	int i = 0;
	char *string_path;


	while (path[i] != '\0')
	{
		i++;
	}
	new = malloc(sizeof(list_paths));
	if (new == NULL)
		return (NULL);

	if (path)
	{
	string_path = _strdup(path);
	if (string_path == NULL)
	{
		free(new);
		return (NULL);
	}
	new->len = i;
	new->path = string_path;
	}
	else
	{
		new->len = 0;
		new->path = NULL;
	}
	new->next = (*head);

	*head = new;
	return (new);
}

/**
* freeList - Frees a singly linked list
* @head: Pointer to the head of the list
*/
void freeList(list_paths *head)
{
	list_paths *ptr = head;
	list_paths *nextNode;

	while (ptr != NULL)
	{

		nextNode = ptr->next;
		free(ptr->path);
		free(ptr);
		ptr = nextNode;
	}

}

/**
 * print_list - prints all the elements of a list_paths list
 * If str is NULL, print [0] (nil)
 * @h: pointer to the head of list with the type list_paths
 * Return: the number of nodes
*/
size_t print_list(const list_paths *h)
{
	int count;

	if (h == NULL)
	{
		return (0);
	}
	count = 0;
	while (h)
	{
		if (h->path == NULL)
		{
			printf("[0] (nil)\n");
			fflush(stdout);
		}
		else
		{
			printf("[%d] %s\n", h->len, h->path);
			fflush(stdout);
		}
		h = h->next;
		count++;
	}
	return (count);
}
