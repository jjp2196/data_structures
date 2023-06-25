package abstract_classes.abstract_classes_java;

public abstract class AbstractQueue {
    protected int size;

    // Abstract Queue initializing object
    public AbstractQueue() {
        size = 0; 
    }

    // Enqueue (adding to front of line)
    public abstract void enqueue(int value); 

    // Dequeue (removing from front of line)
    public abstract int dequeue(); 

    // Returns the value for size, int type
    public int size() {
        return size;
    }

    // Returns T/F if queue is empty, good for while loops
    public boolean isEmpty() {
        return size == 0;
    }
}
