# include <iostream>
# include <stdio.h>
# include <vector>

using namespace std;

/*
Given an integer x, return true if x is a 
palindrome, and false otherwise.

Example 1:

Input: x = 121
Output: true
Explanation: 121 reads as 121 from left to right 
and from right to left.
*/

class Solution {
public:
    bool isPalindrome(int x) {
        long number = x;
        long reverse = 0; 
        
        while (x > 0) {
            int digit = x % 10; // returns last digit
            reverse = (reverse * 10) + digit;
            x = x / 10;
        }

        if (number == reverse) {
            return true;
        }
        else {
            return false;
        }
    }
};

int main() {
    int pal = 12321;
    Solution solution;
    bool isPalindrome = solution.isPalindrome(pal);
    cout << "The number " << pal << " is a palindrome? " << (isPalindrome ? "Yes" : "No") << endl;
    return 0;

}
