/*
File: strStr.c
Problem: Find the Index of the First Occurrence in a String

Approach Used:
Brute Force Substring Search

- Input: haystack (main string), needle (substring)
- If needle is empty, return 0
- Iterate through haystack, for each index i:
      - Compare characters with needle
      - If all characters match, return i
- If needle not found, return -1

Time Complexity:
O(n * m)
- n = length of haystack
- m = length of needle

Space Complexity:
O(1)
- Only indices and counters used
*/

#include <string.h>

int strStr(char* haystack, char* needle) {
    
    int n = strlen(haystack);
    int m = strlen(needle);
    
    if (m == 0) return 0;
    
    for (int i = 0; i <= n - m; i++) {
        int j = 0;
        while (j < m && haystack[i + j] == needle[j]) {
            j++;
        }
        if (j == m) {
            return i;
        }
    }
    
    return -1;
}