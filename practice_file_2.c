/*In an attempt to experiment the practice of variadic functions using different data types
 * below is a simple custom printf function
 * printf is itself a  variadic function, so attempting to recreate a minimalistic version of it
 * serves as good practice.
 * This function will be very simple and is only meant to solidify my understanding of variadic functions*/

#include "variadic_functions.h"

/**
 * custom_printf - Prints to output according to format
 * @format: Character string
 * Return: 0 (Success)
 */
int custom_printf(const char *format, ...)
{
        va_list args;
	int i = 0;
	int num;
	char *str, ch;

	va_start(args, format);
	if (format == NULL) /*Exit*/
		return (-1);

	while (format[i])
	{
		if (format[i] == '%') /*go to the next then*/
		{
			if (format[i + 1])
			{
				switch (format[i + 1])
				{
					case 'd': /* Handle integer */
					{
						num = va_arg(args, int);
						printf("%d", num);
						i++;
						break;
					}
					case 's': /*Handle string*/
					{
						str = va_arg(args, char *);
						printf("%s", str);
						i++;
						break;
					}
					case 'c': /*Handle character*/
					{
						ch = va_arg(args, int);
						printf("%c", ch);
						i++; /*Move to the next character after 'c'*/
						break;
					}
					default: /*// Unsupported specifier, print as is*/
						_putchar('%');
						break;
				}
			}
			else
			{
				/* Incomplete format specifier, print '%'*/
				_putchar('%');
			}
		}
		else
		{
			_putchar(format[i]);
		}
		i++;
	}

	va_end(args);
	return (0);
}
