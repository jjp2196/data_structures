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
}