#include "main.h"

typedef int (*func_t)(va_list);

int _putchar(char c)
{
    return (write(1, &c, 1));
}

int print_char(va_list args)
{
    char c = va_arg(args, int);
    _putchar(c);
    return (1);
}

int print_string(va_list args)
{
    int count = 0;
    char *str = va_arg(args, char *);

    if (str == NULL)
        str = "(null)";

    while (*str)
    {
        _putchar(*str);
        str++;
        count++;
    }
    return (count);
}

int print_percent(va_list args)
{
    (void)args;
    _putchar('%');
    return (1);
}

int print_number(va_list args)
{
    int num = va_arg(args, int);
    int count = 0;
    int temp = num;
    int divisor = 1;

    if (num < 0)
    {
        _putchar('-');
        count++;
        num = -num;
    }

    while (temp / 10)
    {
        divisor *= 10;
        temp /= 10;
    }

    while (divisor)
    {
        _putchar((num / divisor) + '0');
        num %= divisor;
        divisor /= 10;
        count++;
    }
    return (count);
}

int _printf(const char *format, ...)
{
    int count = 0;
    va_list args;
    int i = 0;

    func_t funcs[256] = {NULL};

    funcs['c'] = print_char;
    funcs['s'] = print_string;
    funcs['%'] = print_percent;
    funcs['d'] = print_number;
    funcs['i'] = print_number;

    va_start(args, format);
    if (format == NULL)
        return (-1);

    while (format[i])
    {
        if (format[i] == '%' && funcs[(int)format[i + 1]] != NULL)
        {
            count += funcs[(int)format[i + 1]](args);
            i++;
        }
        else
        {
            _putchar(format[i]);
            count++;
        }
        i++;
    }
    va_end(args);
    return (count);
}
