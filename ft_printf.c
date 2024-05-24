
# include "ft_printf.h"

int ft_printf(const char *s, ...)
{
    if (!s)
        return -1;
    va_list args; //va_list is a type to hold information about variable arguments.
    va_start(args, s); //Simply put, it initializes the va_list variable to point to the first variable argument which is the last known fixed parameter (s in this case).
    int count;
    int i;
    
    count = 0; //This variable will be used to count the number of characters printed.
    i = 0;
    while (s[i])
    {
    if (s[i] == '%')
    {
        i++; // skip the % character
        int res = formats(&args, s[i]);
        if (res < 0)
            return -1; 
        count = count + res;
    }  
    else {
        int res = ft_printchar(s[i]);
        if (res < 0)
            return -1; 
        count = count + res;
    }
    i++;
}
    va_end(args);
    if (count < 0)
        return -1;
    return count;
}

int formats(va_list *args, const char format)
{
    int count;

    count = 0;
    if (format == 'd' || format == 'i')
        count += ft_printnbr(va_arg(*args, int)); 
    else if (format == 'c')
        count += ft_printchar((char)va_arg(*args, int));
    else if (format == 's')
        count += ft_printstr(va_arg(*args, char *));
    else if (format == 'x')
        count += ft_printhex(va_arg(*args, unsigned int), 0);
    else if (format == 'X')
        count += ft_printhex(va_arg(*args, unsigned int), 1);
    else if (format == 'u')
        count += ft_printunsigned(va_arg(*args, unsigned int));
    else if (format == 'p')
        count += ft_printptr(va_arg(*args, void *));
    else if (format == '%')
        count += ft_printpercent();
    else
        return -1;
    if (count < 0)
        return -1; // Propagate the error
    return count;
}
    
