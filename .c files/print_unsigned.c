#include "main.h"
/**
 * print_unsigned - Print an unsigned integer
 * @n: The unsigned integer to print
 *
 * Return: The number of characters printed
 */
int print_unsigned(unsigned int n)
{
int count = 0;
int divisor = 1;
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
