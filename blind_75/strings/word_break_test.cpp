#include <iostream>
#include <vector>
#include "solution.h"  // Include the header file for your solution

int main() {
    Solution solution;

    std::vector<std::string> dictionary = {"mobile", "samsung", "sam", "sung",
                                           "man", "mango", "icecream", "and",
                                           "go", "i", "like", "ice", "cream"};

    // Test cases
    std::cout << (solution.wordBreak("ilikesamsung", dictionary) ? "Yes" : "No") << std::endl;
    std::cout << (solution.wordBreak("iiiiiiii", dictionary) ? "Yes" : "No") << std::endl;
    std::cout << (solution.wordBreak("", dictionary) ? "Yes" : "No") << std::endl;
    std::cout << (solution.wordBreak("ilikelikeimangoiii", dictionary) ? "Yes" : "No") << std::endl;
    std::cout << (solution.wordBreak("samsungandmango", dictionary) ? "Yes" : "No") << std::endl;
    std::cout << (solution.wordBreak("samsungandmangok", dictionary) ? "Yes" : "No") << std::endl;

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

    g++ -std=c++11 -o word_break word_break.cpp word_break_test.cpp

This command tells the compiler to create an 
executable file named twosum from your wordbreak.cpp source file.

3.) Run the executable: After successful compilation, 
you can run your program by executing the generated executable.

    On Windows: Copy word_break.exe
    On Linux: bashCopy code./word_break
    On Mac: ./word_break

*/