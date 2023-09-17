#include <iostream>
# include <stdio.h>
# include <vector>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        for (int i = 0; i < nums.size(); i++) {
            for (int j = i + 1; j < nums.size(); j++) {
                if (nums[i] + nums[j] == target) {
                    return {i, j};
                }
            }
        }
    return {}; // Return an empty vector if no pair is found
    }
};

int main() 
{
    Solution s;
    vector<int> v = {1, 6, 3, 2, 5};
    int target = 11;
    vector<int> result = s.twoSum(v, target);

    if (result.size() == 2) {
        cout << "Indices of the elements that sum up to " << target << " are: " << result[0] << " and " << result[1] << endl;
    } else {
        cout << "No such pair of elements found that sum up to " << target << endl;
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

    g++ -std=c++11 -o two_sum two_sum.cpp

This command tells the compiler to create an 
executable file named twosum from your twosum.cpp source file.

3.) Run the executable: After successful compilation, 
you can run your program by executing the generated executable.

    On Windows: Copy code two_sum.exe
    On Linux: bashCopy code./two_sum
    On Mac: ./two_sum

*/