#include "shell.h"

/**
 * _myexit - exits the shell
 * @news: Structure containing potential arguments. Used to maintain
 * constant function prototype.
 * Return: exits with a given exit status
 * (0) if news.argv[0] != "exit"
 */
int _myexit(news_t *news)
{
	int exitcheck;

	if (news->argv[1]) /* If there is an exit arguement */
	{
		exitcheck = _erratoi(news->argv[1]);
		if (exitcheck == -1)
		{
			news->status = 2;
			print_error(news, "Illegal number: ");
			_eputs(news->argv[1]);
			_eputchar('\n');
			return (1);
		}
		news->err_num = _erratoi(news->argv[1]);
		return (-2);
	}
	news->err_num = -1;
	return (-2);
}

/**
 * _mycd - changes the current directory of the process
 * @news: Structure containing potential arguments. Used to maintain
 * constant function prototype.
 * Return: Always 0
 */
int _mycd(news_t *news)
{
	char *s, *dir, buffer[1024];
	int chdir_ret;

	s = getcwd(buffer, 1024);
	if (!s)
		_puts("TODO: >>getcwd failure emsg here<<\n");
	if (!news->argv[1])
	{
		dir = _getenv(news, "HOME=");
		if (!dir)
			chdir_ret = /* TODO: what should this be? */
				chdir((dir = _getenv(news, "PWD=")) ? dir : "/");
		else
			chdir_ret = chdir(dir);
	}
	else if (_strcmp(news->argv[1], "-") == 0)
	{
		if (!_getenv(news, "OLDPWD="))
		{
			_puts(s);
			_putchar('\n');
			return (1);
		}
		_puts(_getenv(news, "OLDPWD=")), _putchar('\n');
		chdir_ret = /* TODO: what should this be? */
			chdir((dir = _getenv(news, "OLDPWD=")) ? dir : "/");
	}
	else
		chdir_ret = chdir(news->argv[1]);
	if (chdir_ret == -1)
	{
		print_error(news, "can't cd to ");
		_eputs(news->argv[1]), _eputchar('\n');
	}
	else
	{
		_setenv(news, "OLDPWD", _getenv(news, "PWD="));
		_setenv(news, "PWD", getcwd(buffer, 1024));
	}
	return (0);
}

/**
 * _myhelp - changes the current directory of the process
 * @news: Structure containing potential arguments. Used to maintain
 * constant function prototype.
 * Return: Always 0
 */
int _myhelp(news_t *news)
{
	char **arg_array;

	arg_array = news->argv;
	_puts("help call works. Function not yet implemented \n");
	if (0)
		_puts(*arg_array); /* temp att_unused workaround */
	return (0);
}

