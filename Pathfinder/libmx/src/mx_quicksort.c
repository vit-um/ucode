#include "libmx.h"

static void swap(int *i1, int *i2, int *count) {
    int tmp = *i1;
    *i1 = *i2;
    *i2 = tmp;
    ++*count;
}
//  Algorithm 1
int mx_quicksort(int *arr, int l, int r) {
    int count = 0;
    int pivot;
    int left = l;
    int right = r;

    if (!arr)
        return -1;
    
    pivot = arr[r];

    for (right -= 1; left < right; swap(&arr[left++], &arr[right--], &count)) {
        for (; arr[left] <= pivot && left < r; ++left);
        for (; arr[right] > pivot; --right);
        if (left >= right)
            break;
    }
    if (arr[left] > pivot)
        swap(&arr[left], &arr[r], &count);
        
    if (right > l)
        count += mx_quicksort(arr, l, right);
    if (left + 1 < r)
        count += mx_quicksort(arr, left + 1, r);
    return count;
}

//  Algorithm 2
// int mx_quicksort(int *arr, int left, int right) {
//     if (!arr) 
//         return -1;
//     if (left == right)
//         return 0;
//     int count = 0;
//     int beg = left, end = right;
//     int pivot = arr[end];
//     while (beg <= end) {
//         while (arr[beg] < pivot)
//             beg++;
//         while (arr[end] > pivot)
//             end--;
//         if (beg <= end) {
//             if (arr[beg] != arr[end])
//                 swap(&arr[beg], &arr[end], &count);
//             //     tmp = arr[beg];
//             //     arr[beg] = arr[end];
//             //     arr[end] = tmp;
//             //     count++;    
//             // }
//             beg++;
//             end--;
//         }
//     if (left < end)
//         count += mx_quicksort(arr, left, end);
//     if (right > beg)
//         count += mx_quicksort(arr, beg, right);
//     }
//     return count;
// }
