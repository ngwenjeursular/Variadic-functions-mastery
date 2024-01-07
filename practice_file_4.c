/*Day 4*/
/*Error handling and debugging*/

#include "variadic_functions.h"

/**
 * custom_printf - Prints to output according to format
 * @format: Character string
 * Return: 0 (Success)
 */
int custom_printf2(const char *format, ...)
{
        va_list args;
	int i = 0;
	int num;
	char *str, ch;

	va_start(args, format);
	if (format == NULL)
        {
                fprintf(stderr, "Error: Null format string\n"); /*print to stderror*/
		return (-1);/*Exit*/
        }
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
                                                if (va_arg(args, int) < 0)/*No negative integers*/
                                                {
                                                        fprintf(stderr, "Error: Negative integer not allowed\n");
                                                        va_end(args);
                                                        return (-1);
                                                }
						num = va_arg(args, int);
						printf("%d", num);
						i++;
						break;
					}
					case 's': /*Handle string*/
					{
						str = va_arg(args, char *);

                                                if (str == NULL)/*Handle NULL string*/
                                                {
                                                        fprintf(stderr, "Error: Null string argument\n");
                                                        va_end(args);
                                                        return (-1);
                                                }
						printf("%s", str);
						i++;
						break;
					}
					case 'c': /*Handle character*/
					{
						ch = va_arg(args, int);

                                                if (!isalpha(ch))/*Handle non-alphabets*/
                                                {
                                                        fprintf(stderr, "Error: Non-alphabetic character\n");
                                                        va_end(args);
                                                        return (-1);
                                                }
						printf("%c", ch);
						i++; /*Move to the next character after 'c'*/
						break;
					}
					default: /*Unsupported specifier, print as is*/
                                                fprintf(stderr, "Error: Unsupported format specifier\n");
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
