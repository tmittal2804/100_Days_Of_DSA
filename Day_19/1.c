//Problem: Given an array of integers, find two elements whose sum is closest to zero.

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int compare(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

int main() {
    int n;
    if (scanf("%d", &n) != 1 || n < 2) return 0;

    int arr[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    qsort(arr, n, sizeof(int), compare);

    int left = 0, right = n - 1;
    int min_sum = INT_MAX;
    int res_left = 0, res_right = n - 1;

    while (left < right) {
        int sum = arr[left] + arr[right];

        if (abs(sum) < abs(min_sum)) {
            min_sum = sum;
            res_left = left;
            res_right = right;
        }

        if (sum < 0) {
            left++;
        } else if (sum > 0) {
            right--;
        } else {
            break;
        }
    }

    printf("%d %d\n", arr[res_left], arr[res_right]);

    return 0;
}