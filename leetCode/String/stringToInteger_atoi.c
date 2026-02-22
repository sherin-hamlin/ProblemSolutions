/*
File: stringToInteger_atoi.c
Problem: String to Integer (atoi)

Approach Used:
Step-by-step parsing with overflow handling

Steps:
1. Skip leading whitespaces
2. Detect optional sign (+ / -)
3. Convert consecutive digits
4. Stop at first non-digit character
5. Clamp result within INT_MIN and INT_MAX

Overflow Handling:
Before multiplying result by 10:
    If result > INT_MAX / 10
    OR
    result == INT_MAX / 10 and digit > 7
Then overflow occurs.

Time Complexity:
O(n)
Single pass through the string.

Space Complexity:
O(1)
Constant extra space.
*/

#include <limits.h>

int myAtoi(char* s) {
    int i = 0;
    int sign = 1;
    int result = 0;

    // 1. Skip leading spaces
    while (s[i] == ' ') {
        i++;
    }

    // 2. Check sign
    if (s[i] == '-' || s[i] == '+') {
        if (s[i] == '-') {
            sign = -1;
        }
        i++;
    }

    // 3. Convert digits
    while (s[i] >= '0' && s[i] <= '9') {
        int digit = s[i] - '0';

        // 4. Check overflow
        if (result > INT_MAX / 10 ||
           (result == INT_MAX / 10 && digit > 7)) {

            if (sign == 1)
                return INT_MAX;
            else
                return INT_MIN;
        }

        result = result * 10 + digit;
        i++;
    }

    return result * sign;
}