#ifndef _CIRCULARDOUBLYLINKEDLIST_H
#define _CIRCULARDOUBLYLINKEDLIST_H

#include <string>
using namespace std;

struct node
{
	string info;
	node * next;
	node * prev;

	node();
	node(const string & kelime, node * ileri, node * geri);
};

class CircularDoublyLinkedList
{
	private:
		node * head;

	public:
		CircularDoublyLinkedList();
		~CircularDoublyLinkedList();

		bool addNode (string s);
		bool deleteNode (string s);
		bool searchList(string s);
		void printList();
		void deleteList();
};

#endif _CIRCULARDOUBLYLINKEDLIST_H