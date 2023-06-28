namespace abstract_classes {
    template<typename T>
    class AbstractAVLSearchTree {
    protected:
        struct Node {
            T data;
            Node* left;
            Node* right;
            int height;

            Node(T data) : data(data), left(nullptr), right(nullptr), height(1) {}
        };

        Node* root;

        int height(Node* node) {
            if (node == nullptr) {
                return 0;
            }
            return node->height;
        }

        int balanceFactor(Node* node) {
            if (node == nullptr) {
                return 0;
            }
            return height(node->left) - height(node->right);
        }

        Node* rotateLeft(Node* node) {
            Node* newRoot = node->right;
            node->right = newRoot->left;
            newRoot->left = node;
            node->height = std::max(height(node->left), height(node->right)) + 1;
            newRoot->height = std::max(height(newRoot->left), height(newRoot->right)) + 1;
            return newRoot;
        }

        Node* rotateRight(Node* node) {
            Node* newRoot = node->left;
            node->left = newRoot->right;
            newRoot->right = node;
            node->height = std::max(height(node->left), height(node->right)) + 1;
            newRoot->height = std::max(height(newRoot->left), height(newRoot->right)) + 1;
            return newRoot;
        }

        Node* insert(Node* node, T data) {
            if (node == nullptr) {
                return new Node(data);
            }

            if (data < node->data) {
                node->left = insert(node->left, data);
            } else if (data > node->data) {
                node->right = insert(node->right, data);
            } else {
                // Duplicate keys not allowed in AVL tree
                return node;
            }

            node->height = 1 + std::max(height(node->left), height(node->right));

            int balance = balanceFactor(node);

            if (balance > 1 && data < node->left->data) {
                return rotateRight(node);
            }

            if (balance < -1 && data > node->right->data) {
                return rotateLeft(node);
            }

            if (balance > 1 && data > node->left->data) {
                node->left = rotateLeft(node->left);
                return rotateRight(node);
            }

            if (balance < -1 && data < node->right->data) {
                node->right = rotateRight(node->right);
                return rotateLeft(node);
            }

            return node;
        }

        void inorderTraversal(Node* node) {
            if (node != nullptr) {
                inorderTraversal(node->left);
                std::cout << node->data << " ";
                inorderTraversal(node->right);
            }
        }

    public:
        AbstractAVLSearchTree() : root(nullptr) {}

        void insert(T data) {
            root = insert(root, data);
        }

        virtual void remove(T data) = 0;
        virtual bool search(T data) = 0;
        virtual void displayInOrder() = 0;
    };
}
