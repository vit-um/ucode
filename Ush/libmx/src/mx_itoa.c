#include "libmx.h"

char *mx_itoa(int number) {
    int i, sign;
    char* res = NULL;
    char s[20];

    if ((sign = number) < 0) {
        if (number == -2147483648) {
            number = -(number + 1);
        }
        else {
            number = -number;
        }
    }
    
    i = 0;

    while (number > 0) {
        s[i++] = number % 10 + '0';
        number /= 10;
    }
    
    if (sign == 0) 
        s[i++] = '0';

    if (sign < 0) {
        s[i++] = '-';
        if (sign == -2147483648)
            s[0] = 8 + '0';
    }


    res = mx_strnew(i + 1);

	for (int j = i - 1, k = 0; j >= 0; j--, k++) {
        res[k] = s[j];
    }
    res[i] = '\0';

	if(res)
		return res;
	return 0;
}
