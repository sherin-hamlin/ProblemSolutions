/*
File: integerToRoman.c
Problem: Integer to Roman

Approach Used:
Greedy Algorithm

- Maintain parallel arrays of:
    1) Roman values (largest to smallest)
    2) Corresponding Roman symbols
- Iterate from largest value to smallest.
- While num >= value:
      append symbol
      subtract value from num
- Continue until num becomes 0.

Time Complexity:
O(1)
Maximum Roman length is bounded (num <= 3999).

Space Complexity:
O(1)
Result length is limited (max ~15 characters).
*/

#include <stdlib.h>
#include <string.h>

char* intToRoman(int num) {
    
    int values[] = {1000, 900, 500, 400, 100, 90, 50, 40,
                    10, 9, 5, 4, 1};
    
    char *symbols[] = {"M","CM","D","CD","C","XC","L","XL",
                       "X","IX","V","IV","I"};
    
    // Max Roman length for 3999 is less than 20
    char* result = (char*)malloc(20 * sizeof(char));
    result[0] = '\0';

    for (int i = 0; i < 13; i++) {
        while (num >= values[i]) {
            strcat(result, symbols[i]);
            num -= values[i];
        }
    }

    return result;
}