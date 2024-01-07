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
	double sum = 0, current;
	int i;

	if (count <= 0)
	{
	    fprintf(stderr, "Error: Invalid count for calculateMean function\n");
	    return -1;
	}


	va_start(args, count);
	
	current = va_arg(args, double);
	for (i = 0; i < count; ++i)
	{
		if (!current)
		{
		    fprintf(stderr, "Error: Non-double argument for calculateMean function\n");
		    va_end(args);
		    return (-1);  /* Return -1 or handle the error as needed */
		}

		sum += current;
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
	double mean, sumSquaredDifferences, difference, current;
	int i;

	if (count <= 0)
	{
	    fprintf(stderr, "Error: Invalid count for calculateVariance function\n");
	    return (-1);
	}


	va_start(args, count);

	mean = calculateMean(count, args);

	va_end(args);

	va_start(args, count);

	sumSquaredDifferences = 0;

	for (i = 0; i < count; ++i)
	{
		current = va_arg(args, double);

		if (!current)
		{
		    fprintf(stderr, "Error: Non-double argument for calculateVariance function\n");
		    va_end(args);
		    return (-1);
		}

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

	if (count <= 0)
	{
	    fprintf(stderr, "Error: Invalid count for calculateStandardDeviation function\n");
	    return (-1);
	}


	va_start(args, count);

	variance = calculateVariance(count, args);

	va_end(args);

	if (variance == -1)
	{
	    fprintf(stderr, "Error: Unable to calculate standard deviation due to variance error\n");
	    return -1;
	}


	return (sqrt(variance));
}
