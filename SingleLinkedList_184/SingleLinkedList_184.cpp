#include <iostream>
using namespace std;

struct Node {
	int NoMhs;
	string name;
	Node* next;
};

Node* START = NULL;

void addNode() {
	int nim;
	string nama;
	Node* nodeBaru = new Node();
	cout << "Masukkan NIM : ";
	cin >> nim;
	cout << "Masukan Nama : ";
	cin >> nama;
	nodeBaru->NoMhs = nim;
	nodeBaru->name = nama;

	if (START == NULL || nim <= START->NoMhs) {
		if (START != NULL && nim == START->NoMhs) 
		{
			cout << " NIM suda ada " << endl;
			return;
		}

		nodeBaru->next = START;
		START = nodeBaru;
		return;
	}

	Node* previous = START;
	Node* current = START;

	while ((current != NULL) && (nim >= current->NoMhs)) 
	{
		if (nim == current->NoMhs) 
		{
			cout << " NIM sudah ada " << endl;
			return;
		}
		previous = current;
		current = current->next;
	}

	nodeBaru->next = current;
	previous->next = nodeBaru;
}

bool searchNode(int nim, Node* current, Node* previous) {
	previous = START;
	current = START;
	while (current != NULL && nim > current->NoMhs)
	{
		previous = current;
		current = current->next;
	}

	if (current == NULL)
	{
		return false;
	}
	else if (current->NoMhs == nim)
	{
		return true;
	}
	else
	{
		return false;
	}
}