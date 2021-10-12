#include "libmx.h"

bool mx_islower(int c);
bool mx_isupper(int c);

unsigned long mx_hex_to_nbr(const char *hex) {
    unsigned long dec = 0;
    int tmp = 0;
    int len = mx_strlen(hex) - 1;
    if (hex) {
        while (*hex) {
            if(mx_isdigit(*hex))
                tmp = *hex - 48;
            else if(mx_isalpha(*hex) && mx_islower(*hex))
                tmp = *hex - 97 + 10;
            else if(mx_isalpha(*hex) && mx_isupper(*hex))
                tmp = *hex - 65 + 10;
            else
                return 0;
        dec += tmp * mx_pow(16, len);
        len--;
        hex++;
        }
        return dec;
    }
    else
        return 0;
}


bool mx_isdigit(int c) {
    if (c > 47 && c < 58)
        return 1;
    else
        return 0;
}

bool mx_islower(int c) {
    if (c >= 97 && c <= 122) 
        return 1;
    else 
        return 0;
}

bool mx_isupper(int c) {
    if (c >= 65 && c <= 90) 
        return 1;
    else 
        return 0;
}
