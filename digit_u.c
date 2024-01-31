#include "main.h"
/**
 * to_print - checks if a char can be printed
 * @c: char to be checked
 * Return: 1 if c is printable, else 0
 */
int to_print(char c)
{
if (c >= 32 && c < 127)
return (1);
return (0);
}

/**
 * hex_append - Append ascii in hex code to buffer
 * @buffer: array of chars
 * @i: index to start appending
 * @ascii_code: ascii code
 * Return: 3 for success
 */
int hex_append(char ascii_code, char buffer[], int i)
{
char map_to[] = "0123456789ABCDEF";
if (ascii_code < 0)
ascii_code *= -1;
buffer[i++] = '\\';
buffer[i++] = 'x';
buffer[i++] = map_to[ascii_code / 16];
buffer[i] =  map_to[ascii_code % 16];

return (3);
}
/**
 * digit_verify - This checks if a char is a integer
 * @c: char to be checked
 * Return: 1 if c is a integer, else 0
 */
int digit_verify(char c)
{
if (c >= '0' && c <= '9')
return (1);
return(0);
}
/**
 * num_convert - casts a number to the specified size
 * @num: Number to be casted
 * @size: Number indicating the type to be casted
 *
 * Return: casted value of num
 */
long int num_convert(long int num, int size)
{
if (size == S_LONG)
return (num);
else if (size == S_SHORT)
return ((short)num);
return ((int)num);
}

/**
 * unsig_convert - This casts a number to the specific size
 * @num: Num to be casted
 * @size: Number indicatinf the type to be casted
 * Return: casted value of num
 */
long int unsig_convert(unsigned long int num, int size)
{
if (size == S_LONG)
return (num);
else if (size == S_SHORT)
return ((unsigned short)num);
return ((unsigned int)num);
}
