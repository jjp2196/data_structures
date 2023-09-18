#include <iostream>
# include <stdio.h>
# include <vector>
using namespace std;

/*

Problem Statement: 

Given a sorted array of distinct integers and a target value, 
return the index if the target is found. If not, return the index 
where it would be if it were inserted in order.

You must write an algorithm with O(log n) runtime complexity.

*/

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int count = 0; // Initialize counter alongside i
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] < target) {
                count = i + 1; 
                // if the value is less than target at i, count = i + 1;
                // this tracks all the solutions with value of i;
            }
            if (nums[i] == target) {
                count = i;
                break;
                // if value is equal target, log k as target
            }
        }
        return count;
        // if there is no target, then return the highest 
        // count that we get to
    }
};



int main() 
{
    Solution s;
    vector<int> nums = {1, 2, 3, 5};
    int target = 4;
    int result = s.searchInsert(nums, target);

    cout << "The position of target or insert point is " << result << "."; 
    
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

    g++ -std=c++11 -o search_insert search_insert.cpp

This command tells the compiler to create an 
executable file named twosum from your twosum.cpp source file.

3.) Run the executable: After successful compilation, 
you can run your program by executing the generated executable.

    On Windows: Copy code search_insert.cpp.exe
    On Linux: bashCopy code./search_insert.cpp
    On Mac: ./search_insert

*/