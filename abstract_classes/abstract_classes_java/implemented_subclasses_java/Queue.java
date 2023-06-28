package abstract_classes.abstract_classes_java.implemented_subclasses_java;
import abstract_classes.abstract_classes_java.AbstractQueue;
import java.util.NoSuchElementException;

public class Queue extends AbstractQueue {
    private Node head;
    private Node tail;

    private class Node {
        int value;
        Node next;

        public Node(int value) {
            this.value = value;
            this.next = null;
        }
    }

    @Override
    public void enqueue(int value) {
        Node newNode = new Node(value);
        if (isEmpty()) {
            head = newNode;
            tail = newNode;
        } else {
            tail.next = newNode;
            tail = newNode;
        }
        size++;
    }

    @Override
    public int dequeue() {
        if (isEmpty()) {
            throw new NoSuchElementException("Queue is empty");
        }
        int value = head.value;
        head = head.next;
        size--;
        if (isEmpty()) {
            tail = null;
        }
        return value;
    }
}
