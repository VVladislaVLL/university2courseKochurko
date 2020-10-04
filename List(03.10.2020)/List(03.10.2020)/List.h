#pragma once
struct Node {
	Node* next;
	int value;
};

class List{
private: 
	Node* tail;
	Node* head;
	Node* find(int value);
public:
	List();
	void insert(int value);
	void remove(int value);
	bool exist(int value);
	void print();
};