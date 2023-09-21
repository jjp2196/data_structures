#include "iostream"
#include "stack"

using namespace std;

/*

Given a string s containing just the characters 
'(', ')', '{', '}', '[' and ']', determine if the 
input string is valid.

An input string is valid if:

Open brackets must be closed by the same type of brackets.
Open brackets must be closed in the correct order.
Every close bracket has a corresponding open bracket of the same type.

*/

#include <iostream>
#include <stack>

using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for (char c : s) {
            if (c == '(' || c == '[' || c == '{') {
                st.push(c);
            } else if (c == ')' || c == ']' || c == '}') {
                if (st.empty()) {
                    return false; // There is no matching opening bracket.
                } else {
                    char top = st.top();
                    st.pop();
                    if ((c == ')' && top != '(') ||
                        (c == ']' && top != '[') ||
                        (c == '}' && top != '{')) {
                        return false; // Mismatched opening and closing brackets.
                    }
                }
            }
        }
        return st.empty(); // Check if all opening brackets are closed.
    }
};

int main() {
    Solution solution;
    string s = "{[()]}";
    bool result = solution.isValid(s);
    if (result) {
        cout << "Valid" << endl;
    } else {
        cout << "Not Valid" << endl;
    }
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

    g++ -std=c++11 -o valid_parentheses valid_parentheses.cpp

This command tells the compiler to create an 
executable file named twosum from your twosum.cpp source file.

3.) Run the executable: After successful compilation, 
you can run your program by executing the generated executable.

    On Windows: Copy code valid_parentheses.cpp.exe
    On Linux: bashCopy code./valid_parentheses.cpp
    On Mac: ./valid_parentheses

*/