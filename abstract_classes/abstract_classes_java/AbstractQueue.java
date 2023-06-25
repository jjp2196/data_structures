package abstract_classes.abstract_classes_java;

public abstract class AbstractQueue {
    protected int size;

    public AbstractQueue() {
        size = 0; 
    }

    public abstract void enqueue(int value); 

    public abstract int dequeue(); 

    public int size() {
        return size;
    }

    public boolean isEmpty() {
        return size == 0;
    }S
}
