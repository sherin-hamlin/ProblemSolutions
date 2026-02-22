/*
File: isPalindrome.c
Problem: Check if an Integer is a Palindrome

Approach Used:
Reverse Half of the Number

- Negative numbers are not palindromes
- Numbers ending with 0 (except 0 itself) are not palindromes
- Reverse only half of the digits:
      - While x > reversedHalf:
            reversedHalf = reversedHalf * 10 + last digit of x
            remove last digit from x
- Check if first half equals reversed second half:
      - For odd digits, ignore middle digit: x == reversedHalf/10
      - For even digits: x == reversedHalf

Time Complexity:
O(log10 x)
- Each iteration removes one digit from x

Space Complexity:
O(1)
- No extra space used
*/

#include <stdbool.h>

bool isPalindrome(int x) {
    
    if (x < 0 || (x % 10 == 0 && x != 0))
        return false;
    
    int reversedHalf = 0;
    
    while (x > reversedHalf) {
        reversedHalf = reversedHalf * 10 + x % 10;
        x /= 10;
    }
    
    return (x == reversedHalf || x == reversedHalf / 10);
}