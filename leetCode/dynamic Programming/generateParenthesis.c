/*
File: generateParenthesis.c
Problem: Generate All Combinations of Well-Formed Parentheses

Approach Used:
Backtracking / Recursive Construction

- Keep track of:
      1) Number of open '(' used
      2) Number of close ')' used
      3) Current string being built
- Rules:
      - Add '(' if open < n
      - Add ')' if close < open
- When current string length == 2*n, store it in result.
- Uses recursion to explore all valid combinations.

Time Complexity:
O(4^n / sqrt(n)) 
Catalan number of valid combinations.

Space Complexity:
O(n) recursion stack + O(Catalan(n) * n) for result storage
*/

#include <stdlib.h>
#include <string.h>

void backtrack(char** result, int* returnSize, 
               char* current, int pos, 
               int open, int close, int n) {
    
    if (pos == 2 * n) {
        current[pos] = '\0';
        result[*returnSize] = strdup(current);
        (*returnSize)++;
        return;
    }

    if (open < n) {
        current[pos] = '(';
        backtrack(result, returnSize, current, pos + 1, open + 1, close, n);
    }

    if (close < open) {
        current[pos] = ')';
        backtrack(result, returnSize, current, pos + 1, open, close + 1, n);
    }
}

char** generateParenthesis(int n, int* returnSize) {
    
    *returnSize = 0;
    
    int capacity = 1500; // enough for n <= 8
    char** result = (char**)malloc(capacity * sizeof(char*));
    
    char* current = (char*)malloc((2 * n + 1) * sizeof(char));
    
    backtrack(result, returnSize, current, 0, 0, 0, n);
    
    return result;
}