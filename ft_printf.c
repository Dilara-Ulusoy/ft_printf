
#include <stdarg.h>

//va_start initializes the argument list.
//va_arg retrieves each integer passed after the first parameter.
//va_end cleans up the argument list after processing.
//va_copy copies the argument list to another variable.
//cspdiuxX% are the conversion specifiers that can be used with printf.

int ft_printf(const char *str, ...)
{
    va_list args;
    va_start(args, str);
    int count = 0;
    int i = 0;

    while(str[i])
    {
        if(str[i] != '%')
        {
            ft_putchar(str[i]);
            i++;
            count++;
        }
        else
        {
            count += formats(args, str[i + 1]);
        }
        i++;
    }
    va_end(args);
    return count;
}

int formats(va_list args, const char *format)
{
    int count = 0;
    while (*format)
    {
        if (*format == '%')
        {
            format++;
            if (*format == 'd' || *format == 'i')
                count += ft_printnbr(va_arg(args, int));
            else if (*format == 'c')
                count += ft_printchar((char)va_arg(args, int));
            else if (*format == 's')
                count += ft_printformat(va_arg(args, char *));
            else if (*format == 'f')
                count += ft_printfloat(va_arg(args, double));
            else if (*format == 'x')
                count += ft_printhex(va_arg(args, unsigned int));
            else if (*format == 'X')
                count += ft_printhex(va_arg(args, unsigned int));
            else if (*format == 'u')
                count += ft_printhex(va_arg(args, unsigned int));
            else if (*format == 'p')
                count += ft_printptr(va_arg(args, void *));
            else if (*format == '%')
                count += ft_putchar('%');
        }
        else
            count += ft_putchar(*format);
        format++;
    }
    return count;
}




//Varargs fonksiyonlar, değişken sayıda argüman alabilen fonksiyonlardır. Bu tür fonksiyonlar, C dilinde standart olarak desteklenir.
//Varargs fonksiyonlar aslinda bir linked list gibi calisir. Fonksiyonun aldigi ilk arguman, fonksiyonun ne kadar arguman alacagini belirler.
//Bu argumanlar, va_list veri türüne sahip bir degiskene atanir. Bu degisken, va_start fonksiyonu ile baslatilir.

#va_list ne icin kullanilir?
//va_list, bir fonksiyonun değişken sayıda argüman almasını sağlar. Örneğin, printf fonksiyonu, değişken sayıda argüman alır.
//va_list, stdarg.h başlık dosyasında tanımlanmıştır. Bu başlık dosyası, değişken sayıda argüman almak için kullanılan makroları içerir.
//Mesela prinf fonksiyonu, bir arguman örnegi olarak, format formatingi ve format formatingindeki degiskenlerin degerlerini alir.
//Bu degerlerin alinmasi icin va_list kullanilir.

#va_start ne icin kullanilir?
//va_start, bir fonksiyonun değişken sayıda argüman almasını sağlar. Bu fonksiyon, va_list veri türüne sahip bir değişkeni başlatır.
//örnegin va_start(args, format); fonksiyonu, args adında bir va_list veri türüne sahip bir değişkeni başlatır. 
//Format ise, fonksiyonun aldığı ilk argümandır.

#va_arg ne icin kullanilir?
//va_arg, va_list veri türüne sahip bir değişkenin değerini alır. Bu fonksiyon, va_list veri türüne sahip bir değişkeni ve alınacak değerin veri türünü alır.
//Printf fonksiyonunda kullanılan va_arg fonksiyonu, va_list veri türüne sahip bir değişkeni ve alınacak değerin veri türünü alır.
//Bir örnek kod parçası: int a = va_arg(args, int); Bu kod parçası, args adında bir va_list veri türüne sahip bir değişkeni ve alınacak değerin veri türünü alır.
//Bu kod parçası, args adında bir va_list veri türüne sahip bir değişkenin değerini alır ve bu değeri int veri türünde bir değişkene atar.
//Yani va_arg fonksiyonu printf fonksiyonunda belirtilen değişkenlerin değerlerini almak için kullanılır.


#va_end ne icin kullanilir?
//va_end, va_start fonksiyonu ile başlatılan va_list veri türüne sahip bir değişkeni temizler. Bu fonksiyon, va_list veri türüne sahip bir değişkeni temizler.
//Örneğin, va_end(args); fonksiyonu, args adında bir va_list veri türüne sahip bir değişkeni temizler. Bu fonksiyon, va_start fonksiyonu ile başlatılan va_list veri türüne sahip bir değişkeni temizler.


