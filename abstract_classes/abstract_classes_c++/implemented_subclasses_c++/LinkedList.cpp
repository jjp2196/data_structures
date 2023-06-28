#include <iostream>

namespace abstract_classes {
    class AbstractLinkedList {
    protected:
        struct Node {
            int data;
            Node* next;

            Node(int data) : data(data), next(nullptr) {}
        };

        Node* head;
        int size;

    public:
        AbstractLinkedList() : head(nullptr), size(0) {}

        virtual void add(int value) = 0;
        virtual void remove(int value) = 0;
        virtual bool contains(int value) = 0;

        int getSize() {
            return size;
        }

        bool isEmpty() {
            return size == 0;
        }
    };

    class LinkedList : public AbstractLinkedList {
    public:
        void add(int value) override {
            Node* newNode = new Node(value);
            if (head == nullptr) {
                head = newNode;
            } else {
                Node* current = head;
                while (current->next != nullptr) {
                    current = current->next;
                }
                current->next = newNode;
            }
            size++;
        }

        void remove(int value) override {
            Node* current = head;
            Node* previous = nullptr;
            while (current != nullptr) {
                if (current->data == value) {
                    if (previous == nullptr) {
                        // Removing the head node
                        head = current->next;
                    } else {
                        previous->next = current->next;
                    }
                    delete current;
                    size--;
                    return;
                }
                previous = current;
                current = current->next;
            }
        }

        bool contains(int value) override {
            Node* current = head;
            while (current != nullptr) {
                if (current->data == value) {
                    return true;
                }
                current = current->next;
            }
            return false;
        }
    };
}

int main() {
    abstract_classes::LinkedList linkedList;
    // Use the concrete linked list implementation
    linkedList.add(5);
    linkedList.add(10);
    linkedList.add(15);
    std::cout << "Size: " << linkedList.getSize() << std::endl;  // Output: Size: 3
    std::cout << "Contains 10: " << linkedList.contains(10) << std::endl;  // Output: Contains 10: 1 (true)
    std::cout << "Contains 20: " << linkedList.contains(20) << std::endl;  // Output: Contains 20: 0 (false)
    linkedList.remove(10);
    std::cout << "Size after removal: " << linkedList.getSize() << std::endl;  // Output: Size after removal: 2
    return 0;
}