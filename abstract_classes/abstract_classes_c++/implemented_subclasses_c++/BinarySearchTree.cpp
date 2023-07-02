#include <iostream>

namespace abstract_classes {
    template<typename T>
    class AbstractBinarySearchTree {
    protected:
        struct Node {
            T data;
            Node* left;
            Node* right;

            Node(T data) : data(data), left(nullptr), right(nullptr) {}
        };

        Node* root;
        virtual Node* insert(Node* node, T value) = 0;
        virtual Node* deleteNode(Node* node, T value) = 0;
        virtual bool contains(Node* node, T value) = 0;
        virtual void inOrderTraversal(Node* node) = 0;
        virtual void preOrderTraversal(Node* node) = 0;
        virtual void postOrderTraversal(Node* node) = 0;
        virtual Node* findMin(Node* node) = 0;
        virtual Node* findMax(Node* node) = 0;

    public:
        virtual ~AbstractBinarySearchTree() = default;

        void insert(T value) {
            root = insert(root, value);
        }

        void remove(T value) {
            root = deleteNode(root, value);
        }

        bool contains(T value) {
            return contains(root, value);
        }

        void inOrderTraversal() {
            inOrderTraversal(root);
        }

        void preOrderTraversal() {
            preOrderTraversal(root);
        }

        void postOrderTraversal() {
            postOrderTraversal(root);
        }

        Node* findMin() {
            return findMin(root);
        }

        Node* findMax() {
            return findMax(root);
        }
    };

    template<typename T>
    class BinarySearchTree : public AbstractBinarySearchTree<T> {
    private:
        using Node = typename AbstractBinarySearchTree<T>::Node;

        Node* insert(Node* node, T value) override {
            // Implementation code for insert function
        }

        Node* deleteNode(Node* node, T value) override {
            // Implementation code for deleteNode function
        }

        bool contains(Node* node, T value) override {
            // Implementation code for contains function
        }

        void inOrderTraversal(Node* node) override {
            // Implementation code for inOrderTraversal function
        }

        void preOrderTraversal(Node* node) override {
            // Implementation code for preOrderTraversal function
        }

        void postOrderTraversal(Node* node) override {
            // Implementation code for postOrderTraversal function
        }

        Node* findMin(Node* node) override {
            // Implementation code for findMin function
        }

        Node* findMax(Node* node) override {
            // Implementation code for findMax function
        }

    public:
        BinarySearchTree() : AbstractBinarySearchTree<T>(), root(nullptr) {}

        ~BinarySearchTree() {
            destroyTree(root);
        }

        void destroyTree(Node* node) {
            // Implementation code for destroyTree function
        }
    };
}