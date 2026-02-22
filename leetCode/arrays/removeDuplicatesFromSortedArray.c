/*
File: removeDuplicatesFromSortedArray.c
Problem: Remove Duplicates from Sorted Array

Approach Used:
Two Pointer Technique.
Use one pointer (i) to track the position of unique elements.
Use another pointer (j) to scan the array.
Whenever a new unique element is found,
place it at the next position of pointer i.

Time Complexity:
O(n)
Each element is visited once.

Space Complexity:
O(1)
Modification is done in-place without extra space.
*/

int removeDuplicates(int* nums, int numsSize) {
    
    if (numsSize == 0)
        return 0;

    int i = 0;

    for (int j = 1; j < numsSize; j++) {
        if (nums[j] != nums[i]) {
            i++;
            nums[i] = nums[j];
        }
    }

    return i + 1;
}