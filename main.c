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
	double mean, variance, stdDeviation;

	result_sum = sum(3, 4, 2, 10);
	printf("Resulting sum: %d\n", result_sum);


	result_min = min(4, 56, 78, 61, 23);
	printf("Resulting minimum: %d\n", result_min);
	result_max = max(5, 1, 28, 324, 98, 107);
	printf("Resulting maximum: %d\n", result_max);

	custom_printf("a number %d, a string: %s, and a character: %c\n", num, str, ch);

	mean = calculateMean(5, 10.5, 11.0, 10.8, 10.2, 10.9);
	variance = calculateVariance(5, 10.5, 11.0, 10.8, 10.2, 10.9);
	stdDeviation = calculateStandardDeviation(5, 10.5, 11.0, 10.8, 10.2, 10.9);

	printf("\nMean: %.2f\n", mean);
	printf("Variance: %.2f\n", variance);
	printf("Standard Deviation: %.2f\n", stdDeviation);


	custom_printf2(NULL);  /* Null format string */
	custom_printf2("Negative integer: %d\n", -5);  /* Negative integer not allowed */
	custom_printf2("Null string: %s\n", NULL);  /* Null string argument */
	custom_printf2("Non-alphabetic character: %c\n", '2');  /* Non-alphabetic character */




	return (0);
}
