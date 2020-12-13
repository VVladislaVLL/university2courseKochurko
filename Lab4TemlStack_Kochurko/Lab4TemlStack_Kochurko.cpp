#include <iostream>
#include "Stack.h"

using namespace std;

int main() {
	Stack<int>* stack = new Stack<int>();
    cout << "Is empty: " << stack->isEmpty() << endl;
    cout << "Size: " << stack->getSize() << endl;
    cout << "Push (4)" << endl;
    stack->push(4);
    cout << "Push (3)" << endl;
    stack->push(3);
    cout << "Push (2)" << endl;
    stack->push(2);
    cout << "Push (1)" << endl;
    stack->push(1);
    cout << "Size: " << stack->getSize() << endl;
    stack->print();
    cout << "Pop :" << stack->pop() << endl;
    stack->print();
    cout << "Pop :" << stack->pop() << endl;
    stack->print();
    cout << "Pop :" << stack->pop() << endl;
    stack->print();
    cout << "Pop :" << stack->pop() << endl;
    stack->print();
    cout << "Pop from empty stack :" << endl;
    stack->pop();
    stack->print();
	return 0;
}