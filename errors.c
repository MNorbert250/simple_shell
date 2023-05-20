#include "shell.h"

/**
 * _eputs - prints an input string
 * @ptn: the string to be printed
 *
 * Return: Nothing
 */
void _eputs(char *ptn)
{
	int i = 0;

	if (!ptn)
		return;
	while (ptn[i] != '\0')
	{
		_eputchar(ptn[i]);
		i++;
	}
}

/**
 * _eputchar - writes the character t to stderr
 * @t: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _eputchar(char t)
{
	static int i;
	static char buf[WRITE_BUF_SIZE];

	if (t == BUF_FLUSH || i >= WRITE_BUF_SIZE)
	{
		write(2, buf, i);
		i = 0;
	}
	if (t != BUF_FLUSH)
		buf[i++] = t;
	return (1);
}

/**
 * _putfd - writes the character t to given fd
 * @t: The character to print
 * @fd: The filedescriptor to write to
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _putfd(char t, int fd)
{
	static int i;
	static char buf[WRITE_BUF_SIZE];

	if (t == BUF_FLUSH || i >= WRITE_BUF_SIZE)
	{
		write(fd, buf, i);
		i = 0;
	}
	if (t != BUF_FLUSH)
		buf[i++] = t;
	return (1);
}

/**
 * _putsfd - prints an input string
 * @ptn: the string to be printed
 * @fd: the filedescriptor to write to
 *
 * Return: the number of chars put
 */
int _putsfd(char *ptn, int fd)
{
	int i = 0;

	if (!ptn)
		return (0);
	while (*ptn)
	{
		i += _putfd(*ptn++, fd);
	}
	return (i);
}

