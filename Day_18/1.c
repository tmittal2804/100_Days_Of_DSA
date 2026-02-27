//Problem: Given an array of integers, rotate the array to the right by k positions.

#include <stdio.h>

void reverse(int arr[], int start, int end) {
    while (start < end) {
        int temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;
        start++;
        end--;
    }
}

int main() {
    int n, k;
    
    if (scanf("%d", &n) != 1) return 0;
    
    int arr[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    
    if (scanf("%d", &k) != 1) return 0;

    k = k % n;
    if (k < 0) k += n; 

    if (k > 0) {
        reverse(arr, 0, n - 1);
        reverse(arr, 0, k - 1);
        reverse(arr, k, n - 1);
    }

    for (int i = 0; i < n; i++) {
        printf("%d%c", arr[i], (i == n - 1 ? '\n' : ' '));
    }

    return 0;
}