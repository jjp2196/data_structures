package abstract_classes.abstract_classes_java.implemented_subclasses_java;
import abstract_classes.abstract_classes_java.AbstractBinarySearchTree;

public class BinarySearchTree<T extends Comparable<T>> extends AbstractBinarySearchTree<T> {

    @Override
    protected Node<T> insert(Node<T> node, T value) {
        // Provide implementation for inserting a value into the binary search tree
        return null;
    }

    @Override
    protected Node<T> delete(Node<T> node, T value) {
        // Provide implementation for deleting a value from the binary search tree
        return null;
    }

    @Override
    protected boolean contains(Node<T> node, T value) {
        // Provide implementation for checking if the binary search tree contains a value
        return false;
    }

    @Override
    protected void inOrderTraversal(Node<T> node) {
        // Provide implementation for in-order traversal of the binary search tree
    }

    @Override
    protected void preOrderTraversal(Node<T> node) {
        // Provide implementation for pre-order traversal of the binary search tree
    }

    @Override
    protected void postOrderTraversal(Node<T> node) {
        // Provide implementation for post-order traversal of the binary search tree
    }

    @Override
    protected Node<T> findMin(Node<T> node) {
        // Provide implementation for finding the smallest node value in the binary search tree
        return null;
    }

    @Override
    protected Node<T> findMax(Node<T> node) {
        // Provide implementation for finding the largest node value in the binary search tree
        return null;
    }
}
