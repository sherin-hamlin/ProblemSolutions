/*
File: addTwoNumbers.c
Problem: Add Two Numbers Represented by Linked Lists

Approach Used:
Linked List Iterative Addition with Carry

- Input: Two non-empty linked lists l1 and l2
      - Digits stored in reverse order
- Use a dummy head to simplify list construction
- Initialize carry = 0
- While l1 or l2 is not null or carry != 0:
      - sum = carry + l1.val + l2.val
      - carry = sum / 10
      - Create new node with val = sum % 10
      - Append to result list
- Return dummy.next as the head of the resulting list

Time Complexity:
O(max(m, n))
- m, n = lengths of the input lists

Space Complexity:
O(max(m, n))
- New nodes created for the result list
*/

#include <stdlib.h>

// Definition for singly-linked list.
struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    
    struct ListNode dummy;  
    dummy.next = NULL;
    
    struct ListNode* temp = &dummy;
    int carry = 0;
    
    while (l1 != NULL || l2 != NULL || carry != 0) {
        
        int sum = carry;
        
        if (l1 != NULL) {
            sum += l1->val;
            l1 = l1->next;
        }
        
        if (l2 != NULL) {
            sum += l2->val;
            l2 = l2->next;
        }
        
        carry = sum / 10;
        
        struct ListNode* newNode = 
            (struct ListNode*)malloc(sizeof(struct ListNode));
        
        newNode->val = sum % 10;
        newNode->next = NULL;
        
        temp->next = newNode;
        temp = temp->next;
    }
    
    return dummy.next;
}