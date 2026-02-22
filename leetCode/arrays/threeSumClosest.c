/*
File: threeSumClosest.c
Problem: 3Sum Closest

Approach Used:
Sorting + Two Pointer Technique.
First sort the array.
Fix one element and use two pointers (left and right)
to find a triplet whose sum is closest to the target.
Update the closest value whenever a smaller difference is found.

Time Complexity:
O(n^2)
Sorting takes O(n log n),
Two pointer traversal for each element takes O(n).

Space Complexity:
O(1)
Only constant extra variables are used.
*/

#include <stdlib.h>
#include <math.h>

int compare(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

int threeSumClosest(int* nums, int numsSize, int target) {
    
    qsort(nums, numsSize, sizeof(int), compare);
    
    int closest = nums[0] + nums[1] + nums[2];

    for (int i = 0; i < numsSize - 2; i++) {
        
        int left = i + 1;
        int right = numsSize - 1;

        while (left < right) {
            
            int sum = nums[i] + nums[left] + nums[right];

            if (abs(sum - target) < abs(closest - target)) {
                closest = sum;
            }

            if (sum < target) {
                left++;
            } 
            else if (sum > target) {
                right--;
            } 
            else {
                return sum;
            }
        }
    }

    return closest;
}