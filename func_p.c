#include "main.h"

/**
 * var_point - prints value of pointer var
 *
 * @types: list types of args
 * @buffer: array buffer
 * @flags: calcs active flags
 * @width: gets width option
 * @precision: precision format specifier
 * @size: size format specifier
 * Return: number of chars printed
 */
int var_point(va_list types, char buffer[],
              int flags, int width, int precision, int size)
{
char extra_c = 0, padd = ' ';
int ind = BUFF_SIZE - 1, length = 2, padd_start = 1;

unsigned long num_addrs;
char map_to[] = "0123456789abcdef";
void *addrs = va_arg(types, void *);

UNUSED(width);
UNUSED(size);

if (addrs == NULL)
return (buff_num(0, buffer, 0, 0, 0, 5, ' ', ' '));

buffer[BUFF_SIZE - 1] = '\0';
UNUSED(precision);

num_addrs = (unsigned long)addrs;
while (num_addrs > 0)
{
buffer[--ind] = map_to[num_addrs % 16];
num_addrs /= 16;
length++;
}
if ((flags & F_ZERO) && !(flags & F_MINUS))
padd = '0';

return (num_pointer(buffer, ind, length, width, flags, padd, extra_c, padd_start));
}

#include <unistd.h>


/**
 * print_not_printable - handles non-printable characters
 *
 * @types: list types of args
 * @buffer: array buffer
 * @flags: calcs active flags
 * @width: gets width option
 * @precision: precision format specifier
 * @size: size format specifier
 * Return: number of chars printed
 */
int print_not_printable(va_list types, char buffer[],
                        int flags, int width, int precision, int size)
{
char *str = va_arg(types, char *);
int i = 0, offset = 0;

UNUSED(width);
UNUSED(precision);
UNUSED(size);
UNUSED(flags);
 
if (str == NULL)
return write(1, "(null)", 6);

while (str[i])
{
if (!to_print(str[i]))
{
offset += hex_append(str[i], buffer, offset);
}
else
{
buffer[offset++] = str[i];
}

if (offset >= BUFF_SIZE - 1)
break;
i++;
}

buffer[offset] = '\0';

return (write(1, buffer, i + offset));
}
