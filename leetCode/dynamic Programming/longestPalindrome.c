/*
File: longestPalindrome.c
Problem: Longest Palindromic Substring

Approach Used:
Expand Around Center Technique

- A palindrome mirrors around its center.
- Each character can act as:
      1) Center of an odd-length palindrome (aba)
      2) Left center of an even-length palindrome (abba)
- For every index:
      expand outward while characters match.
- Track:
      start index of longest palindrome
      maximum length found
- Extract substring using strncpy.

Time Complexity:
O(n^2)
For each character, we may expand up to O(n).

Space Complexity:
O(1)
Only constant extra variables used.
(Result space not counted in auxiliary space.)
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