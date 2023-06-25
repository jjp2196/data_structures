package abstract_classes.abstract_classes_java;

public abstract class AbstractAVLSearchTree<T extends Comparable<T>> {
    
    // Creates a Node class with height 1 (for root)
    protected class Node {
        T data;
        Node left;
        Node right;
        int height;

        Node(T data) {
            this.data = data;
            height = 1;
        }
    }

    // Creates the root node with each tree
    protected Node root;

    // Creates the height of each tree (like .size() of list)
    protected int height(Node node) {
        if (node == null) {
            return 0;
        }
        return node.height;
    }

    // Compares left node to right node by height, letting AVL balance
    protected int balanceFactor(Node node) {
        if (node == null) {
            return 0;
        }
        return height(node.left) - height(node.right);
    }

    // Creates a newRoot at node.right, switching the max value over
    protected Node rotateLeft(Node node) {
        Node newRoot = node.right;
        node.right = newRoot.left;
        newRoot.left = node;
        node.height = Math.max(height(node.left), height(node.right)) + 1;
        newRoot.height = Math.max(height(newRoot.left), height(newRoot.right)) + 1;
        return newRoot;
    }

    // Creates a new root at node.left, switching the min value over left
    protected Node rotateRight(Node node) {
        Node newRoot = node.left;
        node.left = newRoot.right;
        newRoot.right = node;
        node.height = Math.max(height(node.left), height(node.right)) + 1;
        newRoot.height = Math.max(height(newRoot.left), height(newRoot.right)) + 1;
        return newRoot;
    }

    // Inserts a new node, updates height and balance factor automatically
    // AVL Trees are Sets (immutable), so no duplicate keys are allowed
    protected Node insert(Node node, T data) {
        if (node == null) {
            return new Node(data);
        }

        if (data.compareTo(node.data) < 0) {
            node.left = insert(node.left, data);
        } else if (data.compareTo(node.data) > 0) {
            node.right = insert(node.right, data);
        } else {
            // Duplicate keys not allowed in AVL tree
            return node;
        }

        node.height = 1 + Math.max(height(node.left), height(node.right));

        int balance = balanceFactor(node);

        if (balance > 1 && data.compareTo(node.left.data) < 0) {
            return rotateRight(node);
        }

        if (balance < -1 && data.compareTo(node.right.data) > 0) {
            return rotateLeft(node);
        }

        if (balance > 1 && data.compareTo(node.left.data) > 0) {
            node.left = rotateLeft(node.left);
            return rotateRight(node);
        }

        if (balance < -1 && data.compareTo(node.right.data) < 0) {
            node.right = rotateRight(node.right);
            return rotateLeft(node);
        }

        return node;
    }

    // Allows us to go through and traverse in order (smallest to largest values)
    protected void inorderTraversal(Node node) {
        if (node != null) {
            inorderTraversal(node.left);
            System.out.print(node.data + " ");
            inorderTraversal(node.right);
        }
    }

    protected abstract void insert(T data);

    protected abstract void remove(T data);

    protected abstract boolean search(T data);

    protected abstract void displayInOrder();
}