#include <stdio.h>
#include "DoublyLinkedList.h"

Node::Node(double data)
{
	this->next = NULL;
	this->previous = NULL;
	this->data = data;
}

double Node::getData()
{
	return this->data;
}

Node::~Node()
{
}

DoublyLinkedList::DoublyLinkedList()
{
	this->head = NULL;
	this->tail = NULL;
	this->listSize = 0;
}

double DoublyLinkedList::getHeadValue()
{
	return this->head->getData();
}

Node* DoublyLinkedList::getHead()
{
	return this->head;
}

double DoublyLinkedList::getTailValue()
{
	return this->tail->getData();
}

Node* DoublyLinkedList::getTail()
{
	return this->tail;
}

int DoublyLinkedList::size()
{
	int size = 0;
	Node* temp = this->head;
	while (temp) 
	{
		size++;
		temp = temp->next;
	}
	this->listSize = size;
	return this->listSize;
}

void DoublyLinkedList::addNodeAsTail(double value)
{
	Node* newNode = new Node(value);
	newNode->next = NULL;
	newNode->previous = NULL;

	if (this->head == NULL) 
	{
		this->head = newNode;
		this->tail = this->head;
		this->listSize = this->listSize + 1;
	}
	else 
	{
		this->tail->next = newNode;
		newNode->previous = this->tail;
		this->tail = newNode;
		this->listSize = this->listSize + 1;
	}
}

void DoublyLinkedList::addNodeAsTail(Node* newNode)
{
	newNode->next = NULL;
	newNode->previous = NULL;

	if (this->head == NULL) 
	{
		this->head = newNode;
		this->tail = this->head;
		this->listSize = this->listSize + 1;
	}
	else 
	{
		this->tail->next = newNode;
		newNode->previous = this->tail;
		this->tail = newNode;
		this->listSize = this->listSize + 1;
	}
}

void DoublyLinkedList::addNodeAsHead(double value)
{
	Node* newNode = new Node(value);
	newNode->next = NULL;
	newNode->previous = NULL;

	if (this->head == NULL) 
	{
		this->head = newNode;
		this->tail = this->head;
		this->listSize = this->listSize + 1;
	}
	else 
	{
		this->head->previous = newNode;
		newNode->next = this->head;
		this->head = newNode;
		this->listSize = this->listSize + 1;
	}
}

void DoublyLinkedList::addNodeAsHead(Node* newNode)
{
	newNode->next = NULL;
	newNode->previous = NULL;

	if (this->head == NULL) 
	{
		this->head = newNode;
		this->tail = this->head;
		this->listSize = this->listSize + 1;
	}
	else 
	{
		this->head->previous = newNode;
		newNode->next = this->head;
		this->head = newNode;
		this->listSize = this->listSize + 1;
	}
}

void DoublyLinkedList::push(Node* new_node)
{
	this->addNodeAsHead(new_node);
}

Node* DoublyLinkedList::pop() {
	Node* temp = this->head;
	this->head = this->head->next;
	this->head->previous = NULL;
	this->listSize = this->listSize - 1;
	return temp;
}

Node* DoublyLinkedList::peek()
{
	return this->head;
}


double DoublyLinkedList::getValue(int index) {
	if (index == 0)
	{
		return this->head->getData();
	}
	else if (index == this->listSize - 1)
	{
		return this->tail->getData();
	}
	else if (index < 0 || index >= this->listSize)
	{
		return NULL;
	}
	if (index < this->listSize / 2)
	{
		Node* temp = this->head;
		int i = 0;
		while (temp)
		{
			if (i == index)
			{
				return temp->getData();
			}
			i++;
			temp = temp->next;
		}
	}
	else
	{
		Node* temp = this->tail;
		int i = this->listSize - 1;
		while (temp)
		{
			if (i == index)
			{
				return temp->getData();
			}
			i--;
			temp = temp->previous;
		}
	}
	return NULL;
}


Node* DoublyLinkedList::getNode(int index) {
	if (index == 0) 
	{
		return this->head;
	}
	else if (index == this->listSize - 1) 
	{
		return this->tail;
	}
	else if (index < 0 || index >= this->listSize) 
	{
		return NULL;
	}
	if (index < this->listSize / 2) 
	{
		Node* temp = this->head;
		int i = 0;
		while (temp)
		{
			if (i == index) 
			{
				return temp; 
			}
			i++;
			temp = temp->next;
		}
	}
	else 
	{
		Node* temp = this->tail;
		int i = this->listSize - 1;
		while (temp) 
		{
			if (i == index)
			{ 
				return temp; 
			}
			i--;
			temp = temp->previous;
		}
	}
	return NULL;
}

void DoublyLinkedList::printList()
{
	printf("Start of the list(head): ");
	Node* temp = this->head;
	while (temp) 
	{
		printf("%f%s", temp->getData(), " -> ");
		temp = temp->next;
	}
	printf("%s", "\b\b\b\b :end of the list(tail)\n");
}

void DoublyLinkedList::printListBackwards()
{
	printf("End of the list(tail): ");
	Node* temp = this->tail;
	while (temp) {
		printf("%f%s", temp->getData(), " -> ");
		temp = temp->previous;
	}
	printf("%s", "\b\b\b\b :Begining of the list(head)\n");
}

DoublyLinkedList::~DoublyLinkedList()
{
	while (this->head) 
	{
		Node* next = this->head->next;
		delete this->head;
		this->listSize = this->listSize - 1;
		this->head = next;
	}
}
