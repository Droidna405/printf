#include "main.h"
#include <unistd.h>
#include <stdarg.h>
#include <stdlib.h>
#include <stdio.h>
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
