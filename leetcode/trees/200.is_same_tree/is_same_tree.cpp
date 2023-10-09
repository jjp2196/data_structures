#include <iostream>
#include <cassert>

// Tree Definition of Data Structure

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {

        // base case, both trees are null, identical
        if (p == NULL && q == NULL) {
            return true;
        }

        // if either root is null, or the values aren't equal, return false
        if (p == NULL || q == NULL || p->val != q->val) {
            return false;
        }

        // if these values are true, return the result of this function applied to leaf nodes
        if (p->val == q->val) {
            return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
        }

        // if we recursively bite through each whole tree and cannot find 
        // all equal values, it must be false
        return false;
    }
};

class BinaryTreeTester {
public:
    static void runTests() {
        testIsSameTree();
    }

    static void testIsSameTree() {
        Solution solution;
        
        // Create two sample binary trees
        TreeNode* p = new TreeNode(1);
        p->left = new TreeNode(2);
        p->right = new TreeNode(3);

        TreeNode* q = new TreeNode(1);
        q->left = new TreeNode(2);
        q->right = new TreeNode(3);
        
        // Test Solution
        bool sol = solution.isSameTree(p, q);
        
        // Verify the same structure
        
        std::cout << "It is the same tree is " << sol << "." << std::endl;
        
        // Clean up memory (optional)
        deleteTree(p);
        deleteTree(q);
    }

    static void deleteTree(TreeNode* root) {
        if (root == NULL) {
            return;
        }
        deleteTree(root->left);
        deleteTree(root->right);
        delete root;
    }
};

int main() {
    BinaryTreeTester::runTests();
    return 0;
}

/*

To run this code with tester:

1.) Compile with gcc:

g++ -std=c++11 -o is_same_tree is_same_tree.cpp

2.) Execute: 

gdb ./is_same_tree

*/ 

