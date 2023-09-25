#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length();
        int maxLength = 0;
        unordered_set<char> charSet;
        int left = 0;
        
        for (int right = 0; right < n; right++) {
            if (charSet.count(s[right]) == 0) {
                charSet.insert(s[right]);
                maxLength = max(maxLength, right - left + 1);
            } else {
                while (charSet.count(s[right])) {
                    charSet.erase(s[left]);
                    left++;
                }
                charSet.insert(s[right]);
            }
        }
        
        return maxLength;
    }
};

/*
Approach 1 - Set
We use a set (charSet) to keep track of unique 
characters in the current substring.

We maintain two pointers, left and right, 
to represent the boundaries of the current substring.

The maxLength variable keeps track of the length 
of the longest substring encountered so far.

We iterate through the string using the right pointer.

If the current character is not in the set (charSet), 
it means we have a new unique character.

We insert the character into the set and 
update the maxLength if necessary.

If the character is already present in the set, 
it indicates a repeating character within 
the current substring.

In this case, we move the left pointer forward, 
removing characters from the set until the 
repeating character is no longer present.

We insert the current character into 
the set and continue the iteration.

Finally, we return the maxLength 
as the length of the longest substring 
without repeating characters.
*/