/*
File: romanToInt.c
Problem: Convert Roman Numeral to Integer

Approach Used:
Greedy / Left-to-Right Scan

- Map Roman characters to integer values:
      I=1, V=5, X=10, L=50, C=100, D=500, M=1000
- Iterate through the string s:
      - If current value < next value → subtract current (special case: IV, IX)
      - Else → add current
- Sum all values to get the integer equivalent

Time Complexity:
O(n)
- n = length of the Roman numeral string

Space Complexity:
O(1)
- Only integer variables used
*/

#include <string.h>

int value(char c) {
    switch(c) {
        case 'I': return 1;
        case 'V': return 5;
        case 'X': return 10;
        case 'L': return 50;
        case 'C': return 100;
        case 'D': return 500;
        case 'M': return 1000;
    }
    return 0;
}

int romanToInt(char* s) {
    
    int total = 0;
    int n = strlen(s);
    
    for (int i = 0; i < n; i++) {
        
        int curr = value(s[i]);
        int next = 0;
        
        if (i + 1 < n)
            next = value(s[i + 1]);
        
        if (curr < next)
            total -= curr;
        else
            total += curr;
    }
    
    return total;
}