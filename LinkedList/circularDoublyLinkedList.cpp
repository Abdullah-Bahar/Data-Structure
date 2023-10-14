#include <iostream>
#include <string>
#include "CircularDoublyLinkedList.h"

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

CircularDoublyLinkedList::CircularDoublyLinkedList()
{
	head = NULL;
}

CircularDoublyLinkedList::~CircularDoublyLinkedList()
{
	void deleteList();
}


bool CircularDoublyLinkedList::addNode(string s)
{
	if (searchList(s)) // eklenecek eleman varsa
		return false;

	node * newNode = new node(s, NULL, NULL);
	if (head == NULL) // Liste bos ise 
	{
		head = newNode;
		newNode -> next = newNode;
		newNode -> prev = newNode;

		return true;
	}

	node * ptr = head;
	while (ptr -> next != head) // Listenin oratasina eleman eklenecek ise
	{
		if (newNode -> info < ptr -> next -> info && ptr -> info < newNode -> info)
		{
			newNode -> next = ptr -> next;
			ptr -> next -> prev = newNode;
			ptr -> next = newNode;
			newNode -> prev = ptr;

			return true;
		}
		ptr = ptr -> next;
	}

	// listenin basi veya sonuna eklenecek ise
	ptr -> next = newNode;
	newNode -> next = head;
	head -> prev = newNode;
	newNode -> prev = ptr;

	if (newNode -> info < head -> info) // basina eklecek ise head'i günceller
		head = newNode;

	return true;
}

bool CircularDoublyLinkedList::deleteNode(string s)
{
	if (head == NULL)
		return false;

	node * ptr = head;
	node * delNode = NULL;

	while (ptr -> next != head)
	{
		if (ptr -> next -> info == s)
		{
			delNode = ptr -> next;
			ptr -> next = ptr -> next -> next;
			ptr -> next -> prev = ptr;

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
			head -> prev = ptr;
			ptr -> next = head;
		}

		delete delNode;
		return true;
	}

	return false;
}

bool CircularDoublyLinkedList::searchList(string s)
{
	if (head == NULL)
		return false;

	node * ptr = head;
	while (ptr -> next != head)
	{
		if (ptr -> info == s)
			return true;

		ptr = ptr -> next;
	}
	if (ptr -> info == s) // son elemani kontrol etmeden donguden ciktigi icin son eleman kontrolu yapýlýyor
		return true;


	return false;
}

void CircularDoublyLinkedList::printList()
{
	if (head == NULL)
	{
		cout << "List is Empty" << endl;
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

void CircularDoublyLinkedList::deleteList()
{
	node * delList = head;
	node * ptr = head;

	if (head == NULL)
	{
		cout << "Liste Yok" << endl;
	}	
	else
	{
		while (ptr -> next != head)
		{
			ptr = ptr -> next;
			delete delList;
			delList = ptr;
		}
		delete delList;  // Liste tek elemanli veya listenin sonuncu elemani ise 
		cout << "Liste Silindi" << endl;
		head = NULL;
	}
}