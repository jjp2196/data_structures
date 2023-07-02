#include <iostream>

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

    class Stack : public AbstractStack {
    private:
        int* elements;
        int top;
        int capacity;

    public:
        Stack(int capacity) : capacity(capacity), top(-1) {
            elements = new int[capacity];
        }

        ~Stack() {
            delete[] elements;
        }

        void push(int value) override {
            if (top == capacity - 1) {
                std::cout << "Stack is full. Unable to push." << std::endl;
                return;
            }

            elements[++top] = value;
            size++;
        }

        int pop() override {
            if (isEmpty()) {
                std::cout << "Stack is empty. Unable to pop." << std::endl;
                return -1;
            }

            int value = elements[top--];
            size--;
            return value;
        }
    };
}