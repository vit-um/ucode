#include "ush.h"

int q_count_operation(const char *arr) {
    int counter = 0;

    if (arr) {
        for (int i = 0; arr[i + 1] != '\0'; i++) {
            if (arr[i] == '&' && arr[i + 1] == '&') {
                counter++;
            } else if (arr[i] == '|' && arr[i + 1] == '|') {
                counter++;
            }
        }
    }
    return counter;
}
