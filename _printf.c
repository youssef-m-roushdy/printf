#include <stdarg.h>
#include <stdio.h>
#include <string.h>
#include "main.h"

int _printf(const char *format, ...) {
va_list args;
int lenOfString = 0;

va_start(args, format);
while (*format)
{
if (*format == '%')
{
format++;
if (*format == '\0')
{
break;
}
if (*format == 'c')
{
char c = va_arg(args, int);
putchar(c);
lenOfString++;
}
else if (*format == 's')
{
char *str = va_arg(args, char *);
if (str != NULL) {
fputs(str, stdout);
lenOfString += strlen(str);
}
}
else if (*format == 'd' || *format == 'i')
{
int num = va_arg(args, int);
printf("%d", num);
lenOfString += snprintf(NULL, 0, "%d", num);
}
else if (*format == '%') {
putchar('%');
lenOfString++;
}
else
{
putchar(*format);
lenOfString++;
}
}
else
{
putchar(*format);
lenOfString++;
}
format++;
}
va_end(args);
return lenOfString;
}
