#include "ft_printf.h"


int ft_printchar(char c) //This function is used to print a character and return the number of characters printed.
{
		int result;
		result = write(1, &c, 1);
		if(result < 0)
			return (-1);
		return (1);
}

int ft_printstr(char *str) //This function is used to print a string and return the number of characters printed.
{
    int count = 0;
	int result;

    if (!str)
        str = "(null)";
    while (*str)
    {
        result = ft_printchar(*str);
		if (result < 0)
			return (-1);
		count += result;
        str++;
    }
	if (count < 0)
		return (-1);
    return count;
}

int	ft_printnbr(int nb) 
{
	int	count;

	count = 0;
	if (nb == -2147483648)
	{
		write(1, "-2147483648", 11);
		count = 11;
	}
	else if (nb < 0)
	{
		count += ft_printchar('-');
		nb = -nb;
		count += ft_printnbr(nb);
	}
	else if (nb > 9)
	{
		count += ft_printnbr(nb / 10);
		count += ft_printnbr(nb % 10);
	}
	else
	{
		count += ft_printchar(nb + '0');
	}
	if (count < 0)
		return (-1);
	return (count);
}

int ft_printhex(unsigned long long n, int uppercase) {
    int count = 0;
    if (n >= 16) {
        count += ft_printhex(n / 16, uppercase);
    }
    unsigned int digit = n % 16;
    if (digit < 10) {
        ft_printchar(digit + '0');
    } else {
        if (uppercase) {
            ft_printchar(digit - 10 + 'A');
        } else {
            ft_printchar(digit - 10 + 'a');
        }
    }
    count++;
    return count;
}

int ft_printptr(void *p) {
    int count = 0;

    count += ft_printstr("0x");
    count += ft_printhex((unsigned long long)p, 0);  // Pass the pointer cast to unsigned long long
    return count;
}

int ft_printunsigned(unsigned int n) //This function is used to print an unsigned integer and return the number of characters printed.
{
	int count = 0;
	if (n >= 10)
	{
		count += ft_printunsigned(n / 10);
	}
	ft_printchar(n % 10 + '0');
	count++;
	if (count < 0)
		return (-1);
	return (count);
}

int ft_printpercent(void) //This function is used to print a percent sign and return the number of characters printed.
{
    int count = 0;
	count = ft_printchar('%');
	if (count < 0)
		return (-1);
    return (count);
}