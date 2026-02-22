/*
Problem: Median of Two Sorted Arrays

Approach Used:
Binary Search on the smaller array using partition logic.
We divide both arrays into left and right halves such that:
- All elements on the left side are smaller than or equal to
  all elements on the right side.
- The total number of elements on the left side equals
  the total number on the right side (or differs by 1 for odd length).

Time Complexity:
O(log(min(m, n)))
Binary search is performed only on the smaller array.

Space Complexity:
O(1)
Only constant extra variables are used.
*/

#include <limits.h>

double findMedianSortedArrays(int* nums1, int nums1Size, 
                              int* nums2, int nums2Size) {
    
    if (nums1Size > nums2Size)
        return findMedianSortedArrays(nums2, nums2Size, nums1, nums1Size);
    
    int m = nums1Size;
    int n = nums2Size;
    
    int low = 0, high = m;
    
    while (low <= high) {
        
        int cut1 = (low + high) / 2;
        int cut2 = (m + n + 1) / 2 - cut1;
        
        int L1 = (cut1 == 0) ? INT_MIN : nums1[cut1 - 1];
        int R1 = (cut1 == m) ? INT_MAX : nums1[cut1];
        
        int L2 = (cut2 == 0) ? INT_MIN : nums2[cut2 - 1];
        int R2 = (cut2 == n) ? INT_MAX : nums2[cut2];
        
        if (L1 <= R2 && L2 <= R1) {
            
            if ((m + n) % 2 == 0) {
                return ( (double)( (L1 > L2 ? L1 : L2) +
                                   (R1 < R2 ? R1 : R2) ) ) / 2;
            } else {
                return (double)(L1 > L2 ? L1 : L2);
            }
        }
        else if (L1 > R2) {
            high = cut1 - 1;
        }
        else {
            low = cut1 + 1;
        }
    }
    
    return 0.0;
}