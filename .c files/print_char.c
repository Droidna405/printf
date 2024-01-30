#include <unistd.h>
#include "main.h"
/**
 * print_char - helper function that prints char
 * @c: char to be printed
 * Return: char
 */
int print_char(char c)
{
return (write(1, &c, 1));
}
#include <stdio.h>

int main() {
print_char("Hello, world!\n");
return (0);
}
