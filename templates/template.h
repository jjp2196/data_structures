#ifndef __MY_TEMPLATE_H__
#define __MY_TEMPLATE_H__

#include <iostream>
#include <vector>

template <typename T>
class MyTemplate {
public:
    // Default constructor
    MyTemplate();

    // Parameterized constructor
    MyTemplate(T _x);

    // Copy constructor
    MyTemplate(const MyTemplate& other);

    // Copy assignment
    MyTemplate& operator=(const MyTemplate& other);

    // Destructor
    ~MyTemplate();

    // Move constructor
    MyTemplate(MyTemplate&& other);

    // Move assignment
    MyTemplate& operator=(MyTemplate&& other);

    // Conversion operator
    operator bool() const { return (x != T{}); }

    // Overloaded stream output operator
    friend std::ostream& operator<<(std::ostream& os, const MyTemplate& obj) {
        os << obj.x;
        return os;
    }

    // Overloaded stream input operator
    friend std::istream& operator>>(std::istream& is, MyTemplate& obj) {
        is >> obj.x;
        return is;
    }

    // Operator[] for indexing
    T& operator[](int i) { return list[i]; }

    // Operator[] const for indexing
    const T& operator[](int i) const { return list[i]; }

    // Size method
    size_t size() const { return list.size(); }

    // Sample method (you can replace this with your custom method)
    void method(T v);

private:
    T x;
    std::vector<T> list;
};

// Operator+ for adding two MyTemplate objects
template <typename T>
MyTemplate<T> operator+(const MyTemplate<T>& lhs, const MyTemplate<T>& rhs) {
    MyTemplate<T> result(lhs);
    result += rhs;
    return result;
}

// Operator- for subtracting two MyTemplate objects
template <typename T>
MyTemplate<T> operator-(const MyTemplate<T>& lhs, const MyTemplate<T>& rhs) {
    MyTemplate<T> result(lhs);
    result -= rhs;
    return result;
}

// Functor (you can customize this functor)
template <typename T>
struct MyFunctor {
    void operator()(const T& obj) {
        // Functor body
    }
};

template <typename T>
MyTemplate<T>::MyTemplate() : x(T{}) {}

template <typename T>
MyTemplate<T>::MyTemplate(T _x) : x(_x) {}

template <typename T>
MyTemplate<T>::MyTemplate(const MyTemplate& other) : x(other.x), list(other.list) {}

template <typename T>
MyTemplate<T>& MyTemplate<T>::operator=(const MyTemplate& other) {
    if (this != &other) {
        x = other.x;
        list = other.list;
    }
    return *this;
}

template <typename T>
MyTemplate<T>::~MyTemplate() {}

template <typename T>
MyTemplate<T>::MyTemplate(MyTemplate&& other) noexcept : x(std::move(other.x)), list(std::move(other.list)) {}

template <typename T>
MyTemplate<T>& MyTemplate<T>::operator=(MyTemplate&& other) noexcept {
    if (this != &other) {
        x = std::move(other.x);
        list = std::move(other.list);
    }
    return *this;
}

template <typename T>
void MyTemplate<T>::method(T v) {
    // Implementation of the method
}

#endif
