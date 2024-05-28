#include "ft_printf.h"
#include <stdio.h>

    
int main(void)
{ printf("---------------Character--------------------\n");
    int c = printf("%c", 'A');
    printf("\nCount of characters: %d\n", c);
    ft_printf("My function: %c\n", 'A');
    printf("Library function: %c\n", 'A');
   printf("---------------String--------------------\n");
    int b = printf("%s", "Hello World");
    printf("\nCount of characters: %d\n", b);
    ft_printf("My function: %s %%%s\n", "Hello","Wolrd");
    printf("Library function: %s %%%s\n", "Hello","Wolrd");
    printf("---------------Integer--------------------\n");
    int a = printf("%d", 123); 
    printf("\nCount of characters: %d\n", a);
    ft_printf("My function: %d\n", 123);
    printf("Library function: %d\n", 123);
   printf("---------------Pointer--------------------\n");
    int z = 5;
    int *p = &z;
    ft_printf("My function %p\n", p);
    printf("Library function %p\n", p);
   printf("---------------Hexadecimal--------------------\n");
   int x = ft_printf("%X", 2550);
   printf("\nCount of characters: %X\n", x);
   ft_printf("My function %X\n", 2550);
   printf("Library function %X\n",2550);
   printf("---------------Negative Hexadecimal--------------------\n");
   int t = ft_printf("%X", -2550);
   printf("\nCount of characters: %X\n", t);
   ft_printf("My function %X\n", -2550);
   printf("Library function %X\n",-2550);
   
	return 0;
}
