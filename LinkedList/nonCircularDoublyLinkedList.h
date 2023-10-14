#ifndef _NONCIRCULARDOUBLYLINKEDLIST_H
#define _NONCIRCULARDOUBLYLINKEDLIST_H

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

class nonCircularDoublyLinkedList
{
	private:
		node * head;

	public:
		nonCircularDoublyLinkedList();
		~nonCircularDoublyLinkedList();

		bool addNode (string s);
		bool deleteNode (string s);
		bool searchList(string s);
		void printList();
		void deleteList();
};




#endif _NONCIRCULARDOUBLYLINKEDLIST_H