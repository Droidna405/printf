#include "main.h"
#include <unistd.h>
/**
 * print_format - Format and print output based on the format string
 * @format: The format string
 * @args: The variable arguments list
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
