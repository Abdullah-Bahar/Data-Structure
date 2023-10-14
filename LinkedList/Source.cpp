#include <iostream>
#include <string>
#include "CircularDoublyLinkedList.h"



using namespace std;

/*
* 4 class yazýlacak
- her zaman artan duzende siralanan ve bilgi degerlerinin tekrarina izin verilmeyen (4 cesit bagli liste ) bagli listeler
- her sýnýfta bulunan node icin			=>	string, node isaretcisi (bir veya iki), parametreli ve parametresiz (varsayilan) constructor
- 4 adet bagli listenin her biri icin	=>	.h ve .cpp dosyasi
*/

int main()
{
	string a = "V";
	string b = "K";
	string c = "a";
	string d = "A";
	bool s1 = NULL;
	bool s2 = NULL;
	bool s3 = NULL;
	bool s4 = NULL;


	CircularDoublyLinkedList Liste2;
	Liste2.addNode(a);
	Liste2.addNode(b);
	Liste2.addNode(c);
	Liste2.addNode(d);

	Liste2.printList();

	Liste2.deleteNode("a"); 
	s3 = Liste2.addNode("Z"); 
	s4 = Liste2.addNode("Z");

	cout << s3 << endl; 
	cout << s4 << endl; 

	Liste2.printList();
	
	s1 = Liste2.searchList("V");
	s2 = Liste2.searchList("a");
	cout << s1 << endl; 
	cout << s2 << endl; 

	Liste2.deleteList();
	Liste2.deleteList();

	Liste2.addNode("9");
	Liste2.addNode("\\");
	Liste2.addNode("A");


	Liste2.printList();
	

	system("pause");
	return 0;
}