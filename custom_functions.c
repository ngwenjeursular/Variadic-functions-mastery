#include "variadic_functions.h"

/**
 * _putchar - used to write a character to std output
 * @c: character to be printed
 * Return: 1 (Success)
 * on error, -1 is returned
 */

int _putchar(char c)
{
	return (write(1, &c, 1));
}

/**
 * _puts - print a string
 * @str:pointer char
 * return:void
 */
void _puts(char *str)
{
	int i;

	for (i = 0; str[i] != '\0'; i++)
	{
		_putchar(str[i]);
	}
	_putchar('\n');
}
