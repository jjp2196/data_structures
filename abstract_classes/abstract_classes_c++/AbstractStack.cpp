namespace abstract_classes {
    class AbstractStack {
    protected:
        int size;

    public:
        AbstractStack() : size(0) {}

        virtual void push(int value) = 0;
        virtual int pop() = 0;

        int getSize() {
            return size;
        }

        bool isEmpty() {
            return size == 0;
        }
    };
}