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
    TreeNode* invertTree(TreeNode* root) {
        // Check if the root is NULL (base case for recursion)
        if (root == NULL) {
            return NULL;
        }
        
        // Recursively invert the left and right subtrees
        TreeNode* invertedLeft = invertTree(root->left);
        TreeNode* invertedRight = invertTree(root->right);

        // Check for NULL pointers before swapping, avoid segfault
        if (invertedLeft != NULL && invertedRight != NULL) {
            root->left = invertedRight;
            root->right = invertedLeft;
        }

        // Return the modified root
        return root;
    }
};

class BinaryTreeTester {
public:
    static void runTests() {
        testInvertTree();
    }

    static void testInvertTree() {
        Solution solution;
        
        // Create a sample binary tree
        TreeNode* root = new TreeNode(1);
        root->left = new TreeNode(2);
        root->right = new TreeNode(3);
        root->left->left = new TreeNode(4);
        root->left->right = new TreeNode(5);
        
        // Invert the tree
        TreeNode* invertedTree = solution.invertTree(root);
        
        // Verify the inverted tree structure
        assert(invertedTree->val == 1);
        assert(invertedTree->left->val == 3);
        assert(invertedTree->right->val == 2);
        assert(invertedTree->left->left->val == 5);
        assert(invertedTree->left->right->val == 4);
        
        std::cout << "InvertTree test passed!" << std::endl;
        
        // Clean up memory (optional)
        deleteTree(root);
        deleteTree(invertedTree);
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

g++ -std=c++11 -o invert_tree invert_tree.cpp

2.) Execute: 

gdb ./invert_tree

*/ 

