template <class T>
class Stack {
private:
    struct Node {
        T data;
        Node* next;
    };
    int size;
    Node* head;
public:
    Stack();
    ~Stack();
    void push(T elem);
    T pop();
    int getSize();
    bool isEmpty();
    void print();
};