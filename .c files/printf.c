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
int count = 0;
va_start(args, format);
while (*format)
{
if (*format == '%')
{
format++;
switch (*format)
{
case 'c':
char temp;
temp = (char)va_arg(args, int);
count += write(1, &temp, 1);
break;
case 's':
count += write(1, va_arg(args, char *), 1);
break;
case '%':
count += write(1, "%", 1);
break;
case 'd':
case 'i':
count += printf("%d", va_arg(args, int));
break;
}
}
else
{
count += write(1, format, 1);
}
format++;
}
va_end(args);
return (count);
}
