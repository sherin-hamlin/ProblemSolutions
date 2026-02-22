/*
File: lengthOfLastWord.c
Problem: Length of the Last Word in a String

Approach Used:
Reverse Traversal

- Traverse the string from the end:
      1) Skip trailing spaces
      2) Count characters until a space or start of string
- Return the counted length

Time Complexity:
O(n)
- n = length of the string

Space Complexity:
O(1)
- Only a few integer variables used
*/

#include <string.h>

int lengthOfLastWord(char* s) {
    
    int n = strlen(s);
    int length = 0;
    int i = n - 1;
    
    // Step 1: Skip trailing spaces
    while (i >= 0 && s[i] == ' ') {
        i--;
    }
    
    // Step 2: Count characters of last word
    while (i >= 0 && s[i] != ' ') {
        length++;
        i--;
    }
    
    return length;
}