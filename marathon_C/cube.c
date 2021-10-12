#include <stdlib.h>
#include <unistd.h>

char EOL = 10;

void mx_cube(int n);

int main (int argc, char* argv[]) {
	if (argc == 2) {
		mx_cube(atoi(argv[1]));
	}
	else
		return 1;
}


void mx_cube(int n) {

if (n > 1)
	{
	int ln = 2 * n + 3 + n / 2;
	int h = n + 3 + n / 2;
	char cube[h][ln];

	// top edge of cube

	for (int j = 0; j < ln; j++)
	{
		if (j < n / 2 + 1)
			cube[0][j] = ' ';
		else if (j > n / 2 + 1 && j != ln - 1)
			cube[0][j] = '-';
		else if (j == n / 2 + 1 || j == ln - 1)
			cube[0][j] = '+';
		else
			cube[0][j] = 0;
	}

	// top of cube

	for (int i = 1; i < n / 2 + 1; i++)
	{
		for (int j = 0; j < ln; j++)
		{
			if (j == n / 2 + 1 - i || j == n / 2 + 2 - i + n * 2)
				cube[i][j] = '/';
			else if (j == ln - 1)
				cube[i][j] = '|';
			else
				cube[i][j] = ' ';
		}
	}

	// middle edge of cube

	for (int j = 0; j < ln; j++)
	{
		if (j == 0 || j == n * 2 + 1)
			cube[n / 2 + 1][j] = '+';
		else if (j > 0 && j <= n * 2 + 1)
			cube[n / 2 + 1][j] = '-';
		else if (j == ln - 1)
			cube[n / 2 + 1][j] = '|';
		else
			cube[n / 2 + 1][j] = ' ';
	}

	// bottom edge of cube

	for (int j = 0; j < ln; j++)
	{
		if (j == 0 || j == n * 2 + 1)
			cube[h - 1][j] = '+';
		else if (j > 0 && j <= n * 2 + 1)
			cube[h - 1][j] = '-';
		else
			cube[h - 1][j] = 0;
	}

	// back apex of the cube

	for (int j = 0; j < ln; j++)
	{
		if (j == ln - 1)
			cube[h - n / 2 - 2][j] = '+';
		else if (j == 0 || j == n * 2 + 1)
			cube[h - n / 2 - 2][j] = '|';
		else
			cube[h - n / 2 - 2][j] = ' ';
	}

	// top half the front of cube

	for (int i = n / 2 + 2; i < h - n / 2 - 2; i++)
	{
		for (int j = 0; j < ln; j++)
		{
			if (j == 0 || j == n * 2 + 1 || j == ln - 1)
				cube[i][j] = '|';
			else
				cube[i][j] = ' ';
		}
	}

	// bottom half the front of cube

	for (int i = h - n / 2 - 1; i < h - 1; i++)
	{
		for (int j = 0; j < ln; j++)
		{
			if (j == 0 || j == n * 2 + 1)
				cube[i][j] = '|';
			else if (j == 2 * n + h - i)
				cube[i][j] = '/';
			else if (j > 2 * n + h - i)
				cube[i][j] = 0;
			else
				cube[i][j] = ' ';
		}
	}

	// Print model
		for (int i = 0; i < h; i++){
			for (int j = 0; j < ln; j++){
    			if (cube[i][j] != 0)
					write (1, &cube[i][j], 1);
			}
			write (1, &EOL , 1);
		}
	}
}

