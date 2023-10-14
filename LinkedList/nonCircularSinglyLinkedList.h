#ifndef _NONCIRCULARSINGLYLINKEDLIST_H
#define _NONCIRCULARSINGLYLINKEDLIST_H

/*
	Author : Abdullah Bahar
*/

#include <string>
using namespace std;

struct node
{
	string info;
	node * next;

	node();
	node(const string &kelime, node * baglanti);
};


class  nonCircularSinglyLinkedList
{
	private:
		node * head;

	public:
		nonCircularSinglyLinkedList();		// constructor
		~nonCircularSinglyLinkedList();		// destructor

		bool addNode (string s);
		bool deleteNode (string s);
		bool searchList(string s);
		void printList();
		void deleteList();
};






#endif _NONCIRCULARSINGLYLINKEDLIST_H