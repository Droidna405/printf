#include "main.h"

/**
 * print_char_repeat - Helper function to print a character multiple times
 * @c: The character to print
 * @count: Number of times to print the character
 *
 * Return: The number of characters printed
 */
int print_char_repeat(char c, int count)
{
int i;
int total = 0;

for (i = 0; i < count; i++)
total += print_char(c);
return (total);
}
