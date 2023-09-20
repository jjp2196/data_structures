# include <iostream>
# include <stdio.h>
# include <vector>
using namespace std;

/*
You are given two non-empty linked lists representing 
two non-negative integers. The digits are stored in 
reverse order, and each of their nodes contains a single 
digit. Add the two numbers and return the sum as a linked list.

You may assume the two numbers do not contain any leading zero, 
except the number 0 itself.

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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        
        ListNode* final_list = new ListNode();
        ListNode* temp = final_list;
        int carry = 0;

        while (l1 || l2 || carry) {
            int sum = 0;

            if (l1) {
                sum += l1->val;
                l1 = l1->next;
            }

            if (l2) {
                sum += l2->val;
                l2 = l2->next;
            }

            sum += carry;

            carry = sum/10;
            ListNode *node = new ListNode(sum % 10);
            temp->next = node;
            temp = temp->next;
        }
        return final_list -> next;
    }
};

void deleteLinkedList(ListNode* head) {
    while (head != nullptr) {
        //ListNode* current = head;
        //head = head->next;
        //delete current;
    }
}

int main() {
    // Create two linked lists representing the numbers
    ListNode* l1 = new ListNode(2);
    l1->next = new ListNode(4);
    l1->next->next = new ListNode(3);

    ListNode* l2 = new ListNode(5);
    l2->next = new ListNode(6);
    l2->next->next = new ListNode(4);

    // Create an instance of the Solution class
    Solution solution;

    // Call the addTwoNumbers function to compute the result
    ListNode* result = solution.addTwoNumbers(l1, l2);

    // Print the result
    while (result != nullptr) {
        cout << result->val << " ";
        result = result->next;
    }

    // Clean up memory for the linked lists
    //deleteLinkedList(l1);
    //deleteLinkedList(l2);
   // deleteLinkedList(result); // Clean up the result linked list

    return 0;
}


/* 
To test:

1.) Navigate to the directory where you saved your .cpp file: 
You can use the cd (change directory) command to navigate to 
the directory where your file is located.

    bash cd path/to/your/cpp/file

2.) Compile the code: Use the g++ (GNU C++ compiler) command to compile your code. 
Replace twosum.cpp with the actual name of your source code file if it's different.

    g++ -std=c++11 -o add_two_numbers add_two_numbers.cpp

This command tells the compiler to create an 
executable file named twosum from your twosum.cpp source file.

3.) Run the executable: After successful compilation, 
you can run your program by executing the generated executable.

    On Windows: Copy code add_two_numbers.cpp.exe
    On Linux: bashCopy code./add_two_numbers.cpp
    On Mac: ./add_two_numbers

*/