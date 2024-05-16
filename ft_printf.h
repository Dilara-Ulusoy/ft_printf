#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

// Function prototypes for custom print functions
int ft_printnbr(int n);          // Should return the number of characters printed
int ft_printchar(char c);        // Should return the number of characters printed
int ft_printstr(const char *s);  // Should return the number of characters printed
int ft_printfloat(double d);     // Should return the number of characters printed (implement this)
int ft_printhex(unsigned int x); // Should return the number of characters printed
int ft_printptr(void *p);        // Should return the number of characters printed (implement this)
void ft_putchar(char c);          // Should return the number of characters printed (typically 1)
int formats(va_list args, const char *format);
int ft_printf(const char *s, ...);

# endif