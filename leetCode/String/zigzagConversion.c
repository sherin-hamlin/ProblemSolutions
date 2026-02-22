/*
File: zigzagConversion.c
Problem: Zigzag Conversion

Approach Used:
Mathematical Pattern (Cycle Simulation)

- A full zigzag cycle length is:
      cycle = 2 * numRows - 2

- For each row:
    1) Pick vertical characters at intervals of `cycle`
    2) For middle rows, also pick diagonal characters:
           diagonal = j + cycle - 2 * row

- First and last rows only have vertical elements.

Time Complexity:
O(n)
Each character is visited once.

Space Complexity:
O(n)
New result string is created.
*/

#include <stdlib.h>
#include <string.h>

char* convert(char* s, int numRows) {

    if (numRows == 1)
        return s;

    int len = strlen(s);

    if (numRows >= len)
        return s;

    char* result = (char*)malloc((len + 1) * sizeof(char));
    int index = 0;

    int cycle = 2 * numRows - 2;

    for (int row = 0; row < numRows; row++) {

        for (int j = row; j < len; j += cycle) {

            // Vertical element
            result[index++] = s[j];

            // Diagonal element (not first or last row)
            int diagonal = j + cycle - 2 * row;

            if (row != 0 && row != numRows - 1 && diagonal < len) {
                result[index++] = s[diagonal];
            }
        }
    }

    result[index] = '\0';
    return result;
}