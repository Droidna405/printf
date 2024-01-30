#include "main.h"

/**
 * print_decimal - Print an integer in decimal format
 * @n: The integer to print
 *
 * Return: The number of characters printed
 */
int print_decimal(int n)
{
int count = 0;
int divisor = 1;

if (n < 0)
{
count += print_char('-');
n = -n;
}
while (n / divisor >= 10)
divisor *= 10;
while (divisor != 0)
{
count += print_char('0' + n / divisor);
n %= divisor;
divisor /= 10;
}
return (count);
}
