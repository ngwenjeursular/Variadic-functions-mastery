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

	result_sum = sum(3, 4, 2, 10);
	printf("Resulting sum: %d\n", result_sum);


	result_min = min(4, 56, 78, 61, 23);
	printf("Resulting minimum: %d\n", result_min);
	result_max = max(5, 1, 28, 324, 98, 107);
	printf("Resulting maximum: %d\n", result_max);


	return (0);
}
