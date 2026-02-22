/*
File: longestSubstringWithoutRepeatingCharacters.c
Problem: Longest Substring Without Repeating Characters

Approach Used:
Sliding Window + Hash Table (ASCII index array)

- Maintain a window using two pointers: left and right.
- Use an array `lastSeen[256]` to store the last index of each character.
- If a character repeats within the current window,
  move `left` to one position after its last occurrence.
- Track the maximum window length.

Time Complexity:
O(n)
Each character is processed at most once.

Space Complexity:
O(1)
Fixed-size array of 256 (constant space).
*/

#include <string.h>

int lengthOfLongestSubstring(char* s) {

    int lastSeen[256];

    // Initialize all positions to -1
    for (int i = 0; i < 256; i++)
        lastSeen[i] = -1;

    int maxLen = 0;
    int left = 0;

    for (int right = 0; s[right] != '\0'; right++) {

        if (lastSeen[(unsigned char)s[right]] >= left) {
            left = lastSeen[(unsigned char)s[right]] + 1;
        }

        lastSeen[(unsigned char)s[right]] = right;

        int currLen = right - left + 1;

        if (currLen > maxLen)
            maxLen = currLen;
    }

    return maxLen;
}