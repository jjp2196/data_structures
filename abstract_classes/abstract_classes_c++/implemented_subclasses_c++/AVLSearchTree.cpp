namespace abstract_classes {
    template<typename T>
    class AVLSearchTree : public AbstractAVLSearchTree<T> {
    public:
        void remove(T data) override {
            // Implementation of the remove method specific to the concrete subclass
            // ...
        }

        bool search(T data) override {
            // Implementation of the search method specific to the concrete subclass
            // ...
        }

        void displayInOrder() override {
            // Implementation of the displayInOrder method specific to the concrete subclass
            // ...
        }
    };
}