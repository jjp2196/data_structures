# include <iostream>
# include <stdio.h>
# include <vector>
using namespace std;

/*
You are given a linked list. Reverse the order of the questions 
within the linked list.
*/

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// Part 1: Iterative Solution

class Solution {
public:
    ListNode* reverseList(ListNode* head) {

        // Keep track of previous node
        ListNode* prev_node = NULL;
        ListNode* current_node = head;

        while(current_node) {
            /*
            ListNode* temp = current_node->next;: 
            This pointer (temp) is used to temporarily 
            store the next node in the original list. 
            We need to do this because once we change the 
            next pointer of current_node, we will lose 
            the reference to the next node. 
            So, we save it in next_node temporarily.
            */
            ListNode* temp = current_node->next; // This is the pointer to next

            /* Initially, current_node->next points to 
            the next node in the original list, 
            but by setting it to prev_node, 
            it now points to the previous node 
            in the reversed list. 
            This effectively detaches current_node 
            from the original list and attaches 
            it to the reversed list. 
            */ 
            
            current_node->next = prev_node;

            // now, we reset the current node as the previous node
            prev_node = current_node;

            // finally, we save the next node as the current node
            current_node = temp;
        }

        return prev_node;
    }
};