#include <iostream>
#include <string>
#include "circularSinglyLinkedList.h"

using namespace std;

/****************
Definition Functions of Struct Node 
*****************/

node::node()
{}

node::node(const string &kelime, node * link)
{
	info = kelime;
	next = link;
}


/****************
Definition Functions of nonCircularSinglyLinkedList NoClassde 
*****************/

circularSinglyLinkedList::circularSinglyLinkedList()
{
	head = NULL;
}

circularSinglyLinkedList::~circularSinglyLinkedList()
{
	deleteList();
}


bool circularSinglyLinkedList::addNode(string s)
{
	node * newNode = new node(s, NULL);

	// Liste bos ise
	if (head == NULL)
	{
		head = newNode;
		newNode -> next = head;

		return true;
	}


	node * ptr = head;

	// Listenin ortasina eleman eklenecek ise
	while (ptr -> next != head)
	{
		if (newNode -> info < ptr -> next -> info && ptr -> info < newNode -> info)
		{
			newNode -> next = ptr -> next;
			ptr -> next = newNode;

			return true;
		}
		ptr = ptr -> next;
	}

	
	if (ptr -> info < newNode -> info) // Listenin sonuna eleman eklenecek ise
	{
		ptr -> next = newNode;
		newNode -> next = head;

		return true;
	}	
	else if (newNode -> info < head -> info) // listenin basina eleman eklenecek ise
	{
		newNode -> next = head;
		ptr -> next = newNode;
		head = newNode;

		return true;
	}

	delete newNode;
	return false;
}

bool circularSinglyLinkedList::deleteNode (string s)
{
	// Liste bos ise
	if (head == NULL)
		return false;

	node * ptr = head;
	node * delNode = NULL;

	// Listenin arasindaki veya sonundaki bir eleman silinecek ise
	while (ptr -> next != head)
	{
		if (ptr -> next -> info == s)
		{
			delNode = ptr -> next;
			ptr -> next = ptr -> next -> next;

			delete delNode;
			return true;
		}
		ptr = ptr -> next;
	}

	// Listenin basindaki bir eleman ise
	if (head -> info == s)
	{
		if (head == head -> next)
		{
			// Eger sadece bir dugum varsa
			delNode = head;
			head = NULL;
		}
		else
		{
			// Birden fazla dugum varsa
			delNode = head;
			head = head -> next;
			ptr -> next = head;
		}

		delete delNode;
		return true;
	}

	return false;
}

bool circularSinglyLinkedList::searchList (string s)
{
	// Liste bos ise
	if (head == NULL)
		return false;

	node * ptr = head;

	// Aranan eleman listenin basinda vaya arasinda ise
	while (ptr -> next != head)
	{
		if (ptr -> info == s)
			return true;

		ptr = ptr -> next;
	}

	// Aranan eleman listenin sonunda ise / ya da listede tek eleman var ise
	if (ptr -> info == s)
		return true;

	return false;
}

void circularSinglyLinkedList::printList()
{
	if (head == NULL)
	{
		cout << "Liste Bos" << endl;
	}
	else
	{
		node * ptr = head;
		int k = 0;

		cout << k << ". eleman :" << ptr -> info << endl; // ilk eleman icin
		while (ptr -> next != head)
		{
			ptr = ptr -> next;
			k++;
			cout << k << ". eleman :" << ptr -> info << endl;
		}
	}
}

void circularSinglyLinkedList::deleteList()
{
	node * delList = head;
	node * temp = head;

	if (head == NULL)
	{
		cout << "Liste Yok" << endl;
	}	
	else
	{
		while (temp -> next != head)
		{
			temp = temp -> next;
			delete delList;
			delList = temp;
		}
		delete delList;  // Liste tek elemanli veya listenin sonuncu elemani ise 
		cout << "Liste Silindi" << endl;
		head = NULL;
	}
}
