namespace abstract_classes {
    class AbstractQueue {
    protected:
        int size;

    public:
        AbstractQueue() : size(0) {}

        virtual void enqueue(int value) = 0;
        virtual int dequeue() = 0;

        int getSize() {
            return size;
        }

        bool isEmpty() {
            return size == 0;
        }
    };
}