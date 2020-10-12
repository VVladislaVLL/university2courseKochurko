#include "DoublyLinkedList.h"
#include <stdio.h>
//using namespace std;
DoublyLinkedList::DoublyLinkedList()
{
	qurrent->next = nullptr;
	qurrent->prev = nullptr;
	qurrent->value = NULL;
	head = qurrent;
	tail = qurrent;
}

DoublyLinkedList::DoublyLinkedList(double value)
{
	qurrent->next = nullptr;
	qurrent->prev = nullptr;
	qurrent->value = value;
	head = qurrent;
	tail = qurrent;
}



DoublyLinkedList::~DoublyLinkedList()
{
	qurrent = head;
	while (qurrent->next != nullptr)
	{	
		qurrent = qurrent->next;
		delete qurrent->prev;
	}
	delete qurrent->next;
	delete qurrent;
	delete head;
	delete tail;
}

void DoublyLinkedList::print()
{
	if (head == NULL)
	{
		printf("List is empty\n");
		return;
	}

	Node* listCopy = head;
	printf("List consist of: ");
	do
	{
		printf("%f%s",listCopy->value, " ");
		listCopy = listCopy->next;
	} while (listCopy != NULL);

	printf("%c", ' ');
	return;
}

void DoublyLinkedList::insertAtHead(double value)
{
	if (head == NULL)
	{
		Node* newItem = new Node;
		newItem->value = value;
		newItem->next = NULL;
		newItem->prev = NULL;
		head = newItem;
		tail = newItem;

		printf("Elemet has been added\n");
		return;
	}

	Node* newItem = new Node;
	newItem->value = value;
	newItem->next = head;
	newItem->prev = NULL;
	head->prev = newItem;
	head = newItem;

	printf("Elemet has been added\n");
	return;
}

void DoublyLinkedList::insertAtTail(double value)
{
	if (head == NULL)
	{
		insertAtHead(value);

		return;
	}

	Node* newItem = new Node;
	newItem->value = value;
	newItem->next = NULL;
	Node* last = head;
	while (last->next != NULL)
	{
		last = last->next;
	}
	newItem->prev = last;
	last->next = newItem;
	tail = newItem;
	printf("Elemet has been added\n");
	return;
}

void DoublyLinkedList::insertInCertainPosition(double value, int search)
{
	if (head == NULL)
	{
		printf("List is empty\n");
		return;
	}

	Node* listCopy = head;
	while ((listCopy != NULL) && (listCopy->value != search))
	{
		listCopy = listCopy->next;
	}
	if (listCopy == NULL)
	{
		printf("There isn't such element in the list!\n");
		return;
	}
	else
	{
		Node* newItem = new Node;
		newItem->value = value;
		newItem->next = listCopy->next;
		newItem->prev = listCopy;
		listCopy->next->prev = newItem;
		listCopy->next = newItem;
		printf("Elemet has been added\n");
		return;
	}
}

void DoublyLinkedList::deleteAtHead()
{
	if (head == NULL)
	{
		printf("The list is empty(there is no elements to delete)\n");
		return;
	}

	Node* copyOfFirst = head;
	head = head->next;
	delete copyOfFirst;
	printf("Element has been deleted\n");
	return;
}

void DoublyLinkedList::deleteAtTail()
{
	if (head == NULL)
	{
		printf("The list is empty(there is no elements to delete)\n");
		return;
	}

	if (head->next == NULL)
	{
		deleteAtHead();
		return;
	}

	Node* lastCopy = tail;
	tail->prev->next = NULL;
	delete lastCopy;

	printf("Element has been deleted\n");
	return;
}

void DoublyLinkedList::deleteInCertainPosistion(int search)
{
	if (head == NULL)
	{
		printf("The list is empty(there is no elements to delete)\n");
		return;
	}

	Node* listCopy = head;
	while ((listCopy != NULL) && (listCopy->value != search))
	{
		listCopy = listCopy->next;
	}
	if (listCopy == NULL)
	{
		printf("There isn't such element in list!\n");
		return;
	}
	else
	{
		if (listCopy->prev == NULL)
		{
			deleteAtHead();
			return;
		}
		if (listCopy->next)
		{
			deleteAtTail();
			return;
		}

		Node* copyOfDelItem = listCopy;
		copyOfDelItem->prev->next = listCopy->next;
		copyOfDelItem->next->prev = listCopy->prev;
		delete listCopy;

		printf("Element has been deleted\n");
		return;
	}
}

void DoublyLinkedList::deleteList()
{
	if (head == NULL)
	{
		printf("The list is empty.\n");
		return;
	}

	Node* listCopy = tail;
	while (listCopy != NULL)
	{
		Node* copyOfCopy = listCopy;
		listCopy = listCopy->prev;
		delete copyOfCopy;
	}
	printf("The list has been cleaned\n");
	return;
}