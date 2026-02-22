/*
File: longestPalindromicSubstring.c
Problem: Longest Palindromic Substring

Approach Used:
Expand Around Center

- A palindrome mirrors around its center.
- Each index can be:
    1) Center of an odd-length palindrome
    2) Left center of an even-length palindrome
- Expand outward while characters match.
- Track starting index and maximum length.

Time Complexity:
O(n^2)
For each character, we expand up to O(n).

Space Complexity:
O(1)
No extra space except result string.
*/

#include <string.h>
#include <stdlib.h>

char* longestPalindrome(char* s) {
    
    int n = strlen(s);
    
    if (n < 2)
        return s;
    
    int start = 0;
    int maxLen = 1;
    
    for (int i = 0; i < n; i++) {
        
        // ----- Odd length palindrome -----
        int left = i;
        int right = i;
        
        while (left >= 0 && right < n && s[left] == s[right]) {
            
            int currLen = right - left + 1;
            
            if (currLen > maxLen) {
                start = left;
                maxLen = currLen;
            }
            
            left--;
            right++;
        }
        
        // ----- Even length palindrome -----
        left = i;
        right = i + 1;
        
        while (left >= 0 && right < n && s[left] == s[right]) {
            
            int currLen = right - left + 1;
            
            if (currLen > maxLen) {
                start = left;
                maxLen = currLen;
            }
            
            left--;
            right++;
        }
    }
    
    char* result = (char*)malloc(maxLen + 1);
    strncpy(result, s + start, maxLen);
    result[maxLen] = '\0';
    
    return result;
}