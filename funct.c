#include "main.h"
#include <unistd.h>

#define BUFFER_SIZE 1024

/**
 * _putchar - Writes a character to stdout
 * @c: The character to print
 * Return: On success, 1. On error, -1 is returned, and errno is set appropriately.
 */
int _putchar(char c) {
    static char buf[BUFFER_SIZE];
    static int buf_index = 0;

    if (c == -1 || buf_index >= BUFFER_SIZE) {
        write(1, buf, buf_index);
        buf_index = 0;
    }

    if (c != -1) {
        buf[buf_index] = c;
        buf_index++;
    }

    return 1;
}

/**
 * _puts - Prints a string to stdout
 * @str: Pointer to the string to print
 * Return: The number of characters written.
 */
int _puts(char *str) {
    int char_count = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        if (_putchar(str[i]) == -1) {
            return -1; // Handle write error
        }
        char_count++;
    }

    return char_count;
}
