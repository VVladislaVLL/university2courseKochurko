#pragma once
struct Node {
	double value;
	Node* prev;
	Node* next;
};

class DoublyLinkedList {
private:
	Node* qurrent;
	Node* head;
	Node* tail;
public:
	DoublyLinkedList();
	DoublyLinkedList(double value);
	~DoublyLinkedList();
	void print();
	void insertAtHead(double value);
	void insertAtTail(double value);
	void insertInCertainPosition(double value, int search);
	void deleteAtHead();
	void deleteAtTail();
	void deleteInCertainPosistion(int search);
	void deleteList();
	/*void createList(double value);
	void addBegin(double value);
	void addAfter(double value, int position);
	void deleteElement(double value);
	void searchElement(double value);
	void printList();
	void count();
	void reverse();*/
};
