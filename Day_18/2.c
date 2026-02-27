// Given an integer array nums, return an array answer such that answer[i] is equal to the product of all the elements of nums except nums[i].The product of any prefix or suffix of nums is guaranteed to fit in a 32-bit integer.You must write an algorithm that runs in O(n) time and without using the division operation.

#include <stdio.h>
#include <stdlib.h>

int* productExceptSelf(int* nums, int numsSize, int* returnSize) {
    int* res = (int*)malloc(numsSize * sizeof(int));
    *returnSize = numsSize;

    res[0] = 1;
    for (int i = 1; i < numsSize; i++) {
        res[i] = res[i - 1] * nums[i - 1];
    }

    int suffix = 1;
    for (int i = numsSize - 1; i >= 0; i--) {
        res[i] *= suffix;
        suffix *= nums[i];
    }

    return res;
}