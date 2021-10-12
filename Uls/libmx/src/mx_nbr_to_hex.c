#include "libmx.h"

char *mx_nbr_to_hex(unsigned long nbr) {
	char* res = NULL;
	int ost, i = 0;
	char ch[19];
	while (nbr) {
		ost = nbr % 16;
		if (ost < 10)
			ch[i] = ost + 48;
		else
			ch[i] = ost + 87;
		nbr /= 16;
		i++;
	}

	res = mx_strnew(i);

	for (int j = i - 1, k = 0; j >= 0; j--, k++) {
        res[k] = ch[j];
    }

	if(res)
		return res;
	return 0;
}
