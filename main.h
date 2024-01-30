#ifndef MAIN_H
#define MAIN_H
#include <stdarg.h>

int print_char(char c);
int print_string(char *str);
int print_decimal(int n);
int print_hex(unsigned int n, int uppercase);
int print_unsigned(unsigned int n);
int print_octal(unsigned int n);
int print_pointer(void *ptr);
int print_format(const char *format, va_list args);
int _printf(const char *format, ...);

#endif /* MAIN_H */
