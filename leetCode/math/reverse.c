/*
File: reverse.c
Problem: Reverse Integer

Approach Used:
Iterative Digit Reversal with Overflow Check

- Extract digits one by one from the input number
- Build the reversed number: rev = rev * 10 + digit
- Before each multiplication/addition, check for overflow:
      - If rev > INT_MAX/10 or rev == INT_MAX/10 and digit > 7 → overflow
      - If rev < INT_MIN/10 or rev == INT_MIN/10 and digit < -8 → overflow
- Return 0 if overflow occurs

Time Complexity:
O(log10(x))
- Each iteration processes one digit

Space Complexity:
O(1)
- Only integer variables used
*/

#include <limits.h>

int reverse(int x) {
    int rev = 0;

    while (x != 0) {
        int digit = x % 10;
        x /= 10;

        // Check for overflow
        if (rev > INT_MAX / 10 || (rev == INT_MAX / 10 && digit > 7))
            return 0;

        if (rev < INT_MIN / 10 || (rev == INT_MIN / 10 && digit < -8))
            return 0;

        rev = rev * 10 + digit;
    }

    return rev;
}