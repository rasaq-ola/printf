# printf

This is an implementation of the `printf` function in C. It supports the following conversion specifiers:
- `%c` for characters
- `%s` for strings
- `%%` for the percent symbol
- `%d` and `%i` for integers

## Usage

To use this `printf` implementation, include `main.h` and compile your code with the provided `_printf.c` file.

```c
#include "main.h"

int main(void)
{
    _printf("Character: %c\n", 'A');
    _printf("String: %s\n", "Hello, World!");
    _printf("Percent: %%\n");
    _printf("Integer: %d\n", 123);
    return (0);
}
