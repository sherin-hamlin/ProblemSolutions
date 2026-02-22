/*
File: mySqrt.c
Problem: Compute the Integer Square Root of a Number

Approach Used:
Binary Search

- Base cases:
      x < 2 → return x
- Initialize search range:
      low = 1, high = x / 2
- While low <= high:
      - mid = low + (high - low)/2
      - If mid*mid <= x → mid is a candidate, try higher
      - Else → mid is too big, search lower
- Return last valid mid

Time Complexity:
O(log x)
- Each iteration halves the search space

Space Complexity:
O(1)
- Only a few integer variables used
*/

int mySqrt(int x) {
    
    if (x < 2)
        return x;
    
    int low = 1;
    int high = x / 2;
    int ans = 0;
    
    while (low <= high) {
        int mid = low + (high - low) / 2;
        
        if (mid <= x / mid) {
            ans = mid;        // possible answer
            low = mid + 1;    // try bigger
        } else {
            high = mid - 1;   // too big
        }
    }
    
    return ans;
}