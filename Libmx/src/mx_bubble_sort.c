#include "libmx.h"

int mx_bubble_sort(int *arr, int size) {
    int swp = 0;
	int tmp;
    for (int i = 1; i < size; i++)
		for (int j = 1; j <= size - i; j++)
			if (arr[j-1] > arr[j]) {
			tmp = arr[j];
			arr[j] = arr[j-1];
			arr[j-1] = tmp;
			swp++;
			}
    return swp;
}
