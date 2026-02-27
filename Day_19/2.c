/*Given a circular integer array nums of length n, return the maximum possible sum of a non-empty subarray of nums.
A circular array means the end of the array connects to the beginning of the array. Formally, the next element of nums[i] is nums[(i + 1) % n] and the previous element of nums[i] is nums[(i - 1 + n) % n].A subarray may only include each element of the fixed buffer nums at most once. Formally, for a subarray nums[i], nums[i + 1], ..., nums[j], there does not exist i <= k1, k2 <= j with k1 % n == k2 % n.
 */
 
#include <stdio.h>
#include <stdlib.h>

int maxSubarraySumCircular(int* nums, int numsSize) {
    int total_sum = 0;
    int max_kadane = nums[0];
    int min_kadane = nums[0];
    int cur_max = 0;
    int cur_min = 0;

    for (int i = 0; i < numsSize; i++) {
        total_sum += nums[i];

        cur_max += nums[i];
        if (cur_max > max_kadane) max_kadane = cur_max;
        if (cur_max < 0) cur_max = 0;

        cur_min += nums[i];
        if (cur_min < min_kadane) min_kadane = cur_min;
        if (cur_min > 0) cur_min = 0;
    }

    if (total_sum == min_kadane) {
        return max_kadane;
    }

    int circular_max = total_sum - min_kadane;
    return (max_kadane > circular_max) ? max_kadane : circular_max;
}