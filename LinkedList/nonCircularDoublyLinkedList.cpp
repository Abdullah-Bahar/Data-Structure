#include <iostream>
#include <string>
#include "nonCircularDoublyLinkedList.h"

using namespace std;


/****************
Definition Functions of Struct Node 
*****************/

node::node()
{}

node::node(const string & kelime, node * ileri, node * geri)
	: info(kelime), next(ileri), prev(geri)
{}



/****************
Definition Functions of nonCircularSinglyLinkedList NoClassde 
*****************/

nonCircularDoublyLinkedList::nonCircularDoublyLinkedList()
{
	head = NULL;
}

nonCircularDoublyLinkedList::~nonCircularDoublyLinkedList()
{
	void deleteList();
}


bool nonCircularDoublyLinkedList::addNode(string s)
{
	node * newNode = new node(s, NULL, NULL);

	// Is List Empty
	if (head == NULL)
	{
		head = newNode;
		return true;
	}

	// Eklenecek eleman listenin basinda ise
	if (newNode -> info < head -> info)
	{
		newNode -> next = head;
		newNode -> prev = NULL;
		head -> prev = newNode;
		head = newNode;

		return true;
	}

	// eklenecek eleman listenin ortasinda veya sonunda ise
	if (!searchList(s))		// info degeri liste icerisinde var mi kontrolu
	{
		node * ptr = head;
		while (ptr != NULL)
		{
			if (ptr -> next == NULL || newNode -> info < ptr -> next -> info)
			{
				if (ptr -> next != NULL) // Eklenecek eleman listenin ortasinda ise 
					ptr -> next -> prev = newNode;

				newNode -> next = ptr -> next;	
				ptr -> next = newNode;
				newNode -> prev = ptr;

				return true;
			}
			ptr = ptr -> next;
		}

	}

	delete newNode;
	return false;
}

bool nonCircularDoublyLinkedList::deleteNode(string s)
{
	// Liste bos ise
	if (head == NULL)
		return false;

	node * ptr = head;
	node * delNode = NULL;

	while (ptr != NULL)
	{
		if (ptr -> info == s)
		{
			delNode = ptr;

			if (ptr -> prev == NULL) // Listede basindaki eleman silinecekse
			{
				if (ptr -> next == NULL) // Listede bir eleman varsa
				{
					head = NULL;
				}
				else	// Listede birden fazla eleman varsa
				{
					head = ptr -> next;
					head -> prev = NULL;
				}
			}
			else
			{
				if (ptr -> next == NULL)  // Listenin sonundaki eleman silinecek ise 
				{
					ptr -> prev -> next = NULL;
				}
				else	// Listenin ortasindaki eleman silinecek ise 
				{
					ptr -> prev -> next = ptr -> next;
					ptr -> next -> prev = ptr -> prev;
				}
			}

			delete delNode;
			return true;
		}
		ptr = ptr -> next;
	}


	return false;
}

bool nonCircularDoublyLinkedList::searchList(string s)
{
	node * ptr = head;

	while (ptr != NULL)
	{
		if (ptr -> info == s)
			return true;

		ptr = ptr -> next;
	}

	return false;
}

void nonCircularDoublyLinkedList::printList()
{
	if (head == NULL)
	{
		cout << "List is empty" << endl;
	}
	else
	{
		int k = 0;
		node * ptr = head;

		while (ptr != NULL)
		{
			cout << k <<". eleman : " << ptr -> info << endl;
			ptr = ptr -> next;
			k++;
		}
		cout << endl;
	}
}

void nonCircularDoublyLinkedList::deleteList()
{
	if (head == NULL)
	{
		cout << "Liste is empty" << endl;
	}
	else
	{
		node * ptr = head;
		while (ptr != NULL)
		{
			head = head -> next;
			delete ptr;
			ptr = head;
		}
		cout << "Liste Silindi" << endl;
		head = NULL;
	}
}
