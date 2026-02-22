/*
Problem: Two Sum

Approach Used:
Brute Force – Check every pair using nested loops.
For each element, compare it with all remaining elements
to see if their sum equals the target.

Time Complexity:
O(n^2)

Space Complexity:
O(1)
*/

#include <stdlib.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
    int* result = (int*)malloc(2 * sizeof(int));
    *returnSize = 2;

    for (int i = 0; i < numsSize - 1; i++) {
        for (int j = i + 1; j < numsSize; j++) {
            
            if (nums[i] + nums[j] == target) {
                result[0] = i;
                result[1] = j;
                return result;
            }
        }
    }
    
    return result;
}