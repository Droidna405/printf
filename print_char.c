#include <unistd.h>
/**
 * print_char - helper function that prints char 
 * @c: char to be printed
 * Return: char
 */
int print_char(char c)
{
return write(1, &c, 1);
}
