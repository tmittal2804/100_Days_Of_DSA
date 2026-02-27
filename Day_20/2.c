//Given an integer array nums, return all the triplets [nums[i], nums[j], nums[k]] such that i != j, i != k, and j != k, and nums[i] + nums[j] + nums[k] == 0.

#include <stdlib.h>

int compare(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

int** threeSum(int* nums, int numsSize, int* returnSize, int** returnColumnSizes) {
    qsort(nums, numsSize, sizeof(int), compare);
    int** res = (int**)malloc(sizeof(int*) * (numsSize * numsSize));
    *returnColumnSizes = (int*)malloc(sizeof(int) * (numsSize * numsSize));
    *returnSize = 0;

    for (int i = 0; i < numsSize - 2; i++) {
        if (i > 0 && nums[i] == nums[i - 1]) continue;

        int low = i + 1, high = numsSize - 1;
        while (low < high) {
            int sum = nums[i] + nums[low] + nums[high];
            if (sum == 0) {
                res[*returnSize] = (int*)malloc(sizeof(int) * 3);
                res[*returnSize][0] = nums[i];
                res[*returnSize][1] = nums[low];
                res[*returnSize][2] = nums[high];
                (*returnColumnSizes)[*returnSize] = 3;
                (*returnSize)++;

                while (low < high && nums[low] == nums[low + 1]) low++;
                while (low < high && nums[high] == nums[high - 1]) high--;
                low++;
                high--;
            } else if (sum < 0) {
                low++;
            } else {
                high--;
            }
        }
    }
    return res;
}