#include "matrix.h"

int mx_atoi(const char *str)
{
    int result = 0;
    for (int i = 0; str[i] != '\0'; ++i)
    {
        result *= 10;
        result += str[i] - '0';
    }
    return result;
}
int mx_atoichar(const char a)
{
    return a - 48;
}
