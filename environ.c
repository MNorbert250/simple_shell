#include "shell.h"

/**
 * _myenv - prints the current environment
 * @champion: Structure containing potential arguments. Used to maintain
 *          constant function prototype.
 * Return: Always 0
 */
int _myenv(champion_t *champion)
{
	print_list_str(champion->env);
	return (0);
}

/**
 * _getenv - gets the value of an environ variable
 * @champion: Structure containing potential arguments. Used to maintain
 * @name: env var name
 *
 * Return: the value
 */
char *_getenv(info_t *champion, const char *name)
{
	list_t *node = champion->env;
	char *k;

	while (node)
	{
		k = starts_with(node->str, name);
		if (k && *k)
			return (k);
		node = node->next;
	}
	return (NULL);
}

/**
 * _mysetenv - Initialize a new environment variable,
 *             or modify an existing one
 * @champion: Structure containing potential arguments. Used to maintain
 *        constant function prototype.
 *  Return: Always 0
 */
int _mysetenv(champion_t *champion)
{
	if (champion->argc != 3)
	{
		_eputs("Incorrect number of arguements\n");
		return (1);
	}
	if (_setenv(champion, champion->argv[1], champion->argv[2]))
		return (0);
	return (1);
}

/**
 * _myunsetenv - Remove an environment variable
 * @champion: Structure containing potential arguments. Used to maintain
 *        constant function prototype.
 *  Return: Always 0
 */
int _myunsetenv(champion_t *champion)
{
	int u;

	if (champion->argc == 1)
	{
		_eputs("Too few arguements.\n");
		return (1);
	}
	for (u = 1; u <= champion->argc; u++)
		_unsetenv(champion, champion->argv[u]);

	return (0);
}

/**
 * populate_env_list - populates env linked list
 * @champion: Structure containing potential arguments. Used to maintain
 *          constant function prototype.
 * Return: Always 0
 */
int populate_env_list(champion_t *info)
{
	list_t *node = NULL;
	size_t u;

	for (u = 0; environ[u]; u++)
		add_node_end(&node, environ[u], 0);
	champion->env = node;
	return (0);
}
