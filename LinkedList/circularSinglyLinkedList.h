#ifndef _CIRCULARSINGLYLINKEDLIST_H
#define _CIRCULARSINGLYLINKEDLIST_H

#include <string>
using namespace std;

struct node
{
	string info;
	node * next;

	node();
	node(const string &kelime, node * link);
};

class circularSinglyLinkedList
{
	private:
		node * head;

	public:
		circularSinglyLinkedList();		// constructor
		~circularSinglyLinkedList();	// destructor

		bool addNode (string s);
		bool deleteNode (string s);
		bool searchList(string s);
		void printList();
		void deleteList();
};

#endif _CIRCULARSINGLYLINKEDLIST_H