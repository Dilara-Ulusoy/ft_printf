#include "ft_printf.h"

// This function is used to print a string and return the number of characters printed. If s terminates with '\0', it will return the number of characters printed + 1.
int	ft_printstr(char *str)
{
	int	count;

	count = 0;
	if (str == NULL)
		return (write(1, "(null)", 6));
	while (str[count])
	{
		write (1, &str[count], 1);
		count++;
	}
	if (count < 0)
		return (-1);
	return (count);
}

int ft_printchar(char c) //This function is used to print a character and return the number of characters printed.
{
    write(1, &c, 1);
    return (1);
}

int	ft_printnbr(int nb)
{
	int	count;

	count = 0;
	if (nb == -2147483648)
		count += ft_printstr("-2147483648");
	else if (nb < 0)
	{
		count += ft_printchar('-');
		nb = -nb;
		count += ft_printnbr(nb);
	}
	else
	{
		if (nb >= 10)
		{
			count += ft_printnbr(nb / 10);
			count += ft_printnbr(nb % 10);
		}
		else
            count += ft_printchar(nb + '0');
	}
	ft_itoa(nb);
	if (count < 0)
		return (-1);
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
        ft_printchar(n % 16 + '0');
    }
    else
    {
        if(uppercase)
            ft_printchar(n % 16 - 10 + 'A');
        else
            ft_printchar(n % 16 - 10 + 'a');
    }
    count++;
    return (count);
}

int ft_printptr(void *p) //This function is used to print a pointer and return the number of characters printed.
{
    int count = 0;
    ft_printstr("0x");
    count += 2;
    count += ft_printhex((unsigned long)p, 1);
    return (count);
}

int ft_printpercent(void) //This function is used to print a percent sign and return the number of characters printed.
{
    ft_printchar('%');
    return (1);
}