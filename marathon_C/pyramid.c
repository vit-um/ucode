#include <unistd.h>
#include <stdlib.h>

char EOL = 10;

void mx_pyramid(int n);


void mx_pyramid(int n);

int main (int argc, char* argv[]) {
	if (argc == 2) {
		mx_pyramid(atoi(argv[1]));
	}
	else
		return 1;
}



void mx_pyramid(int n) {

if (n % 2 == 0 && n > 1){
	int ln = n * 2;
	int h = n;
	char pyr[h][ln];

	// base of pyramid
	pyr[h - 1][0] = '/';
	pyr[h - 1][ln - 1] = '|';
	pyr[h - 1][ln - 2] = '\\';
	for (int j = 1; j < ln - 2; j++)
		pyr[h - 1][j] = '_';

	// back of pyramid

	for (int i = h - 2; i >= n / 2; i--)
	{
		pyr[i][ln - 1] = '|';
		for (int j = 0; j < ln - 1; j++)
		{
			if (j == h - i - 1)
				pyr[i][j] = '/';
			else if (ln - j - 2 == h - i - 1)
				pyr[i][j] = '\\';
			else
				pyr[i][j] = ' ';
		}
	}

	// top of pyramid

	for (int j = 0; j < ln - 1; j++)
	{
		if (j == ln / 2 - 1)
			pyr[0][j] = '/';
		else if (j == ln / 2)
			pyr[0][j] = '\\';
		else if (j < ln / 2 - 1 )
			pyr[0][j] = ' ';
		else
			pyr[0][j] = 0;
	}

	// middle part of pyramid


	for (int i = h / 2 - 1, zad = 1; i > 0; i--, zad += 2)
	{
		for (int j = 0; j < ln; j++)
		{
			if (j == h - i - 1)
				pyr[i][j] = '/';
			else if (ln - j - 2 == h - i - 1)
				pyr[i][j] = '\\';
			else if (j == ln - zad - 1)
				pyr[i][j] = '\\';
			else if (j <= ln - zad - 1)
				pyr[i][j] = ' ';
			else
				pyr[i][j] = 0;

		}
	}

	for (int i = 0; i < h; i++){
		for (int j = 0; j < ln; j++){
     		if (pyr[i][j] != 0)
     			write (1, &pyr[i][j], 1);
		}
		write (1, &EOL, 1);
	}

}
}
