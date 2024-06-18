#include "main.h"

/**
 * _puts - writes a string to stdout
 * @str: The string to print
 * Return: On success, the number of characters printed. On error, -1.
 */
int _puts(char *str)
{
    int i;

    if (str == NULL)
        return (-1);

    for (i = 0; str[i] != '\0'; i++)
    {
        if (write(1, &str[i], 1) == -1)
        {
            return (-1); /* Handle write error */
        }
    }
    return (i);
}
