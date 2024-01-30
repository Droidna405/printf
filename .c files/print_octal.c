#include "main.h"

/**
 * print_octal - Print an unsigned integer in octal format
 * @n: The unsigned integer to print
 *
 * Return: The number of characters printed
 */
int print_octal(unsigned int n)
{
int count = 0;
int octal_digits[100];
if (n == 0)
return (print_char('0'));

while (n != 0)
{
octal_digits[count] = n % 8;
n /= 8;
count++;
}

while (--count >= 0)
print_char('0' + octal_digits[count]);

return (count);
}
