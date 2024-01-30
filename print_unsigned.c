#include "main.h"
#include <unistd.h>

/**
 * print_unsigned - Helper function to print unsigned integers
 * @n: The unsigned integer to be printed
 *
 * Return: The number of characters printed
 */
int print_unsigned(unsigned int n)
{
char buffer[20];
int count = 0;
int i = 0;

if (n == 0)
{
return (print_char('0'));
}

while (n > 0)
{
buffer[i++] = (n % 10) + '0';
n /= 10;
}

for (i = i - 1; i >= 0; i--)
{
count += print_char(buffer[i]);
}
return (count);
}
