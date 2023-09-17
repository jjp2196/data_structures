#include <iostream>
# include <stdio.h>
# include <vector>
using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        
        // Because the first value (base case) will always be unique, 
        // start with k = 1 and initialize loop with i = 1;
        int k = 1;

        // every time that i is not the i before it, 
        // set val[k] to val[i], add to k to increment for next loop
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] != nums[i - 1]) {
                nums[k] = nums[i]; 
                k++;
            }
        }
        return k; 
    }
};

/*

Problem Statement: 

Given an integer array nums sorted in non-decreasing order, 
remove the duplicates in-place such that each unique element 
appears only once. The relative order of the elements should 
be kept the same. Then return the number of unique elements in nums.

Consider the number of unique elements of nums to be k, 
to get accepted, you need to do the following things:

1.) Change the array nums such that the first k elements 
of nums contain the unique elements in the order they were 
present in nums initially. The remaining elements of nums are not 
important as well as the size of nums.

2.) Return k.

*/

int main() 
{
    Solution s;
    vector<int> nums = {1, 2, 2, 3, 4, 4, 5, 6, 7, 7};
    int result = s.removeDuplicates(nums);

    cout << "The amount of unique values in nums is equal to " << result << ". \n"; 

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

    g++ -std=c++11 -o remove_sorted_duplicates remove_sorted_duplicates.cpp

This command tells the compiler to create an 
executable file named twosum from your twosum.cpp source file.

3.) Run the executable: After successful compilation, 
you can run your program by executing the generated executable.

    On Windows: Copy code remove_sorted_duplicates.cpp.exe
    On Linux: bashCopy code./remove_sorted_duplicates.cpp
    On Mac: ./remove_sorted_duplicates

*/