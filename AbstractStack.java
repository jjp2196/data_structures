public abstract class AbstractStack {
    protected int size;

    // Constructor for AbstractStack
    public AbstractStack() {
        size = 0;
    }

    // Abstract method for pushing an element to the stack
    public abstract void push(int value);

    // Abstract method for popping an element from the stack
    public abstract int pop();

    // Returns the current size of the stack
    public int size() {
        return size;
    }

    // Checks if the stack is empty
    public boolean isEmpty() {
        return size == 0;
    }
}