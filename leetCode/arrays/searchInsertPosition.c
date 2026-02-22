/*
File: searchInsertPosition.c
Problem: Search Insert Position

Approach Used:
Binary Search.
Since the array is sorted, apply binary search.
If target is found, return its index.
If not found, return the position where it should be inserted.
The insertion position will be the final value of 'low'.

Time Complexity:
O(log n)
Binary search halves the search space each iteration.

Space Complexity:
O(1)
Only constant extra variables are used.
*/

int searchInsert(int* nums, int numsSize, int target) {
    
    int low = 0;
    int high = numsSize - 1;
    
    while (low <= high) {
        
        int mid = low + (high - low) / 2;
        
        if (nums[mid] == target)
            return mid;
        else if (nums[mid] < target)
            low = mid + 1;
        else
            high = mid - 1;
    }
    
    return low;
}