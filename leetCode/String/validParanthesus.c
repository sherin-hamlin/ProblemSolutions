/*
File: isValid.c
Problem: Valid Parentheses

Approach Used:
Stack Simulation

- Use a stack to track opening brackets: '(', '{', '['
- Iterate over the string:
      - If char is opening bracket → push onto stack
      - If char is closing bracket → 
            - If stack is empty → invalid
            - Pop top and check if matches corresponding opening
- At end, stack must be empty for valid string

Time Complexity:
O(n)
- Each character is pushed/popped at most once

Space Complexity:
O(n)
- Stack can grow up to size n
*/

#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

bool isValid(char* s) {
    
    int n = strlen(s);
    
    char* stack = (char*)malloc(n * sizeof(char));
    int top = -1;
    
    for (int i = 0; i < n; i++) {
        
        char ch = s[i];
        
        // If opening bracket → push
        if (ch == '(' || ch == '{' || ch == '[') {
            stack[++top] = ch;
        }
        else {
            // If stack empty → invalid
            if (top == -1) {
                free(stack);
                return false;
            }
            
            char open = stack[top--];
            
            if ((ch == ')' && open != '(') ||
                (ch == '}' && open != '{') ||
                (ch == ']' && open != '[')) {
                
                free(stack);
                return false;
            }
        }
    }
    
    bool valid = (top == -1);
    free(stack);
    return valid;
}