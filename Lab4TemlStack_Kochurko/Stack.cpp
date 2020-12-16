#include <iostream>
#include "Stack.h"

using namespace std;

template <class T>
Stack <T>::Stack()
{
    this->size = 0;
    this->head = NULL;
}

template <class T>
Stack <T>::~Stack()
{
}

template<class T>
void Stack< T >::push(T elem) {
    Node* newNode = new Node();
    newNode->data = elem;
    newNode->next = NULL;

    if (this->head == NULL) {
        this->head = newNode;
    }
    else {
        newNode->next = this->head;
        this->head = newNode;
    }

    this->size += 1;
}


template<class T>
T Stack< T >::pop() {
    try {
        if (this->isEmpty() == false) {
            Node* temp = this->head;
            this->head = this->head->next;
            this->size--;

            if (this->isEmpty() == true)
            {
                this->head = NULL;
            }
            return temp->data;
        }
        else {
            throw out_of_range("Stack is empty!");
        }
    }
    catch (const out_of_range) {
        cerr << "Stack is empty!" << endl;
    }
}

template<class T>
void Stack<T>::print()
{
    Node* new_node = this->head;
    while (new_node)
    {
        cout << new_node->data << "->";
        new_node = new_node->next;
    }
    cout << "NULL" << endl;
}

template<class T>
int Stack<T>::getSize()
{
    return this->size;
}


template<class T>
bool Stack<T>::isEmpty() {
    if (this->size > 0)
    {
        return false;
    }
    return true;
}