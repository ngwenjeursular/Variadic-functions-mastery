#ifndef VARIADIC_FUNCTIONS_H
#define VARIADIC_FUNCTIONS_H

#include <stdarg.h> /*header file required to access passed parameters in a variadic function*/
#include <unistd.h>
#include <stddef.h>
#include <stdio.h>
#include <math.h>

int sum(int count, ...);
int max(int count, ...);
int min(int count, ...);

/*helper functions*/
int _putchar(char c);
void _puts(char *str);

int custom_printf(const char *format, ...);

/*nested variiadic functions*/
double calculateMean(int count, ...);
double calculateVariance(int count, ...);
double calculateStandardDeviation(int count, ...);

#endif  /*VARIADIC_FUNCTIONS_H*/
