#include "variadic_functions.h"
#include <stdio.h>

/**
 * main - entry point
 *
 * Return: 0 (Success)
 */
int main(void)
{
	int result_sum, result_min, result_max;
	int num = 9;
	char str[] = "Jackie";
	char ch = 'j';

	result_sum = sum(3, 4, 2, 10);
	printf("Resulting sum: %d\n", result_sum);


	result_min = min(4, 56, 78, 61, 23);
	printf("Resulting minimum: %d\n", result_min);
	result_max = max(5, 1, 28, 324, 98, 107);
	printf("Resulting maximum: %d\n", result_max);

	custom_printf("a number %d, a string: %s, and a character: %c\n", num, str, ch);


	return (0);
}
