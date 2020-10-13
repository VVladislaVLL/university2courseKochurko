#include "DoublyLinkedList.h"
#include <stdio.h>

int main()
{
	DoublyLinkedList firstList;
	DoublyLinkedList secondList;
	// Number of elemnts in first List
	int N = 10;

	for (int i = 0; i < N; i++)
	{
		firstList.addNodeAsTail(i);
	}
	firstList.printList();
	printf("%s%d\n", "Size of First List: ",firstList.size());

	int start = 0;
	int end = N - 1;
	for (int i = 0; i < N * 2; i++) {
		if (i % 2 == 0) 
		{
			secondList.addNodeAsTail(firstList.getValue(start++));
		}
		else
		{
			secondList.addNodeAsTail(firstList.getValue(end--));
		}
	}
	secondList.printList();
	printf("%s%d\n", "Size of Second List: ", secondList.size());

	
	return 0;
}