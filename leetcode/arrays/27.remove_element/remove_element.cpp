#include <iostream>
# include <stdio.h>
# include <vector>
using namespace std;

/*

Problem Statement: 

Given an integer array nums and an integer val, remove 
all occurrences of val in nums in-place. The order of the 
elements may be changed. Then return the number of elements 
in nums which are not equal to val. 

Consider the number of elements in nums which are not equal to 
val to be k. To get accepted, do the following:

1.) Change the array nums s.t. the first k elements of nums contain 
the elements which are not equal to val. The remaining elements 
and size are not important.

2.) Return k.

*/

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int k = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != val) {
                nums[i] = nums[k];
                k++; 
            }
        }
        return k; 
    }
};

int main() 
{
    Solution s;
    vector<int> nums = {1, 5, 6, 5, 3, 2};
    int val = 5;
    int result = s.removeElement(nums, val);

    cout << "The amount of values not equal to " << val << " is " << result << "."; 
    
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

    g++ -std=c++11 -o remove_element remove_element.cpp

This command tells the compiler to create an 
executable file named twosum from your twosum.cpp source file.

3.) Run the executable: After successful compilation, 
you can run your program by executing the generated executable.

    On Windows: Copy code remove_element.cpp.exe
    On Linux: bashCopy code./remove_element.cpp
    On Mac: ./remove_element

*/