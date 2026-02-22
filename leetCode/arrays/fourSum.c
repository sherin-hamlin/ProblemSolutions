/*
File: fourSum.c
Problem: 4Sum

Approach Used:
Sorting + Nested Loops + Two Pointer Technique.
First sort the array.
Fix the first two elements using two loops.
Use two pointers (left and right) to find remaining two elements.
Skip duplicates to avoid repeated quadruplets.
Dynamic resizing is used to expand result storage if needed.

Time Complexity:
O(n^3)
Sorting takes O(n log n),
Two nested loops + two pointer traversal results in O(n^3).

Space Complexity:
O(1) auxiliary space
(Excluding space used for storing the result)
*/

#include <stdlib.h>

int compare(const void* a, const void* b) {
    long x = *(int*)a;
    long y = *(int*)b;
    if (x > y) return 1;
    if (x < y) return -1;
    return 0;
}

int** fourSum(int* nums, int numsSize, int target, int* returnSize, int** returnColumnSizes) {
    
    *returnSize = 0;
    if (numsSize < 4)
        return NULL;

    qsort(nums, numsSize, sizeof(int), compare);

    int capacity = 1000;
    int** result = (int**)malloc(capacity * sizeof(int*));
    *returnColumnSizes = (int*)malloc(capacity * sizeof(int));

    for (int i = 0; i < numsSize - 3; i++) {

        if (i > 0 && nums[i] == nums[i - 1])
            continue;

        for (int j = i + 1; j < numsSize - 2; j++) {

            if (j > i + 1 && nums[j] == nums[j - 1])
                continue;

            int left = j + 1;
            int right = numsSize - 1;

            while (left < right) {

                long sum = (long)nums[i] + nums[j] + nums[left] + nums[right];

                if (sum == target) {

                    if (*returnSize >= capacity) {
                        capacity *= 2;
                        result = realloc(result, capacity * sizeof(int*));
                        *returnColumnSizes = realloc(*returnColumnSizes, capacity * sizeof(int));
                    }

                    result[*returnSize] = (int*)malloc(4 * sizeof(int));
                    result[*returnSize][0] = nums[i];
                    result[*returnSize][1] = nums[j];
                    result[*returnSize][2] = nums[left];
                    result[*returnSize][3] = nums[right];
                    (*returnColumnSizes)[*returnSize] = 4;
                    (*returnSize)++;

                    while (left < right && nums[left] == nums[left + 1])
                        left++;

                    while (left < right && nums[right] == nums[right - 1])
                        right--;

                    left++;
                    right--;
                }
                else if (sum < target) {
                    left++;
                }
                else {
                    right--;
                }
            }
        }
    }

    return result;
}