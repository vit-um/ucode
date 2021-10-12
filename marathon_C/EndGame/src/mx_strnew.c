#include <header.h>

char *mx_strnew(const int size)
{
    if (size > 0) {
        char *strnew = malloc(size + 1);

        for (int i = 0; i <= size; i++)
        {
            strnew[i] = '\0';
        }

        return strnew;   
    }

    return NULL;
}
