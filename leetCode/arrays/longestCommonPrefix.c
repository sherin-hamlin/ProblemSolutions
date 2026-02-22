/*
File: longestCommonPrefix.c
Problem: Longest Common Prefix

Approach Used:
Vertical Scanning.
Compare characters column-wise starting from the first string.
For each character position, check whether all other strings
have the same character at that position.
Stop when mismatch occurs.

Time Complexity:
O(n * m)
n = number of strings
m = length of shortest string

Space Complexity:
O(1)
Only constant extra space is used (fixed prefix array).
*/

#include <stdio.h>
#include <string.h>

char* longestCommonPrefix(char** strs, int strsSize) {

    if (strsSize == 0)
        return "";

    static char prefix[201];
    int i = 0;

    while (strs[0][i] != '\0') {

        char current = strs[0][i];

        for (int j = 1; j < strsSize; j++) {
            if (strs[j][i] == '\0' || strs[j][i] != current) {
                prefix[i] = '\0';
                return prefix;
            }
        }

        prefix[i] = current;
        i++;
    }

    prefix[i] = '\0';
    return prefix;
}