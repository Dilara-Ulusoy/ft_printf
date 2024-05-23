#include "ft_printf.h"

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
int ft_printstr(const char *s) {
    int count = 0;
    while (*s) {
        ft_putchar(*s++);
        count++;
    }
    return count; // Returning the number of characters printed
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

int ft_printhex(unsigned int n, int uppercase) //This function is used to print an hexadecimal number and return the number of characters printed.
//Example: ft_printhex(10) will print "a" and return 1. ft_printhex(16) will print "10" and return 2. because 16 in hexadecimal is 10 and it has 2 characters.
//Another example: ft_printhex(255) will print "ff" and return 2. because 255 in hexadecimal is ff and it has 2 characters.
{
    int count = 0;
    if (n >= 16)
    {
        count += ft_printhex(n / 16, uppercase);
    }
    if (n % 16 < 10)
    {
        ft_putchar(n % 16 + '0');
    }
    else
    {
        if(uppercase)
            ft_putchar(n % 16 - 10 + 'A');
        else
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
    count += ft_printhex((unsigned long)p, 1);
    return (count);
}

int ft_printfloat(double d) //This function is used to print a floating point number and return the number of characters printed. 
//Exp: ft_printfloat(3.14) will print "3.140000" and return 8.
{
    int count = 0;
    int i = 0;
    if (d < 0)
    {
        ft_putchar('-');
        d = -d;
        count++;
    }
    count += ft_printnbr((int)d);
    ft_putchar('.');
    count++;
    d -= (int)d; //d = d - (int)d = 3.14 - 3 = 0.14. 
    while(i < 6)
    {
        d *= 10; //d = 0.14 * 10 = 1.4
        count += ft_printnbr((int)d); //count = 4 + 1 = 5, print 1
        d -= (int)d; //d = 1.4 - 1 = 0.4
        i++;    
    }
    return (count);
}

int ft_printpercent(void) //This function is used to print a percent sign and return the number of characters printed.
{
    ft_putchar('%');
    return (1);
}