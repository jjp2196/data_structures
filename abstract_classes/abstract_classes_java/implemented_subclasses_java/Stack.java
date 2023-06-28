package abstract_classes.abstract_classes_java.implemented_subclasses_java;

import abstract_classes.abstract_classes_java.AbstractStack;
import java.util.NoSuchElementException;


public class Stack extends AbstractStack {
    private Node top;

    private class Node {
        int value;
        Node next;

        public Node(int value) {
            this.value = value;
            this.next = null;
        }
    }

    @Override
    public void push(int value) {
        Node newNode = new Node(value);
        newNode.next = top;
        top = newNode;
        size++;
    }

    @Override
    public int pop() {
        if (isEmpty()) {
            throw new NoSuchElementException("Stack is empty");
        }
        int value = top.value;
        top = top.next;
        size--;
        return value;
    }
}
