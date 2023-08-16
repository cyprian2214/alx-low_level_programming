#include "function_pointers.h"
#include <stdio.h>
#include <stdlib.h>
#include "3-calc.h"

/**
 * main - Entry point of the program.
 * @argc: Number of arguments.
 * @argv: Array of pointers to the arguments.
 *
 * Return: 0 (Success).
 */
int main(int argc, char *argv[])
{
    int num1, num2, result;
    int (*func_ptr)(int, int);

    if (argc != 4)
    {
        printf("Error\n");
        return (98);
    }

    num1 = atoi(argv[1]);
    num2 = atoi(argv[3]);

    func_ptr = get_op_func(argv[2]);
    if (func_ptr == NULL)
    {
        printf("Error\n");
        return (99);
    }

    if ((*argv[2] == '/' || *argv[2] == '%') && num2 == 0)
    {
        printf("Error\n");
        return (100);
    }

    result = func_ptr(num1, num2);
    printf("%d\n", result);

    return (0);
}
