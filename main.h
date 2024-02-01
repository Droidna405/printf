#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>

#define UNUSED(x) (void)(x)
#define BUFF_SIZE 1024

/* flags */
#define F_MINUS 1
#define F_PLUS 2
#define F_ZERO 4
#define F_HASH 8
#define F_SPACE 16

#define S_LONG 2
#define S_SHORT 1

/**
 * struct fmt - struct op
 *
 * @fmt: the format
 * @fn: function associated
 */
struct fmt
{
char fmt;
int (*fn)(va_list, char[], int, int, int, int);
};

/**
 * typedef struct fmt fmt_t - struct op
 *
 * @fmt: The format
 * @fn: the function associated
 */
typedef struct fmt fmt_t;

int _printf(const char *format, ...);
int handle_print(const char *fmt, int *i,
va_list list, char buffer[],
		 int flags, int width, int precision, int size);

/* to print char and str */
int print_char(va_list data, char buffer[],
	       int flags, int width, int precision, int size);
int print_string(va_list data, char buffer[],
		 int flags, int width, int precision, int size);
int print_percent(va_list data, char buffer[],
		  int flags, int width, int precision, int size);

/* to print int */
int print_int(va_list data, char buffer[],
	      int flags, int width, int precision, int size);
int print_binary(va_list data, char buffer[],
		 int flags, int width, int precision, int size);
int _unsigned_p(va_list types, char buffer[],
	       int flags, int width, int precision, int size);
int octal_p(va_list types, char buffer[],
	    int flags, int width, int precision, int size);
int hex_p(va_list types, char buffer[],
	  int flags, int width, int precision, int size);
int print_hex_uppercase(va_list types, char buffer[],
			int flags, int width, int precision, int size);

int print_hex(va_list types, char map_to[],
	      char buffer[],
	      int flags, char flag_ch, int width, int precision, int size);

/* to print non-printable chars */
int print_not_printable(va_list types, char buffer[],
			int flags, int width, int precision, int size);

/* to print pointers addresses */
int pointer_p(va_list types, char buffer[],
	      int flags, int width, int precision, int size);

/* other specifiers */
int flags_p(const char *format, int *i);
int width_p(const char *format, int *l, va_list arg);
int precision_p(const char *format, int *i, va_list list);
int size_p(const char *format, int *i);

/* reverse string */
int reverse_p(va_list types, char buffer[],
		  int flags, int width, int precision, int size);

/* rotstr13 encrtyp print */
int rotstr13_p(va_list types, char buffer[],
	       int flags, int width, int precision, int size);

/* width handler */
int handle_char(char c, char buffer[],
		int flags, int width, int precision, int size);
int handle_number(int is_positive, int ind, char buffer[],
		  int flags, int width, int precision, int size);
int handle_num(int ind, char bff[],
	       int flags, int width, int precision,
	       int length, char padd, char extra_c);
int handle_pointer(char buffer[],
		   int ind, int length, int width,
		   int flags, char padd, char extra_c, int padd_start);

int handle_unsigned_(int is_negative, int ind, char buffer[],
		    int flags, int width, int precision);

int _printable(char);
int hex_append(char, char[], int);
int _digit(char);

long int number_convert_size(long int num, int size);
long int _unsigned_convert_size(unsigned long int num, int size);

#endif /* MAIN_H  */
