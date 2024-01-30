#include "main.h"

/**
 * print_hex - Print an unsigned integer in hexadecimal format
 * @n: The unsigned integer to print
 * @uppercase: Flag to indicate whether to use uppercase letters (1) or not (0)
 *
 * Return: The number of characters printed
 */
int print_hex(unsigned int n, int uppercase)
{
int count = 0;
char hex_digits[] = "0123456789abcdef";
if (uppercase)
hex_digits[10] = 'A';
if (n == 0)
return (print_char('0'));
while (n != 0)
{
int remainder = n % 16;
count += print_char(hex_digits[remainder]);
n /= 16;
}
count += print_char_repeat('0', 8 - count);
return (count);
}
