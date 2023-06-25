public abstract class AbstractLinkedList {
    
    // Creates the first node (head) and size attribute of the class
    protected Node head;
    protected int size;

    // Inititializes the object with a head and size attribute (both empty)
    public AbstractLinkedList() {
        head = null;
        size = 0;
    }

    // Add a value to a node
    public abstract void add(int value);

    // Remove a value from a node
    public abstract void remove(int value);

    // Searches for a value in list, returns true or false
    public abstract boolean contains(int value);

    // Size of the list (number of nodes)
    public int size() {
        return size;
    }

    // Whether the list is empty or not (true or false)
    public boolean isEmpty() {
        return size == 0;
    }

    // Creates node class (to pull upwards when making a list)
    protected static class Node {
        protected int data;
        protected Node next;

        public Node(int data) {
            this.data = data;
            next = null;
        }
    }

}
