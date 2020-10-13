#include <stdio.h>

class Node {
private:
	double data;
public:
	Node* next;
	Node* previous;
	Node(double data);
	double getData();
	~Node();
};

class DoublyLinkedList {
private:
	Node* head;
	Node* tail;
	int listSize;
public:
	DoublyLinkedList();
	~DoublyLinkedList();
	int size();
	void addNodeAsTail(double value);
	void addNodeAsTail(Node* newNode);
	void addNodeAsHead(double value);
	void addNodeAsHead(Node* newNode);
	void push(Node* newNode);
	void printList();
	void printListBackwards();
	Node* pop();
	Node* peek();
	double getValue(int index);
	Node* getNode(int index);
	double getHeadValue();
	Node* getHead();
	double getTailValue();
	Node* getTail();
};