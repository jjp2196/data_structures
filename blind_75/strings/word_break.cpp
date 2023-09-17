#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
    bool wordBreak(string word, vector<string>& wordDict) {
        unordered_set<string> dict(wordDict.begin(), wordDict.end());
        int n = word.length();
        vector<bool> dp(n + 1, false);
        dp[0] = true; // Empty string can be segmented

        for (int i = 1; i <= n; i++) {
            for (int j = 0; j < i; j++) {
                if (dp[j] && dict.count(word.substr(j, i - j))) {
                    dp[i] = true;
                    break;
                }
            }
        }

        return dp[n];
    }
};

/*

Code Functionality Explanation: 

1.) dp[j] checks whether the substring from position 0 to j (inclusive) 
can be segmented into words from the dictionary. If dp[j] is true, 
it means that the substring up to position j can be segmented into 
valid words from the dictionary.

2.) word.substr(j, i - j) extracts a substring starting from position j 
and ending at position i in the input string word. This represents the 
remaining part of the string that needs to be checked for segmentation.

3.) dict.count(word.substr(j, i - j)) checks if the extracted substring 
(the remaining part of the string) exists in the dictionary. If it does, 
it means that the current substring from position j to i can also be 
segmented into a valid word.

4.) 

5.) 

*/

/* 
To test:

1.) Navigate to the directory where you saved your .cpp file: 
You can use the cd (change directory) command to navigate to 
the directory where your file is located.

    bash cd path/to/your/cpp/file

2.) Compile the code: Use the g++ (GNU C++ compiler) command to compile your code. 
Replace twosum.cpp with the actual name of your source code file if it's different.

    g++ -std=c++11 -c word_break.cpp -o word_break.o

    g++ -std=c++11 -o word_break_output word_break_test.cpp word_break.o

This command tells the compiler to create an 
executable file named twosum from your wordbreak.cpp source file.

3.) Run the executable: After successful compilation, 
you can run your program by executing the generated executable.

    On Windows: Copy word_break.exe
    On Linux: bashCopy code./word_break
    On Mac: ./word_break

*/