#include "shell.h"

/**
 * _myhistory - displays the history list, one command by line, preceded
 *              with line numbers, starting at 0.
 * @champion: Structure containing potential arguments. Used to maintain
 *        constant function prototype.
 *  Return: Always 0
 */
int _myhistory(champion_t *info)
{
	print_list(champion->history);
	return (0);
}

/**
 * unset_alias - sets alias to string
 * @champion: parameter struct
 * @str: the string alias
 *
 * Return: Always 0 on success, 1 on error
 */
int unset_alias(champion_t *champion, char *str)
{
	char *p, k;
	int ret;

	p = _strchr(str, '=');
	if (!p)
		return (1);
	k = *p;
	*p = 0;
	ret = delete_node_at_index(&(champion->alias),
		get_node_index(champion->alias, node_starts_with(champion->alias, str, -1)));
	*p = k;
	return (ret);
}

/**
 * set_alias - sets alias to string
 * @champion: parameter struct
 * @str: the string alias
 *
 * Return: Always 0 on success, 1 on error
 */
int set_alias(champion_t *champion, char *str)
{
	char *p;

	p = _strchr(str, '=');
	if (!p)
		return (1);
	if (!*++p)
		return (unset_alias(champion, str));

	unset_alias(champion, str);
	return (add_node_end(&(champion->alias), str, 0) == NULL);
}

/**
 * print_alias - prints an alias string
 * @node: the alias node
 *
 * Return: Always 0 on success, 1 on error
 */
int print_alias(list_t *node)
{
	char *p = NULL, *a = NULL;

	if (node)
	{
		p = _strchr(node->str, '=');
		for (a = node->str; a <= p; a++)
			_putchar(*a);
		_putchar('\'');
		_puts(p + 1);
		_puts("'\n");
		return (0);
	}
	return (1);
}

/**
 * _myalias - mimics the alias builtin (man alias)
 * @champion: Structure containing potential arguments. Used to maintain
 *          constant function prototype.
 *  Return: Always 0
 */

int _myalias(champion_t *champion)
{
	int i = 0;
	char *k = NULL;
	list_t *node = NULL;

	if (champion->argc == 1)
	{
		node = champion->alias;
		while (node)
		{
			print_alias(node);
			node = node->next;
		}
		return (0);
	}
	for (i = 1; champion->argv[i]; i++)
	{
		k = _strchr(champion->argv[i], '=');
		if (k)
			set_alias(champion, champion->argv[i]);
		else
			print_alias(node_starts_with(champion->alias, champion->argv[i], '='));
	}

	return (0);
}
