#include <unistd.h>

/**
 * print_pointer - helper function to print pointer address for 64 bit
 * @ptr: The pointer address to be printed
 *
 * Return: The number of characters printed
 */
int print_pointer(void *ptr)
{
uintptr_t address = (uintptr_t)ptr;
char hex_digits[] = "0123456789abcdef";
char buffer[18];  /* Assuming a 64-bit system */
if (ptr == NULL)
{
return (print_string("(nil)"));
}
buffer[0] = '0';
buffer[1] = 'x';
int i;
for (i = 15; i >= 2; i--)
{
buffer[i] = hex_digits[address & 0xf];
address >>= 4;
}
buffer[16] = '\0';
return (write(1, buffer, 17));
}
