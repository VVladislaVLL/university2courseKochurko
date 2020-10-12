#include "DoublyLinkedList.h"

int main()
{
	DoublyLinkedList list;
	list.insertAtHead(1);
	list.insertAtTail(1);
	list.insertAtTail(1);
	list.insertAtTail(2);
	list.insertAtTail(3);
	list.insertAtTail(4);
	list.insertAtTail(5);
	list.insertAtTail(6);
	list.insertAtTail(7);
	list.insertAtHead(0);
	list.deleteList();
	//list.insertInCertainPosition(1000,10);
	//list.deleteAtHead();
	//list.deleteInCertainPosistion(4);
	//list.deleteAtTail();
	list.print();
	return 0;
}