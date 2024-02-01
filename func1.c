#include "main.h"

static int print_base(unsigned long int num, char map_to[], char buffer[],
                      int flags, char flag_ch, int size);

/**
 * _unsigned_convert_size - Converts an unsigned long int to the specified size
 * @num: The unsigned long int to convert
 * @size: The desired size (S_SHORT, S_LONG, or neither)
 *
 * Return: The converted value
 */
long int _unsigned_convert_size(unsigned long int num, int size)
{
if (size == S_LONG)
return ((long int)num);
else if (size == S_SHORT)
return ((short)num);

return ((long int)num);
}


/**
 * _unsigned_p - Prints an unsigned number
 * @types: List a of arguments
 * @buffer: Buffer array to handle print
 * @flags:  Calculates active flags
 * @width: get width
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Number of chars printed.
 */
int _unsigned_p(va_list types, char buffer[],
		   int flags, int width, int precision, int size)
{
int i = BUFF_SIZE - 2;
unsigned long int num = va_arg(types, unsigned long int);

num = _unsigned_convert_size(num, size);

if (num == 0)
buffer[i--] = '0';

buffer[BUFF_SIZE - 1] = '\0';

while (num > 0)
{
buffer[i--] = (num % 10) + '0';
num /= 10;
}

i++;

return (handle_unsigned_(0, i, buffer, flags, width, precision, size));
}

/**
 * octal_p - Prints an unsigned number in octal notation
 * @types: Lista of arguments
 * @buffer: Buffer array to handle print
 * @flags:  Calculates active flags
 * @width: get width
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Number of chars printed
 */
int octal_p(va_list types, char buffer[],
		int flags, int width, int precision, int size)
{

int i = BUFF_SIZE - 2;
unsigned long int num = va_arg(types, unsigned long int);
unsigned long int init_num = num;

UNUSED(width);

num = _unsigned_convert_size(num, size);

if (num == 0)
buffer[i--] = '0';

buffer[BUFF_SIZE - 1] = '\0';

while (num > 0)
{
buffer[i--] = (num % 8) + '0';
num /= 8;
}

if (flags & F_HASH && init_num != 0)
buffer[i--] = '0';

i++;

return (handle_unsigned_(0, i, buffer, flags, width, precision, size));
}

/**
 * hex_p - Prints an unsigned number in hexadecimal notation
 * @types: Lista of arguments
 * @buffer: Buffer array to handle print
 * @flags:  Calculates active flags
 * @width: get width
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Number of chars printed
 */
int hex_p(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
return (print_hex(types, "0123456789abcdef", buffer,
		  flags, 'x', width, precision, size));
}

/**
 * print_hex_uppercase - Prints an unsgnd num in upper hex notation
 * @types: Lista of arguments
 * @buffer: Buffer array to handle print
 * @flags:  Calculates active flags
 * @width: get width
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Number of chars printed
 */
int print_hex_uppercase(va_list types, char buffer[],
			int flags, int width, int precision, int size)
{
return (print_hex(types, "0123456789ABCDEF", buffer,
		  flags, 'X', width, precision, size));
}


/**
 * print_hex - Prints a hexadecimal number in lower or upper
 * @types: Lista of arguments
 * @map_to: Array of values to map the number to
 * @buffer: Buffer array to handle print
 * @flags:  Calculates active flags
 * @flag_ch: Calculates active flags
 * @width: get width
 * @precision: Precision specification
 * @size: Size specifier
 * @size: Size specification
 * Return: Number of chars printed
 */
int print_hex(va_list types, char map_to[], char buffer[],
	int flags, char flag_ch, int width, int precision, int size)
{
int i = BUFF_SIZE - 2;
unsigned long int num = va_arg(types, unsigned long int);
unsigned long int init_num = num;

UNUSED(width);

num = _unsigned_convert_size(num, size);

if (num == 0)
buffer[i--] = '0';

buffer[BUFF_SIZE - 1] = '\0';

while (num > 0)
{
buffer[i--] = map_to[num % 16];
num /= 16;
}

if (flags & F_HASH && init_num != 0)
{
buffer[i--] = flag_ch;
buffer[i--] = '0';
}

i++;

return (handle_unsigned_(0, i, buffer, flags, width, precision, size));
}

static int print_base(unsigned long int num, char map_to[], char buffer[], int flags, char flag_ch, int size)
{
    int i = BUFF_SIZE - 2;
    unsigned long int init_num = num;

    UNUSED(width);

    num = _unsigned_convert_size(num, size);

    if (num == 0)
        buffer[i--] = '0';

    buffer[BUFF_SIZE - 1] = '\0';

    while (num > 0)
    {
        buffer[i--] = map_to[num % (int)strlen(map_to)];
        num /= (int)strlen(map_to);
    }

    if ((flags & F_HASH) && init_num != 0)
    {
        buffer[i--] = flag_ch;
        buffer[i--] = '0';
    }
     i++;

    return handle_unsigned_(0, i, buffer, flags, width, precision, size);
}
