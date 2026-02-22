/*
File: removeElement.c
Problem: Remove Element

Approach Used:
Two Pointer Technique.
Use one pointer (i) to track the position of elements
that are NOT equal to val.
Traverse the array using another pointer (j).
Whenever nums[j] != val, place it at nums[i] and increment i.

Time Complexity:
O(n)
Each element is checked once.

Space Complexity:
O(1)
Modification is done in-place without extra space.
*/

int removeElement(int* nums, int numsSize, int val) {
    
    int i = 0;

    for (int j = 0; j < numsSize; j++) {
        if (nums[j] != val) {
            nums[i] = nums[j];
            i++;
        }
    }

    return i;
}