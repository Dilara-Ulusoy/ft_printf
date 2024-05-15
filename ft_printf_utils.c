#include <unistd.h>
#include <stdarg.h>

void ft_putchar(char c)
{
    write(1, &c, 1);
}

void ft_putstr(char *s)
{
    while (*s)
    {
        ft_putchar(*s);
        s++;
    }
}

// This function is used to print a string and return the number of characters printed. If s terminates with '\0', it will return the number of characters printed + 1.
int ft_printstr(char *s) 
{
    int count = 0;
    while (*s)
    {
        ft_putchar(*s);
        s++;
        count++;
    }
    return (count);
}

int ft_printchar(char c) //This function is used to print a character and return the number of characters printed.
{
    ft_putchar(c);
    return (1);
}

int ft_printnbr(int n) //This function is used to print an integer and return the number of characters printed
{
    int count = 0;
    if (n < 0)
    {
        ft_putchar('-');
        n = -n;
        count++;
    }
    if (n >= 10)
    {
        count += ft_printnbr(n / 10);
    }
    ft_putchar(n % 10 + '0');
    count++;
    return (count);
}

int ft_printhex(unsigned int n) //This function is used to print an hexadecimal number and return the number of characters printed.
//Example: ft_printhex(10) will print "a" and return 1. ft_printhex(16) will print "10" and return 2. because 16 in hexadecimal is 10 and it has 2 characters.
//Another example: ft_printhex(255) will print "ff" and return 2. because 255 in hexadecimal is ff and it has 2 characters.
{
    int count = 0;
    if (n >= 16)
    {
        count += ft_printhex(n / 16);
    }
    if (n % 16 < 10)
    {
        ft_putchar(n % 16 + '0');
    }
    else
    {
        ft_putchar(n % 16 - 10 + 'a');
    }
    count++;
    return (count);
}
int ft_printptr(void *p) //This function is used to print a pointer and return the number of characters printed.
{
    int count = 0;
    ft_putstr("0x");
    count += 2;
    if ((unsigned long long)p >= 16)
    {
        count += ft_printhex((unsigned long long)p / 16);
    }
    ft_printhex((unsigned long long)p % 16);
    count++;
    return (count);
}