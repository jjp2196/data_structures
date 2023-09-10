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