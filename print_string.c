#include "main.h"
/**
 * print_string - prints a string
 * @str: pointer to the string to be printed
 * Return: number of characters printed
 */
int print_string(char *str)
{
	int count = 0;

	if (str == NULL)
		return (-1); /* Error NULL pointer */
	while (*str != '\0')
	{
		count += print_char(*str);
		str++;
	}
	return (count);
}
