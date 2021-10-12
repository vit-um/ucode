void mx_printchar(char c);

void mx_printint(int n) {
    int i = 0, k =0;
    char s[11];
    if  (n < 0) {
        mx_printchar('-');
        if (n == -2147483648)
            k = 1;
        n = -n-k;
    }
    while (n > 0) {
        s[i] = n % 10;
	n = n / 10;
	i++;
    }
    if (n % 10 == 0 && i == 0)
        mx_printchar('0');
    else {
        s[0] = s[0] + k;
        for (int m = i - 1; m >= 0; m--)
        mx_printchar(s[m] + '0');
    }
}
