#include <stdarg.h>
#include <stdio.h>


int _printf(const char *format, ...)
{
    int len;
    va_list args;
    va_start(args, format);

    len = 0;
    while (*format) {
        if (*format == '%') {
            format++;
            if (*format == 'd' || *format == 'i')
            {
                printf("%d", va_arg(args, int));
                len++;
            }
            else if(*format == 'u')
            {
                printf("%u", va_arg(args, unsigned int));
                len++;
            }
            else if(*format == 'o')
            {
                printf("%o", va_arg(args, unsigned int));
                len++;
            }
            else if(*format == 'x')
            {
                printf("%x", va_arg(args, unsigned int));
                len++;
            }
            else if(*format == 'X')
            {
                printf("%X", va_arg(args, unsigned int));
                len++;
            }
            else if(*format == 'p')
            {
                printf("%p", va_arg(args, void *));
                len++;
            }
            else if (*format == 's')
            {
                printf("%s", va_arg(args, char *));
                len++;
            }
            else if (*format == 'c')
            {
                putchar(va_arg(args, int));
                len++;
            }
            else if (*format == 'c')
            {
                putchar(va_arg(args, int));
                len++;
            }
	    else if (*format == 'r')
            {
                printf("%r");
                len++;
            }
            else
            {
                putchar(*format);
                len++;
            }
        }
        else
        {
            putchar(*format);
            len++;
        }
        format++;
    }

    va_end(args);
    return len;
}
