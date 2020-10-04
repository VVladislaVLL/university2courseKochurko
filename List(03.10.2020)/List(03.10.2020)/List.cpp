#include<stdio.h>
#include "List.h"

List::List() {
	head = 0;
	tail = 0;
}

void List::insert(int value) {
	/*if (!head) {
		Node* node = new Node();
		node->value = value;
		node->next = 0;
		head = node;
	}
	else {
		Node* node = new Node();
		node->value = value;
		node->next = head;
		head = node;
	}*/
	Node* node = new Node();
	node->value = value;
	node->next = head;
	head = node;
}


Node* List::find(int value) {
	Node* p = head;
	while (p != 0 && p->value != value) {
		p = p->next;
	}

	return p;
}

List::~List() {
	while (head) {
		Node* p = head;
		head = p->next;
		delete p;
	}
}

bool List::exist(int value) {
	return !find(value);
}

void List::remove(int value) {
	Node* p1 = head;
	Node* p2 = 0;
	while (p1 != 0 && p1->value != value) {
		p2 = p1;
		p1 = p1->next;
	}

	if (!p1) {
		return;
	}

	if (p2) {
		p2->next = p1->next;
		delete p1;
	}
	else {
		head = p1->next;
		delete p1;
	}
}

void List::print() {
	Node* p = head;
	while (p != 0 ) {
		printf("%d",p->value);
	}
}