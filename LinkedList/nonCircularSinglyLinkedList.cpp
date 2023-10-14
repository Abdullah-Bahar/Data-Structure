#include <iostream>
#include "nonCircularSinglyLinkedList.h"

using namespace std;

/****************
Definition Functions of Struct Node 
*****************/
node::node() 
{}

node::node(const string &kelime, node * baglanti)
{
	info = kelime;
	next = baglanti;
}


/****************
Definition Functions of nonCircularSinglyLinkedList NoClassde 
*****************/
nonCircularSinglyLinkedList::nonCircularSinglyLinkedList()
{
	head = NULL;
}

nonCircularSinglyLinkedList::~nonCircularSinglyLinkedList()
{
	deleteList();
}

bool nonCircularSinglyLinkedList::addNode (string s)
{
	node * newNode = new node(s, NULL);
	// newNode -> info = s (asagidaki yapmis oldugumuz karsilastirmalarda birbirlerinin yerine kullanilabilir)

	// Liste 'NULL' ise ya da liistenin basina eklenecek ise asagidaki if blogunda olay gerceklesir
	if (head == NULL || newNode -> info < head -> info)
	{
		newNode -> next = head;
		head = newNode;

		return true;
	}

	// Liste'ni ortasina ya da listenin sonuna eklenecek ise asagidaki if blogunda olay gerceklesir
	node * ptr = head; 
	while (ptr != NULL && newNode -> info != ptr -> info) 
	{
		if (ptr -> info < newNode -> info)
		{
			if (ptr -> next == NULL || newNode -> info < ptr -> next -> info)
			{
				newNode -> next = ptr -> next;
				ptr -> next = newNode;

				return true;
			}
		}
		ptr = ptr -> next;
	}

	delete newNode;
	return false; 
}

bool nonCircularSinglyLinkedList::deleteNode (string s)
{
	if (head == NULL)
	{
		cout << "olmayan bir listeden eleman silinemez ki..." << endl;
		return false;
	}

	// Ilk eleman silinecek ise
	if (head -> info == s)
	{
		node * temp = head;
		head = temp -> next;

		delete temp;	
		return true;
	}

	node * temp = head;
	while (temp -> next != NULL && temp -> next -> info != s) 
		temp = temp -> next;
	/*	Donguden ciktiginda 2 ihtimal var :  
	1) Silinecek elemani bulmustur	-> temp = Silinecek elemanin adresi olur
	2) Silinecek eleman listede yok -> temp = NULLL olur
	*/

	if (temp -> next != NULL)
	{
		node * DelNode = temp -> next;
		temp -> next = temp -> next -> next;
		// temp -> next = DelNode -> next;

		delete DelNode;
		return true;
	}

	return false;
}

bool nonCircularSinglyLinkedList::searchList(string s)
{
	node * search = head;

	while (search != NULL)
	{
		if (search -> info == s)
			return true;

		search = search -> next;
	}
	return false;
}

void nonCircularSinglyLinkedList::printList()
{
	node * yazdir = head;

	if (yazdir == NULL)
	{
		cout << "Liste Bos" << endl;
	}
	else
	{
		while (yazdir != NULL)
		{
			cout << yazdir -> info << endl; 
			yazdir = yazdir -> next;
		}
	}
}

void nonCircularSinglyLinkedList::deleteList()
{
	node * DelList = head;

	if (head == NULL)
	{
		cout << "Liste Yok" << endl;
	}
	else
	{
		while (head != NULL)
		{
			head = head -> next;
			delete DelList;
			DelList = head;
		}
		cout << "Liste Silindi" << endl;
	}

	head = NULL;
}

