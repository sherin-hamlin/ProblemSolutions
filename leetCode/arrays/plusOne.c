/*
File: plusOne.c
Problem: Plus One

Approach Used:
Simulation (Elementary Math)

Traverse the digits array from the end:
- If digit < 9 → increment and return.
- If digit == 9 → set to 0 and carry continues.
- If all digits are 9 → allocate new array with size +1.

Time Complexity:
O(n)
In worst case (all 9s), we traverse the entire array.

Space Complexity:
O(1)
No extra space unless all digits are 9 (then O(n) for new array).
*/

#include <stdlib.h>

int* plusOne(int* digits, int digitsSize, int* returnSize) {
    
    // Traverse from last digit
    for (int i = digitsSize - 1; i >= 0; i--) {
        
        if (digits[i] < 9) {
            digits[i]++;
            *returnSize = digitsSize;
            return digits;
        }
        
        digits[i] = 0;  // carry
    }
    
    // If all digits were 9
    int* result = (int*)malloc((digitsSize + 1) * sizeof(int));
    
    result[0] = 1;
    
    for (int i = 1; i <= digitsSize; i++) {
        result[i] = 0;
    }
    
    *returnSize = digitsSize + 1;
    return result;
}