#include "main.h"
#include <unistd.h>
#include <stdarg.h>
#include <stdlib.h>

/**
 * print_char - Helper function to print a single character
 * @c: The character to be printed
 *
 * Return: The number of characters printed
 */
int print_char(char c)
{
return write(1, &c, 1);
}

/**
 * print_string - Helper function to print strings
 * @str: The string to be printed
 *
 * Return: The number of characters printed
 */
int print_string(char *str)
{
int count = 0;
while (*str)
{
count += write(1, str++, 1);
}
return (count);
}

/**
 * print_decimal - Helper function to print integers
 * @n: The integer to be printed
 *
 * Return: The number of characters printed
 */
int print_decimal(int n)
{
// Implementation for printing integers goes here
return (0);
}

/**
 * print_hex - Helper function to print hexadecimal
 * @n: The unsigned integer to be printed in hexadecimal
 * @uppercase: Whether to use uppercase letters in hex representation
 *
 * Return: The number of characters printed
 */
int print_hex(unsigned int n, int uppercase)
{
    // Implementation for printing hexadecimal goes here
return (0);
}

/**
 * print_unsigned - Helper function to print unsigned integers
 * @n: The unsigned integer to be printed
 *
 * Return: The number of characters printed
 */
int print_unsigned(unsigned int n)
{
    // Implementation for printing unsigned integers goes here
return (0);
}

/**
 * print_octal - Helper function to print octal
 * @n: The unsigned integer to be printed in octal
 *
 * Return: The number of characters printed
 */
int print_octal(unsigned int n)
{
    // Implementation for printing octal goes here
return (0);
}

/**
 * print_pointer - Helper function to print pointer addresses
 * @ptr: The pointer address to be printed
 *
 * Return: The number of characters printed
 */
int print_pointer(void *ptr)
{
    // Implementation for printing pointer addresses goes here
return (0);
}

/**
 * print_format - Helper function to handle format specifiers
 * @format: The format string with specifiers
 * @args: The va_list of arguments
 *
 * Return: The number of characters printed
 */
int print_format(const char *format, va_list args)
{
int count = 0;
while (*format)
{
if (*format == '%')
{
format++;
switch (*format)
{
case 'c':
count += print_char(va_arg(args, int));
break;
case 's':
count += print_string(va_arg(args, char *));
break;
case 'd':
count += print_decimal(va_arg(args, int));
break;
case 'x':
count += print_hex(va_arg(args, unsigned int), 0);
break;
case 'X':
count += print_hex(va_arg(args, unsigned int), 1);
break;
case 'u':
count += print_unsigned(va_arg(args, unsigned int));
break;
case 'o':
count += print_octal(va_arg(args, unsigned int));
break;
case 'p':
count += print_pointer(va_arg(args, void *));
break;
case '%':
count += print_char('%');
break;
default:
count += print_char('%');
count += print_char(*format);
break;
}
}
else
{
count += write(1, format, 1);
}
format++;
}
return (count);
}

/**
 * _printf - Our custom printf function
 * @format: The format string with specifiers
 *
 * Return: The number of characters printed
 */
int _printf(const char *format, ...)
{
va_list args;
int count;
va_start(args, format);
count = print_format(format, args);
va_end(args);
return (count);
}
