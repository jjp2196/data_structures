#include <iostream>

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

namespace concrete_classes {
    class Queue : public abstract_classes::AbstractQueue {
    private:
        int* elements;
        int front;
        int rear;
        int capacity;

    public:
        Queue(int capacity) : capacity(capacity), front(0), rear(-1) {
            elements = new int[capacity];
        }

        ~Queue() {
            delete[] elements;
        }

        void enqueue(int value) override {
            if (rear == capacity - 1) {
                std::cout << "Queue is full. Unable to enqueue." << std::endl;
                return;
            }

            elements[++rear] = value;
            size++;
        }

        int dequeue() override {
            if (isEmpty()) {
                std::cout << "Queue is empty. Unable to dequeue." << std::endl;
                return -1;
            }

            int value = elements[front++];
            size--;
            return value;
        }
    };
}