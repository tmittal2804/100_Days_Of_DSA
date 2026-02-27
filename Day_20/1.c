//Problem: Given an array of integers, count the number of subarrays whose sum is equal to zero.

#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b) {
    long long arg1 = *(const long long *)a;
    long long arg2 = *(const long long *)b;
    if (arg1 < arg2) return -1;
    if (arg1 > arg2) return 1;
    return 0;
}

int main() {
    int n;
    if (scanf("%d", &n) != 1) return 0;

    int *arr = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    long long *sums = (long long *)malloc((n + 1) * sizeof(long long));
    long long current_prefix_sum = 0;
    sums[0] = 0;

    for (int i = 0; i < n; i++) {
        current_prefix_sum += arr[i];
        sums[i + 1] = current_prefix_sum;
    }

    qsort(sums, n + 1, sizeof(long long), compare);

    long long zero_sum_count = 0;
    long long frequency = 1;

    for (int i = 1; i <= n; i++) {
        if (sums[i] == sums[i - 1]) {
            frequency++;
        } else {
            zero_sum_count += (frequency * (frequency - 1)) / 2;
            frequency = 1;
        }
    }
    zero_sum_count += (frequency * (frequency - 1)) / 2;

    printf("%lld\n", zero_sum_count);

    free(arr);
    free(sums);

    return 0;
}