/*
File: threeSum.c
Problem: 3Sum

Approach Used:
Sorting + Two Pointer Technique.
First sort the array.
Fix one element and use two pointers (left and right)
to find pairs whose sum equals the negative of the fixed element.
Skip duplicates to avoid repeated triplets.

Time Complexity:
O(n^2)
Sorting takes O(n log n),
Two pointer traversal for each element takes O(n).

Space Complexity:
O(1) auxiliary space
(Excluding space used for storing the result)
*/

#include <stdlib.h>

int compare(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

int** threeSum(int* nums, int numsSize, int* returnSize, int** returnColumnSizes) {
    *returnSize = 0;

    if (numsSize < 3)
        return NULL;

    qsort(nums, numsSize, sizeof(int), compare);

    int maxTriplets = numsSize * numsSize;
    int **result = (int**)malloc(maxTriplets * sizeof(int*));
    *returnColumnSizes = (int*)malloc(maxTriplets * sizeof(int));

    for (int i = 0; i < numsSize - 2; i++) {

        if (i > 0 && nums[i] == nums[i - 1])
            continue;

        int left = i + 1;
        int right = numsSize - 1;

        while (left < right) {

            int sum = nums[i] + nums[left] + nums[right];

            if (sum == 0) {
                result[*returnSize] = (int*)malloc(3 * sizeof(int));
                result[*returnSize][0] = nums[i];
                result[*returnSize][1] = nums[left];
                result[*returnSize][2] = nums[right];

                (*returnColumnSizes)[*returnSize] = 3;
                (*returnSize)++;

                while (left < right && nums[left] == nums[left + 1])
                    left++;

                while (left < right && nums[right] == nums[right - 1])
                    right--;

                left++;
                right--;
            }
            else if (sum < 0) {
                left++;
            }
            else {
                right--;
            }
        }
    }

    return result;
}