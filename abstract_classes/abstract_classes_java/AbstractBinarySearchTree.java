package abstract_classes.abstract_classes_java;

public abstract class AbstractBinarySearchTree<T extends Comparable<T>> {
    
    // Initializes the abstract root node, inserting and deleting nodes
    protected Node<T> root;
    protected abstract Node<T> insert(Node<T> node, T value);
    protected abstract Node<T> delete(Node<T> node, T value);
    protected abstract boolean contains(Node<T> node, T value);

    // Allows us to traverse nodes from lowest to highest in order
    // (bottom left to bottom right)
    protected abstract void inOrderTraversal(Node<T> node);

    // Allows us to traverse nodes from root flowing down to left leaves then to right
    protected abstract void preOrderTraversal(Node<T> node);

    // Allows us to traverse nodes from left tree to right tree, saving each until end
    protected abstract void postOrderTraversal(Node<T> node);

    // Finds the smallest node value in the tree, traversing whole BST
    protected abstract Node<T> findMin(Node<T> node);

    // Finds the largest node value in the tree, traverses whole BST
    protected abstract Node<T> findMax(Node<T> node);

    // For each node, give it internal data (doesn't matter what data type, abstract as T)
    // Give each node the ability to talk with nodes to the left and to the right of it
    // (Inheritance, descendents as a concept)
    protected static class Node<T> {
        T data;
        Node<T> left;
        Node<T> right;

        public Node(T data) {
            this.data = data;
            this.left = null;
            this.right = null;
        }
    }
}