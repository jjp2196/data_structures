# include <iostream>

using namespace std;

/*
You are given the heads of two sorted 
linked lists, list1 and list2.

Merge the two lists into one sorted list. 
The list should be made by splicing together 
the nodes of the first two lists.

Return the head of the merged linked list.

Example 1:

Input: list1 = [1,2,4], list2 = [1,3,4]
Output: [1,1,2,3,4,4]
*/

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        
        // Case 1: Either of the list head nodes returns NULL
        
        if (list1 == NULL) {
            return list2;
        }

        if (list2 == NULL) {
            return list1;
        }

        // Case 2: List1 Head is less than List2 Head
        // That's good, so apply mergeTwoLists recursively 
        // assigning list1.next as linking list1.next and list 2
        // Then, return list1 so you can do it again if needed

        if (list1->val <= list2->val) {
            list1->next = mergeTwoLists(list1->next, list2);
            return list1;
        }

        // Case 1: List2 Head is less than List1 Head
        // That's good, so apply mergeTwoLists recursively 
        // assigning list2.next as linking list1 and list2.next
        // Then, return list2 so you can do it again if needed

        else {
            list2-> next = mergeTwoLists(list1, list2 -> next);
            return list2;
        }

        // This should work through every possible list 
        // again and again, returning heads until the lists 
        // are fully linked together
    }
};