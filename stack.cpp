#include <iostream>
#include <stdexcept>

template <typename T>
class Stack {
private:
    T* arr;
    int capacity;
    int topIndex;

public:
    // Constructor
    Stack(int size = 10) {
        capacity = size;
        arr = new T[capacity];
        topIndex = -1;
    }

    // Destructor
    ~Stack() {
        delete[] arr;
    }

    // Push an element onto the stack
    void push(const T& value) {
        if (isFull()) {
            throw std::overflow_error("Stack Overflow: Cannot push onto a full stack.");
        }
        arr[++topIndex] = value;
    }

    // Remove and return the top element
    T pop() {
        if (isEmpty()) {
            throw std::underflow_error("Stack Underflow: Cannot pop from an empty stack.");
        }
        return arr[topIndex--];
    }

    // View the top element without removing it
    T peek() const {
        if (isEmpty()) {
            throw std::underflow_error("Stack is empty: No top element.");
        }
        return arr[topIndex];
    }

    // Check if stack is empty
    bool isEmpty() const {
        return topIndex == -1;
    }

    // Check if stack is full
    bool isFull() const {
        return topIndex == capacity - 1;
    }

    // Get current size of stack
    int size() const {
        return topIndex + 1;
    }
};

int main() {
    try {
        Stack<int> myStack(5);

        std::cout << "Pushing elements: 10, 20, 30\n";
        myStack.push(10);
        myStack.push(20);
        myStack.push(30);

        std::cout << "Top element is: " << myStack.peek() << "\n";
        std::cout << "Current stack size: " << myStack.size() << "\n\n";

        std::cout << "Popping elements:\n";
        while (!myStack.isEmpty()) {
            std::cout << myStack.pop() << " ";
        }
        std::cout << "\n";

    } catch (const std::exception& e) {
        std::cerr << "Exception: " << e.what() << "\n";
    }

    return 0;
}