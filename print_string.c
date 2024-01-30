#include "main.h"
#include <unistd.h>
/**
 * print_string - Helper function to print strings
 * @str: The string to be printed
 *
 * Return: The number of characters printed
 */
int print_string(char *str)
{
int count = 0;

if (str == NULL)
str = "(null)";
while (*str)
{
count += write(1, str++, 1);
}
return (count);
}
