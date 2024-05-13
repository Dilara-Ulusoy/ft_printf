

//va_start initializes the argument list.
//va_arg retrieves each integer passed after the first parameter.
//va_end cleans up the argument list after processing.
//va_copy copies the argument list to another variable.
//cspdiuxX% are the conversion specifiers that can be used with printf.

int printf(const char *format, ...)
{
    va_list args; // Va_list bir veri türüdür ve bu veri türü bir fonksiyonun değişken sayıda argüman almasını sağlar.
    va_start(args, format); // Va_start fonksiyonu, bir fonksiyonun değişken sayıda argüman almasını sağlar. Bu fonksiyon, va_list veri türüne sahip bir değişkeni başlatır. For

    while (*format)
    {
        if(*format == '%')
        {
            format++;
        }
        if (*format == 'd' || *format == 'i')
        {
            int i = va_arg(args, int);
            write(1, &i, 1);
        }
        else if (*format == 'c')
        {
            char c = va_arg(args, int);
            printf("%c", c);
        }
        else if (*format == 's')
        {
            char *s = va_arg(args, char *);
            printf("%s", s);
        }
        else if (*format == 'f')
        {
            double d = va_arg(args, double);
            printf("%f", d);
        }
        else if (*format == 'x')
        {
            int x = va_arg(args, int);
            printf("%x", x);
        }
        else if (*format == 'X')
        {
            int X = va_arg(args, int);
            printf("%X", X);
        }
        else if (*format == 'u')
        {
            unsigned int u = va_arg(args, unsigned int);
            printf("%u", u);
        }
        else if (*format == 'p')
        {
            void *p = va_arg(args, void *);
            printf("%p", p);
        }
        else if (*format == '%')
        {
            printf("%%");

        }
        format++;
    }
    va_end(args);
}





//Varargs fonksiyonlar, değişken sayıda argüman alabilen fonksiyonlardır. Bu tür fonksiyonlar, C dilinde standart olarak desteklenir.
//Varargs fonksiyonlar aslinda bir linked list gibi calisir. Fonksiyonun aldigi ilk arguman, fonksiyonun ne kadar arguman alacagini belirler.
//Bu argumanlar, va_list veri türüne sahip bir degiskene atanir. Bu degisken, va_start fonksiyonu ile baslatilir.

#va_list ne icin kullanilir?
//va_list, bir fonksiyonun değişken sayıda argüman almasını sağlar. Örneğin, printf fonksiyonu, değişken sayıda argüman alır.
//va_list, stdarg.h başlık dosyasında tanımlanmıştır. Bu başlık dosyası, değişken sayıda argüman almak için kullanılan makroları içerir.
//Mesela prinf fonksiyonu, bir arguman örnegi olarak, format stringi ve format stringindeki degiskenlerin degerlerini alir.
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


