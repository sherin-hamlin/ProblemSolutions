/*
File: mergeSortedArray.c
Problem: Merge Two Sorted Arrays (nums2 into nums1)

Approach Used:
Two Pointers from the End

- Inputs:
      nums1 with size m + n (first m elements valid)
      nums2 with n elements
- Start from the end of both arrays:
      i = m - 1 (last element of nums1)
      j = n - 1 (last element of nums2)
      k = m + n - 1 (last position in nums1)
- Compare nums1[i] and nums2[j]:
      - Place the larger at nums1[k]
      - Move pointers accordingly
- Copy remaining elements of nums2 (if any) into nums1

Time Complexity:
O(m + n)
- Each element processed once

Space Complexity:
O(1)
- In-place merge, no extra array used
*/

void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n) {

    int i = m - 1;
    int j = n - 1;
    int k = m + n - 1;

    while (i >= 0 && j >= 0) {
        if (nums1[i] > nums2[j]) {
            nums1[k] = nums1[i];
            i--;
        } else {
            nums1[k] = nums2[j];
            j--;
        }
        k--;
    }

    while (j >= 0) {
        nums1[k] = nums2[j];
        j--;
        k--;
    }
}