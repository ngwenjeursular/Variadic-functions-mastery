#include "variadic_functions.h"
/**
 * calculateMean - Calculate the mean of a dataset.
 * @count: Number of elements in the dataset.
 * @...: Variadic arguments representing the dataset.
 *
 * Return: Mean of the dataset.
 */
double calculateMean(int count, ...)
{
	va_list args;
	double sum = 0;
	int i;

	va_start(args, count);

	for (i = 0; i < count; ++i)
	{
		sum += va_arg(args, double);
	}

	va_end(args);

	return (sum / count);
}

/**
 * calculateVariance - Calculate the variance of a dataset.
 * @count: Number of elements in the dataset.
 * @...: Variadic arguments representing the dataset.
 *
 * Return: Variance of the dataset.
 */
double calculateVariance(int count, ...)
{
	va_list args;
	double mean, sumSquaredDifferences, difference;
	int i;

	va_start(args, count);

	mean = calculateMean(count, args);

	va_end(args);

	va_start(args, count);

	sumSquaredDifferences = 0;

	for (i = 0; i < count; ++i)
	{
		difference = va_arg(args, double) - mean;
		sumSquaredDifferences += difference * difference;
	}

	va_end(args);

	return (sumSquaredDifferences / count);
}

/**
 * calculateStandardDeviation - Calculate the standard deviation of a dataset.
 * @count: Number of elements in the dataset.
 * @...: Variadic arguments representing the dataset.
 *
 * Return: Standard deviation of the dataset.
 */
double calculateStandardDeviation(int count, ...)
{
	va_list args;
	double variance;

	va_start(args, count);

	variance = calculateVariance(count, args);

	va_end(args);

	return (sqrt(variance));
}
