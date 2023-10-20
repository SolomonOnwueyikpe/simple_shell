#include "shell.h"

int _myhistory(info_t *info);
int unset_alias(info_t *info, char *str);

/**
 * _myhistory - Display the history list, one command per line,
 *             preceded with line numbers, starting at 0.
 * @info: Structure containing potential arguments. Used to maintain
 *        a constant function prototype.
 * Return: Always 0
 */

int _myhistory(info_t *info)
{
	list_t *node = info->history;
	int line_num = 0;

	while (node)
	{
		_printf("%d %s\n", line_num++, node->str);
		node = node->next;
	}

	return (0);
}

/**
 * unset_alias - Unset an alias.
 * @info: Parameter struct.
 * @str: The string alias.
 * Return: 0 on success, 1 on error.
 */

int unset_alias(info_t *info, char *str)
{
	char *p, c;
	int ret;

	p = _strchr(str, '=');
	if (!p)
		return (1);
	c = *p;
	*p = 0;
	ret = delete_node_at_index(&(info->alias),
		get_node_index(info->alias, node_starts_with(info->alias, str, -1)));
	*p = c;
	return (ret);
}

/**
 * set_alias - Set an alias to a string.
 * @info: Parameter struct.
 * @str: The string alias.
 * Return: 0 on success, 1 on error.
 */
int set_alias(info_t *info, char *str)
{
	char *p;

	p = _strchr(str, '=');
	if (!p)
		return (1);

	if (!*++p)
		return (unset_alias(info, str));

	unset_alias(info, str);
	return (add_node_end(&(info->alias), str, 0) ? 0 : 1);
}

/**
 * print_alias - Print an alias string.
 * @node: The alias node.
 * Return: 0 on success, 1 on error.
 */

int print_alias(list_t *node)
{
	if (node)
	{
		char *p = _strchr(node->str, '=');
		char *a = node->str;

		while (a <= p)
			_putchar(*a++);
		_putchar('\'');
		_puts(p + 1);
		_puts("'\n");
		return (0);
	}

	return (1);
}

/**
 * _myalias - Mimic the alias builtin (man alias).
 * @info: Structure containing potential arguments. Used to maintain
 *        a constant function prototype.
 * Return: Always 0
 */

int _myalias(info_t *info)
{
	int i = 0;
	char *p = NULL;

	if (info->argc == 1)
	{
		list_t *node = info->alias;

		while (node)
		{
			print_alias(node);
			node = node->next;
		}
	}
	else
	{
		for (i = 1; info->argv[i]; i++)
		{
			p = _strchr(info->argv[i], '=');
			if (p)
				set_alias(info, info->argv[i]);
			else
				print_alias(node_starts_with(info->alias, info->argv[i], '='));
		}
	}

	return (0);
}
