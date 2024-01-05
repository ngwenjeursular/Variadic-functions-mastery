/*DAY 2 OF #31DaysofDiscipline*/
/*Hackerrank Problem*/

/*you will implement three variadic functions named sum(), min()  and max()  to calculate sums, minima, maxima of a variable number of arguments.
 *  The first argument passed to the variadic function is the count of the number of arguments, which is followed by the arguments themselves.*/


#include <stdio.h>
#include "variadic_functions.h"

/**
 * sum - finds the sum of the given parameters
 * @count: represents the number of arguments
 *
 * Return: resulting sum
 */
int sum(int count, ...)
{
	va_list args;
	int i, result = 0;

	va_start(args, count);

	for (i = 0; i < count; ++i)
	{
		result += va_arg(args, int);
	}

	va_end(args); /*ends your access to the arguments*/

	return (result);
}

/**
 * min - finds the minimum number
 * @count: represents the number of arguments
 *
 * Return: minimum number
 */
int min(int count, ...)
{
	va_list args;
	int i, min_value, current;

	va_start(args, count);

	min_value = va_arg(args, int);

	for (i = 1; i < count; ++i)
	{
		current = va_arg(args, int);
		if (current < min_value)
			min_value = current;

	}
	va_end(args);

	return (min_value);
}

/**
 * max - finds the maximum number
 * @count: represents the number of arguments
 *
 * Return: maximum number
 */
int max(int count, ...)
{
        va_list args;
        int i, max_value, current;

        va_start(args, count);

        max_value = va_arg(args, int);

        for (i = 1; i < count; ++i)
        {
                current = va_arg(args, int);
                if (current > max_value)
                        max_value = current;

        }
        va_end(args);

        return (max_value);
}
