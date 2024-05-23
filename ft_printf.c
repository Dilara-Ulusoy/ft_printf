
# include "ft_printf.h"

int ft_printf(const char *s, ...)
{
    va_list args; //va_list is a type to hold information about variable arguments.
    va_start(args, s); //Simply put, it initializes the va_list variable to point to the first variable argument which is the last known fixed parameter (s in this case).
    int count = 0; //This variable will be used to count the number of characters printed.
    int i = 0;

 while (s[i])
 {
    if (s[i] == '%')
    {
        i++;
        count += formats(args, s[i]);  
        if (count < 0)
		return (-1);
    } 
    else 
    {
        count += ft_printchar(s[i]);
        if (count < 0)
		return (-1);
    }
    i++;
}
    va_end(args);
    if (count < 0)
		return (-1);
    return count;
}

int formats(va_list args, const char format)
{
    int count = 0;
        if (format == 'd' || format == 'i')
            count += ft_printnbr(va_arg(args, int)); 
        else if (format == 'c')
            count += ft_printchar((char)va_arg(args, int));
        else if (format == 's')
            count += ft_printstr(va_arg(args, char *));
        else if (format == 'x')
            count += ft_printhex(va_arg(args, unsigned int), 0);
        else if (format == 'X')
            count += ft_printhex(va_arg(args, unsigned int), 1);
        else if (format == 'u')
            count += ft_printhex(va_arg(args, unsigned int), 0);
        else if (format == 'p')
            count += ft_printptr(va_arg(args, void *));
        else if (format == '%')
            count += ft_printpercent();
        else
            count += ft_printchar(format);
        return count;
    }
    




//va_start initializes the argument list.
//va_arg retrieves each integer passed after the first parameter.
//va_end cleans up the argument list after processing.
//va_copy copies the argument list to another variable.
//cspdiuxX% are the conversion specifiers that can be used with printf.