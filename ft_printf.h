#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>

int ft_printnbr(int nb);          // Should return the number of characters printed
int ft_printchar(char c);        // Should return the number of characters printed
int ft_printstr(char *str);  // Should return the number of characters printed
int ft_printhex(unsigned long long n, int uppercase); // Should return the number of characters printed
int ft_printptr(void *p);        // Should return the number of characters printed
int ft_printpercent(void);       // Should return the number of characters printed          // Should return the number of characters printed (typically 1)
int ft_printunsigned(unsigned int n);
int formats(va_list *args, const char format);
int ft_printf(const char *s, ...);

# endif